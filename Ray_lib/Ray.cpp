//
// Created by Allan, Ray on 1/1/22.
//

#include "Ray.h"

Point Ray::position(float time) {
    // TODO figure out why the operator ordering is wonky
    // Point + Vector returns a Point
    return this->getOrigin() + (this->getDirection() * time);
}