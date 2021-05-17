//
// Created by Kerr Yoo on 5/14/21.
//

#ifndef CLOUDCAFESERVER_SERVERCONFIGS_H
#define CLOUDCAFESERVER_SERVERCONFIGS_H

class ServerConfigs {
public:
    constexpr static const float MOVE_SPEED = 1;
    constexpr static const float ROTATE_SPEED = 30;
    inline static const std::string BOOTSTRAP_SERVER_IP = "52.3.250.51:9092";
    inline static const std::string CLIENT_INPUTS_TOPIC = "ClientInputsTopic";
    inline static const std::string ALL_CLIENT_STATES_TOPIC = "AllClientStatesTopic";
};

#endif //CLOUDCAFESERVER_SERVERCONFIGS_H
