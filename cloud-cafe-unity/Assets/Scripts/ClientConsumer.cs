using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using Confluent.Kafka;

public class ClientConsumer : MonoBehaviour
{
    // Start is called before the first frame update
    void Start()
    {
        var Config = new ConsumerConfig
        {
            BootstrapServers = ServerConfigs.KafkaServerIP,
            GroupId = "clientGroup",
            AutoOffsetReset = AutoOffsetReset.Earliest,
        };
        var consumer = new ConsumerBuilder<Ignore, string>(Config).Build();
        consumer.Subscribe("demo");
        var consumeResult = consumer.Consume();
        string value = consumeResult.Message.Value;
    }
}
