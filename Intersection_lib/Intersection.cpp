//
// Created by Allan, Ray on 1/1/22.
//

#include "Intersection.h"
#include "../Shape_lib/Sphere.h"


bool Intersection::operator==(Intersection& rhs) {
    Shape* rhsShape = rhs.getShape();
    Shape* thisShape = this->getShape();
    return (std::abs(this->tValue - rhs.tValue) < EPSILON &&
    *thisShape == *rhsShape);
}

std::vector<Intersection> Intersection::intersect(Shape& shapeIn, Ray rayIn) {
    std::vector<float> rayIntersects = shapeIn.getRayIntersects(rayIn);
    std::vector<Intersection> resultIntersections;
    for (unsigned int i = 0; i < rayIntersects.size(); i++) {
        resultIntersections.push_back(Intersection(rayIntersects[i], &shapeIn));
    }
    return resultIntersections;
}

Intersection Intersection::getVisibleHit(std::vector<Intersection> intersections) {
    Intersection resultIntersection;
    if (intersections.size() < 1) {
        return resultIntersection;
    } else {
        resultIntersection = intersections[0];
        for (unsigned int i=1; i<intersections.size(); i++) {
            if (intersections[i].getTValue() < resultIntersection.getTValue()) {
                resultIntersection = intersections[i];
            }
        }
        if (resultIntersection.getTValue() < 0) {
            Intersection emptyIntersection;
            return emptyIntersection;
        } else {
            return resultIntersection;
        }
    }
}