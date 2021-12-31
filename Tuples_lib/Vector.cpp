//
// Created by Allan, Ray on 12/26/21.
//

//#include "Point.h"
#include "Vector.h"

#include <math.h>


// Adding a Point to a Vector to returns a Point
//Point Vector::operator+(const Point& rhs) {
//    return Point((x + rhs.getX()), (y + rhs.getY()), (z + rhs.getZ()));
//}

// Adding A Vector to a Vector returns a Vector
Vector Vector::operator+(const Vector& rhs) {
    return Vector((x + rhs.getX()), (y + rhs.getY()), (z + rhs.getZ()));
}

// Subtracting 2 Vectors returns a Vector
Vector Vector::operator-(const Vector& rhs) {
    return Vector((x - rhs.getX()), (y - rhs.getY()), (z - rhs.getZ()));
}

Vector Vector::operator-() {
    return Vector(-x, -y, -z);
}

Vector Vector::operator*(const float scalar) {
    return Vector((x * scalar), (y * scalar), (z * scalar));
}

Vector Vector::operator/(const float scalar) {
    return Vector((x / scalar), (y / scalar), (z / scalar));
}

float Vector::magnitude() {
    return sqrt((x*x)+(y*y)+(z*z));
}

Vector Vector::normalize() {
    float thisMagnitude = magnitude();
    return Vector((x/thisMagnitude), (y/thisMagnitude), (z/thisMagnitude));
}

float Vector::dotProduct(const Vector& rhs) {
    return ((x * rhs.getX())+(y * rhs.getY()) + (z * rhs.getZ()));
}

Vector Vector::crossProduct(const Vector& rhs) {
    return Vector((y * rhs.getZ()) - (z * rhs.getY()),
                  (z * rhs.getX()) - (x * rhs.getZ()),
                  (x * rhs.getY()) - (y * rhs.getX()));
}
