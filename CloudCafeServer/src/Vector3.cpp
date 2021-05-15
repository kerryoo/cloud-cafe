//
// Created by Kerr Yoo on 5/13/21.
//

#include "Vector3.h"

float &Vector3::operator[](int index) {
    if (index == 0) {
        return x;
    } else if (index == 1) {
        return y;
    } else if (index == 2) {
        return z;
    } else {
        throw std::out_of_range("only 3 pos");
    }
}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3 Vector3::operator-() const {
    return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator+(const Vector3 &rhs) const {
    return Vector3(x+rhs.x, y+rhs.y, z+rhs.z);
}

Vector3 Vector3::operator-(const Vector3 &rhs) const {
    return Vector3(x-rhs.x, y-rhs.y, z-rhs.z);
}

float Vector3::operator*(const Vector3 &rhs) const {
    return (x*rhs.x + y*rhs.y + z*rhs.z);
}

Vector3 Vector3::operator*(float rhs) const {
    return Vector3(x*rhs, y*rhs, z*rhs);
}

Vector3 Vector3::cross(const Vector3 &rhs) const {
    return Vector3(y*rhs.z - z*rhs.y, z*rhs.x - x*rhs.z, x*rhs.y - y*rhs.x);
}

float Vector3::norm() const {
    return sqrt(x*x + y*y + z*z);
}

float Vector3::normSquared() {
    return (norm()*norm());
}

std::ostream &operator<<(std::ostream &os, const Vector3 &rayVector) {
    os << "<" << rayVector.x << ", " << rayVector.y << ", " << rayVector.z << ">";
    return os;
}

bool Vector3::operator==(const Vector3 &rhs) const {
    return x==rhs.x && y==rhs.y && z==rhs.z;
}

Vector3 Vector3::zeroVector() {
    return Vector3(0, 0, 0);
}

bool Vector3::parallel(const Vector3 &rhs) const {
    float theta = acos((*this*rhs)/(norm()*rhs.norm()));
    std::cout << theta << std::endl;
    return (theta >= -0.1 && theta <= 0.1) || (theta >= M_PI - 0.1 && theta <= M_PI + 0.1);
}

Vector3 Vector3::operator/(float rhs) const {
    return *this * (1/rhs);
}

Vector3 Vector3::normalize() const {
    return *this/norm();
}

float Vector3::cosTheta(const Vector3 &rhs) const {
    float num = *this * rhs;
    float den = norm() * rhs.norm();
    return num/den;
}

void Vector3::clampToZeroAndOne() {
    if (x > 1) {
        x = 1;
    }
    if (x < 0) {
        x = 0;
    }
    if (y > 1) {
        y = 1;
    }
    if (y < 0) {
        y = 0;
    }
    if (z > 1) {
        z = 1;
    }
    if (z < 0) {
        z = 0;
    }
}

Vector3 &Vector3::operator+=(const Vector3 &rhs) {
    x += rhs.x;
    y += rhs.y;
    z += rhs.z;
    return *this;
}

Vector3 &Vector3::operator-=(const Vector3 &rhs) {
    x -= rhs.x;
    y -= rhs.y;
    z -= rhs.z;
    return *this;
}

Vector3 operator* (float x, const Vector3& rhs) {
    return Vector3(x*rhs.x, x*rhs.y, x*rhs.z);
}