//
// Created by Allan, Ray on 1/1/22.
//

#ifndef GOOGLE_TESTS_SHAPE3D_H
#define GOOGLE_TESTS_SHAPE3D_H

#include "../Ray_lib/Ray.h"
#include "../Matrix_lib/Matrix.h"

#include <vector>


class Shape {
protected:
    Point center;
    Matrix transform;
public:
    Shape() {
        this->transform = Matrix::identityMatrix();
    };
    Shape(Point centerIn) {
        this->center = centerIn;
        this->transform = Matrix::identityMatrix();
    }
    virtual bool equals(Shape& rhs) const = 0;
    bool operator==(Shape& rhs) const;
    Point getCenter() {return this->center;}
    Matrix getTransform() {return this->transform;}
    void setTransform(Matrix transformIn) {this->transform = transformIn;}
    // base shape has no intersections
    virtual std::vector<float> getRayIntersects(Ray& rayIn);
    Vector normalAt(Point pointIn);
};

#endif //GOOGLE_TESTS_SHAPE3D_H
