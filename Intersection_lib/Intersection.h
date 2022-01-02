//
// Created by Allan, Ray on 1/1/22.
//

#ifndef GOOGLE_TESTS_INTERSECTION_H
#define GOOGLE_TESTS_INTERSECTION_H

#include "../Shape_lib/Shape.h"


class Intersection {
protected:
    float tValue;
    Shape shape;
public:
    Intersection() {};
    Intersection(float tValueIn, Shape shapeIn) {
        tValue = tValueIn;
        shape = shapeIn;
    };
    float getTValue() {return this->tValue;}
    Shape getShape() {return this->shape;}
};


#endif //GOOGLE_TESTS_INTERSECTION_H
