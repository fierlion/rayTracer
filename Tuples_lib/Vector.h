//
// Created by Allan, Ray on 12/26/21.
//

#ifndef TESTING_TEST_VECTOR_H
#define TESTING_TEST_VECTOR_H

#include "Tuple.h"

class Vector : public Tuple {
public:
    Vector(){
        w = VECTOR_FLOAT;
    };
    Vector(float inX, float inY, float inZ) {
        x = inX;
        y = inY;
        z = inZ;
        w = VECTOR_FLOAT;
    }

    //Point operator+(const Point& rhs);
    Vector operator+(const Vector& rhs);
    Vector operator-(const Vector& rhs);
    Vector operator-();
    Vector operator*(const float scalar);
    Vector operator/(const float scalar);

    float magnitude();
    Vector normalize();
    float dotProduct(const Vector& rhs);
    Vector crossProduct(const Vector& rhs);
    Vector reflect(Vector& normalVector);
};

#endif //TESTING_TEST_VECTOR_H
