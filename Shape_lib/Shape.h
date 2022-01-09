//
// Created by Allan, Ray on 1/1/22.
//

#ifndef GOOGLE_TESTS_SHAPE3D_H
#define GOOGLE_TESTS_SHAPE3D_H

#include "../Ray/Ray.h"
#include "../Matrix/Matrix.h"
#include "../Material_lib/Material.h"

#include <vector>


class Shape {
protected:
    Point center;
    Matrix transform;
    Material material;
public:
    Shape() {
        this->transform = Matrix::identityMatrix();
        // each shape starts with default material;
        this->material = Material();
    };
    Shape(Point centerIn) {
        this->center = centerIn;
        this->transform = Matrix::identityMatrix();
        this->material = Material();
    }
    virtual bool equals(Shape& rhs) const = 0;
    bool operator==(Shape& rhs) const;
    Point getCenter() {return this->center;}
    Matrix getTransform() {return this->transform;}
    Material getMaterial() {return this->material;}
    void setTransform(Matrix transformIn) {this->transform = transformIn;}
    void setMaterial(Material materialIn) {this->material = materialIn;}
    // base shape has no intersections
    virtual std::vector<float> getRayIntersects(Ray& rayIn);
    Vector normalAt(Point pointIn);
};

#endif //GOOGLE_TESTS_SHAPE3D_H
