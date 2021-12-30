//
// Created by Allan, Ray on 12/29/21.
//

#ifndef RAYTRACER_MATRIX3_H
#define RAYTRACER_MATRIX3_H
#include "Matrix.h"
#include <array>

class Matrix3 : public Matrix {
public:
    Matrix3() {
        dimension = 3;
    };
    Matrix3(std::array<float, 9> matrixIn) {
        dimension = 3;
        for (unsigned int r = 0; r < dimension; r++) {
            for (unsigned int c = 0; c < dimension; c++) {
                matrix[c][r] = matrixIn[(dimension * c) + r];
            }
        }
    }
};

#endif //RAYTRACER_MATRIX3_H
