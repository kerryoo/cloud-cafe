#include <iostream>
#include <sstream>
#include "include/UserList.h"

UserList users;
void init();
void handleRequest(std::string request);
void onUserEnter(std::string const& playerID);
void onUserExit(std::string const& playerID);
void onUserMove(std::string const& playerID, std::string const& input);
void init() {

}

void handleRequest(std::string request) {
    std::istringstream stream(request);
    std::string token;

    stream >> token;
    std::string playerID;
    stream >> playerID;
    if (token == "login") {
        onUserEnter(playerID);
    } else if (token == "logout") {
        onUserExit(playerID);
    } else if (token == "move") {
        std::string input;
        stream >> input;
        onUserMove(playerID, input);
    }
}

void onUserEnter(std::string const& playerID) {
    users.addUser(playerID);
}

void onUserExit(std::string const& playerID) {
    users.removeUser(playerID);
}

void onUserMove(std::string const& playerID, std::string const& input) {

}

int main() {
    User user = User("kerr");
    for (int i = 0; i < 6; i++) {
        user.move("d");
    }
    std::cout << user << std::endl;
    user.move("w");
    return 0;
}
