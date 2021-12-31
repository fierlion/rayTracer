//
// Created by Allan, Ray on 12/24/21.
//

#include "Tuple.h"

#include <cmath>
#include <exception>
#include <iostream>


class IllegalArithmeticException: public std::exception {
    virtual const char* what() const throw() {
        return "Illegal Arithmetic Exception";
    }
} illArithEx;

class ConversionException: public std::exception {
    virtual const char* what() const throw() {
        return "Conversion to target is illegal";
    }
} convEx;

bool Tuple::operator==(const Tuple& rhs) const {
    return (std::abs(x - rhs.x) < EPSILON &&
            std::abs(y - rhs.y) < EPSILON &&
            std::abs(z - rhs.z) < EPSILON &&
            std::abs(w - rhs.w) < EPSILON);
}

bool Tuple::operator!=(const Tuple& rhs) const {
    return !(this->operator==(rhs));
}

Tuple Tuple::operator+(const Tuple& rhs) const {
    if (std::abs(w + rhs.w) > (2.0 - EPSILON)) {
        // Point + Point is illegal
        throw illArithEx;
    } else if (std::abs(w + rhs.w) > (1.0 - EPSILON)) {
        // Point + Vector is a Point
        return Tuple((x + rhs.x), (y + rhs.y), (z + rhs.z), POINT_FLOAT);
    } else {
        // Vector + Vector is a Vector
        return Tuple((x + rhs.x), (y + rhs.y), (z + rhs.z), VECTOR_FLOAT);
    }
}

Tuple Tuple::operator-(const Tuple& rhs) const {
   if (std::abs(w - rhs.w) < (0.0 - EPSILON)) {
       // Vector - Point is illegal
       throw illArithEx;
   } else if (std::abs(w - rhs.w) > (1.0 - EPSILON)) {
       return Tuple((x - rhs.x), (y - rhs.y), (z - rhs.z), POINT_FLOAT);
   } else {
       return Tuple((x - rhs.x), (y - rhs.y), (z - rhs.z), VECTOR_FLOAT);
   }
}

Tuple Tuple::operator-() const {
    return Tuple(-x, -y, -z, w);
}

Tuple Tuple::operator*(const float scalar) const {
    return Tuple((x*scalar), (y*scalar), (z*scalar), w);
}

Tuple Tuple::operator/(const float scalar) const {
    // throw exception if scalar is 0
    return Tuple((x/scalar), (y/scalar), (z/scalar), w);
}

bool Tuple::isVector() const {return std::abs(w - VECTOR_FLOAT) < EPSILON;}
bool Tuple::isPoint() const {return std::abs(w - POINT_FLOAT) < EPSILON;}

std::string Tuple::toString() const {
    return std::string("x: " + std::to_string(x) + " " +
                       "y: " + std::to_string(y) + " " +
                       "z: " + std::to_string(z) + " " +
                       "w: " + std::to_string(w));
}