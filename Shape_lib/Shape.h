//
// Created by Allan, Ray on 1/1/22.
//

#ifndef GOOGLE_TESTS_SHAPE3D_H
#define GOOGLE_TESTS_SHAPE3D_H

#include "../Ray_lib/Ray.h"

#include <vector>


class Shape {
protected:
    Point center;
public:
    Shape() {};
    Shape(Point centerIn) {
        this->center = centerIn;
    }
    Point getCenter() {return this->center;}
    // base shape has no intersections
    virtual std::vector<float> intersect(Ray rayIn);
};


#endif //GOOGLE_TESTS_SHAPE3D_H
