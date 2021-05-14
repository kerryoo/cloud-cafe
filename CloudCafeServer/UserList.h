//
// Created by Kerr Yoo on 5/13/21.
//

#ifndef CLOUDCAFESERVER_USERLIST_H
#define CLOUDCAFESERVER_USERLIST_H

#include <list>
#include "User.h"
class UserList {
public:
    void addUser();
    void removeUser();
private:
    std::list<User> users;

};


#endif //CLOUDCAFESERVER_USERLIST_H
