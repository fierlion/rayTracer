//
// Created by Allan, Ray on 1/1/22.
//

#include "Shape.h"

#include <memory>

bool Shape::operator==(Shape& rhs) const {
    return equals(rhs);
}

std::vector<float> Shape::intersect(Ray rayIn) {
    return std::vector<float>();
}

bool Shape::equals(Shape &rhs) const {
    return false;
}
