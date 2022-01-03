//
// Created by Allan, Ray on 1/1/22.
//

#include "Ray.h"

Point Ray::position(float time) {
    // TODO figure out why the operator ordering is wonky
    // Point + Vector returns a Point
    return this->getOrigin() + (this->getDirection() * time);
}

Ray Ray::transform(Matrix transformMatrix) {
    Point transformedOrigin = transformMatrix * this->getOrigin();
    Vector transformedDirection = transformMatrix * this->getDirection();
    return Ray(transformedOrigin, transformedDirection);
}