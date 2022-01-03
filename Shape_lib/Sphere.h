//
// Created by Allan, Ray on 1/1/22.
//

#ifndef GOOGLE_TESTS_SPHERE_H
#define GOOGLE_TESTS_SPHERE_H

#include "../Shape_lib/Shape.h"
#include "../Ray_lib/Ray.h"

#include <vector>


class Sphere : public Shape {
protected:
    float radius;
public:
    Sphere() : Shape() {};
    bool equals(Shape& rhs) const;
    Sphere(Point centerIn, float radiusIn) : Shape(centerIn), radius(radiusIn) {
        radius = radiusIn;
    };
    float getRadius() {return this->radius;}
    std::vector<float> getRayIntersects(Ray& rayIn);
};


#endif //GOOGLE_TESTS_SPHERE_H
