//
// Created by Kerr Yoo on 5/13/21.
//

#include "User.h"
#include "ServerConfigs.h"


User::User(std::string userID, Vector3 startPos, Vector3 startRot) :
userId(std::move(userID)), position(startPos), rotation(startRot) {}

bool User::operator==(const User &rhs) const {
    return userId == rhs.userId;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "User ID: " << user.userId << std::endl;
    os << "Position: " << user.position << std::endl;
    os << "Rotation: " << user.rotation << std::endl;
    return os;
}

void User::move(std::string const& input) {
    if (input == "w") {
        Vector3 forwardVector = getForwardVector();
        position += forwardVector * ServerConfigs::MOVE_SPEED;
    } else if (input == "a") {
        rotation.y -= ServerConfigs::ROTATE_SPEED;
    } else if (input == "s") {
        Vector3 forwardVector = getForwardVector();
        position -= forwardVector * ServerConfigs::MOVE_SPEED;
    } else if (input == "d") {
        rotation.y += ServerConfigs::ROTATE_SPEED;
    }
}

Vector3 User::getForwardVector() {
    float x = -cos(rotation.x * M_PI / 180) * sin(rotation.y * M_PI / 180);
    float y = sin(rotation.x * M_PI / 180);
    float z = -cos(rotation.x * M_PI / 180) * cos(rotation.y * M_PI / 180);

    if (abs(x) < 0.0001) { x = 0; }
    if (abs(y) < 0.0001) { y = 0; }
    if (abs(z) < 0.0001) { z = 0; }
    return Vector3(x, y, z);
}

