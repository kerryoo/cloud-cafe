//
// Created by Kerr Yoo on 5/13/21.
//

#include "UserList.h"

void UserList::addUser(const std::string &playerID) {
    std::list<User>::iterator it;
    User user(playerID);
    it = std::find(users.begin(), users.end(), user);
    if (it == users.end()) {
        users.emplace_back(user);
    }
}
void UserList::addUser(const User &user) {
    std::list<User>::iterator it;
    it = std::find(users.begin(), users.end(), user);
    if (it == users.end()) {
        users.emplace_back(user);
    }
}

void UserList::removeUser(const std::string &playerID) {
    User user(playerID);
    users.remove(user);
}

void UserList::removeUser(const User &user) {
    users.remove(user);
}

std::ostream& operator<<(std::ostream& os, const UserList& userList) {
    for (const auto & user : userList.users) {
        os << user << std::endl;
    }
    return os;
}
