//
// Created by Allan, Ray on 12/24/21.
//

#ifndef TESTING_TEST_TUPLE_H
#define TESTING_TEST_TUPLE_H

#define VECTOR_FLOAT 0.0
#define POINT_FLOAT 1.0
#define COLOR_FLOAT -1.0
#define EPSILON 0.0001

#include <iostream>

class Tuple {
protected:
    float x;
    float y;
    float z;
    float w;

public:
    Tuple(){
        x = 0.0;
        y = 0.0;
        z = 0.0;
        w = 0.0;
    };
    Tuple(float inX, float inY, float inZ, float inW) {
        x = inX;
        y = inY;
        z = inZ;
        w = inW;
    }

    float getX() const {return x;}
    float getY() const {return y;}
    float getZ() const {return z;}
    float getW() const {return w;}

    bool operator==(const Tuple& rhs) const;
    bool operator!=(const Tuple& rhs) const;
    Tuple operator+(const Tuple& rhs) const;
    Tuple operator-(const Tuple& rhs) const;
    Tuple operator-() const;

    Tuple operator*(const float scalar) const;
    Tuple operator/(const float scalar) const;

    bool isPoint() const;
    bool isVector() const;
    std::string toString() const;
};

#endif //TESTING_TEST_TUPLE_H