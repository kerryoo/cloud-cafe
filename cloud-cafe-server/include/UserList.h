//
// Created by Kerr Yoo on 5/13/21.
//

#ifndef CLOUDCAFESERVER_USERLIST_H
#define CLOUDCAFESERVER_USERLIST_H

#include <list>
#include "User.h"
class UserList {
public:
    //adds a user to the user list and returns the message to broadcast to all clients
    std::string addUser(std::string const& playerID);

    //removes a user from the user list and returns the message to broadcast to all clients
    std::string removeUser(std::string const& playerID);

    //moves a user in the user list and returns the message to broadcast to all clients
    std::string moveUser(std::string const& playerID, std::string const& input);

    //adds a message to the user's chatlog and returns the mssage to broadcast to all clients
    std::string chatUser(std::string const& playerID, std::string const& sentence);

    friend std::ostream& operator<<(std::ostream& os, const UserList& userList);
private:
    std::list<User> users;

};



#endif //CLOUDCAFESERVER_USERLIST_H
