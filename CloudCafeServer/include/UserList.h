//
// Created by Kerr Yoo on 5/13/21.
//

#ifndef CLOUDCAFESERVER_USERLIST_H
#define CLOUDCAFESERVER_USERLIST_H

#include <list>
#include "User.h"
class UserList {
public:
    void addUser(std::string const& playerID);
    void addUser(User const& user);
    void removeUser(std::string const& playerID);
    void removeUser(User const& user);
    void moveUser(std::string const& playerID, std::string const& input);

    friend std::ostream& operator<<(std::ostream& os, const UserList& userList);
private:
    std::list<User> users;

};



#endif //CLOUDCAFESERVER_USERLIST_H
