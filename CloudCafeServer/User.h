//
// Created by Kerr Yoo on 5/13/21.
//

#ifndef CLOUDCAFESERVER_USER_H
#define CLOUDCAFESERVER_USER_H

#include <string>
#include "Vector3.h"

class User {
public:
    User(std::string userID, Vector3 startPos, Vector3 rotation);
    ~User() = default;
    User(const User&) = default;
    User& operator= (const User&) = default;

private:
    std::string userId;
    Vector3 position;
    Vector3 rotation;
};


#endif //CLOUDCAFESERVER_USER_H
