//
// Created by Kerr Yoo on 5/13/21.
//

#include "User.h"

#include <utility>


User::User(std::string userID, Vector3 startPos, Vector3 startRot) :
userId(std::move(userID)), position(startPos), rotation(startRot) {

}