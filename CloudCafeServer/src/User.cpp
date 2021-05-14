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
        float x = cos(rotation.y * M_PI / 180) * cos(rotation.x * M_PI / 180);
        float y = sin(rotation.y * M_PI / 180) * cos(rotation.x * M_PI / 180);
        float z = sin(rotation.x * M_PI / 180);
        Vector3 forwardVector = Vector3(x, y, z);
        std::cout << forwardVector;
    } else if (input == "a") {
        rotation.y -= ServerConfigs::ROTATE_SPEED;
    } else if (input == "s") {

    } else if (input == "d") {
        rotation.y -= ServerConfigs::ROTATE_SPEED;
    }
}

