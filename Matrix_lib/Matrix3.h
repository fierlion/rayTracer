//
// Created by Allan, Ray on 12/29/21.
//

#ifndef RAYTRACER_MATRIX3_H
#define RAYTRACER_MATRIX3_H
#include "Matrix.h"

class Matrix3 : public Matrix {
    Matrix3() {
        dimension = 3;
    };
    Matrix3(float matrixIn[9]) {
        dimension = 3;
    }
};

#endif //RAYTRACER_MATRIX3_H
