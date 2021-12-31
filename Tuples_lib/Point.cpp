//
// Created by Allan, Ray on 12/24/21.
//

#include "Point.h"
#include "Vector.h"


// Adding A Vector to a Point returns a Point
Point Point::operator+(const Vector& rhs) {
    return Point((x + rhs.getX()), (y + rhs.getY()), (z + rhs.getZ()));
}

// Subtracting 2 Points returns a Vector
Vector Point::operator-(const Point& rhs) {
    return Vector((x - rhs.getX()), (y - rhs.getY()), (z - rhs.getZ()));
}

// Subtracting a Vector from a Point returns a Vector
Point Point::operator-(const Vector& rhs) {
    return Point((x - rhs.getX()), (y - rhs.getY()), (z - rhs.getZ()));
}

Point Point::operator-() {
    return Point(-x, -y, -z);
}

Point Point::operator*(const float scalar) {
    return Point((x * scalar), (y * scalar), (z * scalar));
}

Point Point::operator/(const float scalar) {
    return Point((x / scalar), (y / scalar), (z / scalar));
}