//
// Created by Allan, Ray on 12/24/21.
//

#ifndef TESTING_TEST_TUPLE_H
#define TESTING_TEST_TUPLE_H

#define VECTOR_FLOAT 0.0
#define POINT_FLOAT 1.0
#define EPSILON 0.00001

class Tuple {
protected:
    float x;
    float y;
    float z;
    float w;

public:
    Tuple(){};
    Tuple(float inX, float inY, float inZ, float inW) {
        x = inX;
        y = inY;
        z = inZ;
        w = inW;
    }

    int getX() const {return x;}
    int getY() const {return y;}
    int getZ() const {return z;}
    int getW() const {return w;}

    bool isPoint();
    bool isVector();
    bool operator==(const Tuple& rhs);
    Tuple operator+(const Tuple& rhs);
    Tuple operator-(const Tuple& rhs);
    Tuple operator-();
    Tuple operator*(const float scalar);
    Tuple operator/(const float scalar);
};

#endif //TESTING_TEST_TUPLE_H