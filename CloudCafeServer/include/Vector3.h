//
// Created by Kerr Yoo on 5/13/21.
//

#ifndef CLOUDCAFESERVER_VECTOR3_H
#define CLOUDCAFESERVER_VECTOR3_H
#include <iostream>

class Vector3 {
public:
    float x, y, z;
    explicit Vector3(float x = 0, float y = 0, float z = 0);
    float& operator[] (int index);
    Vector3 operator- () const;
    Vector3 operator+ (const Vector3& rhs) const;
    Vector3 operator- (const Vector3& rhs) const;
    float operator* (const Vector3& rhs) const;
    Vector3 operator* (float rhs) const;
    Vector3 operator/ (float rhs) const;
    Vector3& operator+= (const Vector3& rhs);
    Vector3& operator-= (const Vector3& rhs);
    bool operator==(const Vector3& rhs) const;
    bool parallel(const Vector3& rhs) const;
    Vector3 cross(const Vector3& rhs) const;
    Vector3 normalize() const;
    static Vector3 zeroVector();
    float norm() const;
    float normSquared();
    float cosTheta(const Vector3& rhs) const;
    friend std::ostream& operator<<(std::ostream& os, const Vector3& rayVector);
    void clampToZeroAndOne();


};
Vector3 operator* (float x, const Vector3& rhs);


#endif //CLOUDCAFESERVER_VECTOR3_H
