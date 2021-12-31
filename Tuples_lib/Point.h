//
// Created by Allan, Ray on 12/24/21.
//

#ifndef TESTING_TEST_POINT_H
#define TESTING_TEST_POINT_H

#include "Tuple.h"
#include "Vector.h"


class Point : public Tuple {
public:
    Point(){
        w = POINT_FLOAT;
    };
    Point(float inX, float inY, float inZ) {
        x = inX;
        y = inY;
        z = inZ;
        w = POINT_FLOAT;
    }

    Point operator+(const Vector& rhs);
    Vector operator-(const Point& rhs);
    Point operator-(const Vector& rhs);
    Point operator-();
    Point operator*(const float scalar);
    Point operator/(const float scalar);
};

#endif //TESTING_TEST_POINT_H
