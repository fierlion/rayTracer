//
// Created by Allan, Ray on 1/1/22.
//

#include "Sphere.h"
#include "../Shape_lib/Shape.h"

#include <vector>
#include <numeric>


bool Sphere::equals(Shape& rhs) const {
    Sphere *rhsSphere = dynamic_cast<Sphere*>(&rhs);
    // NULL check dynamic_cast
    if (!rhsSphere) {
        return false;
    }
    return (std::abs(this->radius - rhsSphere->radius) < EPSILON &&
            this->center == rhsSphere->center);
}

std::vector<float> Sphere::getRayIntersects(Ray& rayIn) {
    // apply shape transform to ray
    Matrix inverseTransform = this->getTransform().inverse();
    Ray rayTr = rayIn.transform(inverseTransform);
    std::vector<float> intersects;
    Vector sphereToRay = rayTr.getOrigin() - this->getCenter();
    float directionDot = rayTr.getDirection().dotProduct(rayTr.getDirection());
    float directionSphereDot = 2.0 * (rayTr.getDirection().dotProduct(sphereToRay));
    float sphereToRayDot = (sphereToRay.dotProduct(sphereToRay)) - 1;
    float discriminant = (directionSphereDot * directionSphereDot) - (4.0 * directionDot * sphereToRayDot);
    if (discriminant < 0) {
        return intersects;
    } else {
        float t1 = ((-1 * directionSphereDot) - std::sqrt(discriminant)) / (2.0 * directionDot);
        float t2 = ((-1 * directionSphereDot) + std::sqrt(discriminant)) / (2.0 * directionDot);
        intersects.push_back(t1);
        intersects.push_back(t2);
        return intersects;
    }
}

Vector Sphere::normalAt(Point pointIn) {
    std::cout << "called sphere normalAt" << std::endl;
    Point objectPoint = this->getTransform().inverse() * pointIn;
    Vector objectNormal = objectPoint - this->getCenter();
    Vector worldNormal = this->getTransform().inverse().transpose() * objectNormal;
    return worldNormal.normalize();
}