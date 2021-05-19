//
// Created by Kerr Yoo on 5/13/21.
//

#include "UserList.h"

std::string UserList::addUser(const std::string &playerID) {
    User user(playerID);
    std::string currUsers;

    for (const auto& client : userList.users) {
        currUsers += " " + client.getID();
    }

    auto it = std::find(users.begin(), users.end(), user);
    if (it == users.end()) {
        users.emplace_back(user);
    }
    return "login " + playerID + currUsers;
}

std::string UserList::removeUser(const std::string &playerID) {
    User user(playerID);
    users.remove(user);
    return "logout " + playerID;
}

std::ostream& operator<<(std::ostream& os, const UserList& userList) {
    for (const auto& user : userList.users) {
        os << user << std::endl;
    }
    return os;
}

std::string UserList::moveUser(const std::string &playerID, const std::string &input) {
    User user(playerID);
    auto it = std::find(users.begin(), users.end(), user);
    it->move(input);
    return "move " + playerID + " " + it->getPos().toString() + " " + it->getRot().toString();
}

std::string UserList::chatUser(const std::string &playerID, const std::string &sentence) {
    User user(playerID);
    auto it = std::find(users.begin(), users.end(), user);
    it->chat(sentence);
    return "chat " + playerID + " " + sentence;
}
