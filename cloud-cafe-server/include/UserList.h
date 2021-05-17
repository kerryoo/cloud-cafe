//
// Created by Kerr Yoo on 5/13/21.
//

#ifndef CLOUDCAFESERVER_USERLIST_H
#define CLOUDCAFESERVER_USERLIST_H

#include <list>
#include "User.h"
class UserList {
public:
    std::string addUser(std::string const& playerID);
    std::string removeUser(std::string const& playerID);
    std::string moveUser(std::string const& playerID, std::string const& input);
    std::string chatUser(std::string const& playerID, std::string const& sentence);

    friend std::ostream& operator<<(std::ostream& os, const UserList& userList);
private:
    std::list<User> users;

};



#endif //CLOUDCAFESERVER_USERLIST_H
