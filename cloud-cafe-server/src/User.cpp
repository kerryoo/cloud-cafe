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
        Vector3 forwardVector = rotation.getForwardFromRotation();
        position += forwardVector * ServerConfigs::MOVE_SPEED;
    } else if (input == "a") {
        rotation.y -= ServerConfigs::ROTATE_SPEED;
    } else if (input == "s") {
        Vector3 forwardVector = rotation.getForwardFromRotation();
        position -= forwardVector * ServerConfigs::MOVE_SPEED;
    } else if (input == "d") {
        rotation.y += ServerConfigs::ROTATE_SPEED;
    }
}

Vector3 User::getPos() const {
    return position;
}

Vector3 User::getRot() const {
    return rotation;
}

void User::chat(const std::string &sentence) {
    //add to a chat log somewhere
}

std::string User::getId() const {
    return userId;
}

