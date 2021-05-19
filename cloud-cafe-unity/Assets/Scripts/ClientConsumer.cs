using UnityEngine;
using Confluent.Kafka;
using System;
using System.Net;
using System.Threading;

public class ClientConsumer : MonoBehaviour
{
    [SerializeField] AllClientsManager clientsManager;
    private IProducer<Null, string> serverMessenger;
    private IConsumer<Ignore, string> serverListener;
    // Start is called before the first frame update
    public void startKafka(string username)
    {
        string KafkaServerIP = Environment.GetEnvironmentVariable("BOOTSTRAP_SERVER_IP");

        var producerConfig = new ProducerConfig
        {
            BootstrapServers = KafkaServerIP,
            ClientId = Dns.GetHostName(),
        };

        serverMessenger = new ProducerBuilder<Null, string>(producerConfig).Build();


        var Config = new ConsumerConfig
        {
            BootstrapServers = KafkaServerIP,
            GroupId = username,
            AutoOffsetReset = AutoOffsetReset.Earliest,
        };
        serverListener = new ConsumerBuilder<Ignore, string>(Config).Build();
        serverListener.Subscribe(ServerConfigs.AllClientStatesTopic);
    }

    public void sendMessageToServer(string message)
    {
        try
        {
            serverMessenger.ProduceAsync(ServerConfigs.ClientInputsTopic,
                new Message<Null, string> { Value = message });
        }
        catch (ProduceException<Null, string> e)
        {
            Console.WriteLine($"Delivery failed: {e.Error.Reason}");
        }
    }

    public void consumeLoop()
    {
        while (true)
        {
            var consumeResult = serverListener.Consume();

            clientsManager.onReceiveMessage(consumeResult.Message.Value);
            Thread.Sleep(100);
        }
    }
}
