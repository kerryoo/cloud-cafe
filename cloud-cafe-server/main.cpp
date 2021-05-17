#include <iostream>
#include <sstream>
#include "UserList.h"
#include "apis/modern-cpp-kafka/include/kafka/KafkaConsumer.h"
#include "apis/modern-cpp-kafka/include/kafka/KafkaProducer.h"
#include "ServerConfigs.h"

UserList users;

void mainLoop();
std::string handleRequest(std::string request);
std::string onUserEnter(std::string const& playerID);
std::string onUserExit(std::string const& playerID);
std::string onUserMove(std::string const& playerID, std::string const& input);
std::string onUserChat(std::string const& playerID, std::string const& sentence);

std::string handleRequest(std::string request) {
    std::istringstream stream(request);
    std::string token;
    stream >> token;
    std::string playerID;
    stream >> playerID;
    if (token == "login") {
        return onUserEnter(playerID);
    } else if (token == "logout") {
        return onUserExit(playerID);
    } else if (token == "move") {
        std::string input;
        stream >> input;
        return onUserMove(playerID, input);
    } else if (token == "chat") {
        std::string sentence;
        stream >> sentence;
        return onUserChat(playerID, sentence);
    } else {
            return "err";
    }
}

std::string onUserEnter(std::string const& playerID) {
   return users.addUser(playerID);
}

std::string onUserExit(std::string const& playerID) {
    return users.removeUser(playerID);
}

std::string onUserMove(std::string const& playerID, std::string const& input) {
    return users.moveUser(playerID, input);
}

std::string onUserChat(std::string const& playerID, std::string const& sentence) {
    return users.chatUser(playerID, sentence);
}

void mainLoop() {
    kafka::Properties broadcasterProps ({
        {"bootstrap.servers", ServerConfigs::BOOTSTRAP_SERVER_IP},
        {"enable.idempotence", "true"},
    });

    kafka::KafkaSyncProducer broadcaster(broadcasterProps);

    kafka::Properties listenerProps ({{"bootstrap.servers", ServerConfigs::BOOTSTRAP_SERVER_IP}});
    kafka::KafkaAutoCommitConsumer listener(listenerProps);
    listener.subscribe({ServerConfigs::CLIENT_INPUTS_TOPIC});
    std::cout << "% Reading messages from topic: " << ServerConfigs::CLIENT_INPUTS_TOPIC << std::endl;
    while (true) {
        auto records = listener.poll(std::chrono::milliseconds(100));
        for (const auto& record: records) {
            // In this example, quit on empty message
            if (record.value().size() == 0) return;
            if (!record.error()) {
                std::cout << "% Got a new message..." << std::endl;
                std::cout << "    Topic    : " << record.topic() << std::endl;
                std::cout << "    Partition: " << record.partition() << std::endl;
                std::cout << "    Offset   : " << record.offset() << std::endl;
                std::cout << "    Timestamp: " << record.timestamp().toString() << std::endl;
                std::cout << "    Headers  : " << kafka::toString(record.headers()) << std::endl;
                std::cout << "    Key   [" << record.key().toString() << "]" << std::endl;
                std::cout << "    Value [" << record.value().toString() << "]" << std::endl;

                std::string broadcastMessage = handleRequest(record.toString());
                auto broadcastRecord = kafka::ProducerRecord(ServerConfigs::ALL_CLIENT_STATES_TOPIC,
                                                             kafka::NullKey,
                                                             kafka::Value(broadcastMessage.c_str(), broadcastMessage.size()));

                try {
                    kafka::Producer::RecordMetadata metadata = broadcaster.send(broadcastRecord);
                    std::cout << "% Message delivered: " << metadata.toString() << std::endl;
                } catch (const kafka::KafkaException& e) {
                    std::cerr << "% Message delivery failed: " << e.error().message() << std::endl;
                }
            } else {
                std::cerr << record.toString() << std::endl;
            }
        }
    }
}

int main() {
    std::cout << "% Server started!" << std::endl;
//    mainLoop();
    std::cout << "% Server closed!" << std::endl;

    return 0;
}
