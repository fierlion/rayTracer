//
// Created by Allan, Ray on 1/1/22.
//

#include "Sphere.h"

#include <vector>
#include <numeric>

std::vector<float> Sphere::intersect(Ray rayIn) {
    std::vector<float> intersects;
    Vector sphereToRay = rayIn.getOrigin() - Point(0.0, 0.0, 0.0);
    float directionDot = rayIn.getDirection().dotProduct(rayIn.getDirection());
    float directionSphereDot = 2.0 * (rayIn.getDirection().dotProduct(sphereToRay));
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
