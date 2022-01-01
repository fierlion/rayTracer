//
// Created by Allan, Ray on 1/1/22.
//

#ifndef GOOGLE_TESTS_SPHERE_H
#define GOOGLE_TESTS_SPHERE_H

#include "../Ray_lib/Ray.h"

#include <vector>


class Sphere {
protected:
    Point center;
    float radius;
public:
    Sphere() {};
    Sphere(Point centerIn, float radiusIn) {
        this->center = centerIn;
        this->radius = radiusIn;
    };
    std::vector<float> intersect(const Ray& rayIn);
};


#endif //GOOGLE_TESTS_SPHERE_H
