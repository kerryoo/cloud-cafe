//
// Created by Kerr Yoo on 5/13/21.
//

#ifndef CLOUDCAFESERVER_USER_H
#define CLOUDCAFESERVER_USER_H

#include <string>
#include "Vector3.h"

class User {
public:
    explicit User(std::string userID, Vector3 startPos = Vector3(), Vector3 rotation = Vector3());
    ~User() = default;
    User(const User&) = default;
    User& operator= (const User&) = default;
    bool operator==(const User& rhs) const;
    friend std::ostream& operator<<(std::ostream& os, const User& user);
    void move(std::string const& input);
    Vector3 getForwardVector();
private:
    std::string userId;
    Vector3 position;
    Vector3 rotation;
};



#endif //CLOUDCAFESERVER_USER_H
