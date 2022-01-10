//
// Created by Allan, Ray on 1/1/22.
//

#include "Shape.h"

#include <memory>

bool Shape::operator==(Shape& rhs) const {
    return equals(rhs);
}

Vector Shape::normalAt(Point pointIn) {
    std::cout << "called base normalAt" << std::endl;
    Point objectPoint = this->getTransform().inverse() * pointIn;
    Vector objectNormal = objectPoint - this->getCenter();
    Vector worldNormal = this->getTransform().inverse().transpose() * objectNormal;
    return worldNormal.normalize();
}

bool Shape::equals(Shape &rhs) const {
    return false;
}

std::vector<float> Shape::getRayIntersects(Ray& rayIn) {
    return std::vector<float>();
}

