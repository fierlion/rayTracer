//
// Created by Allan, Ray on 12/29/21.
//

#ifndef RAYTRACER_MATRIX2_H
#define RAYTRACER_MATRIX2_H
#import "Matrix.h"

class Matrix2 : public Matrix {
public:
    Matrix2() {
        dimension = 2;
    };
    Matrix2(std::array<float, 4> matrixIn) {
        dimension = 2;
        for (unsigned int r = 0; r < dimension; r++) {
            for (unsigned int c = 0; c < dimension; c++) {
                matrix[c][r] = matrixIn[(dimension * c) + r];
            }
        }
    };
    float determinant();
};

#endif //RAYTRACER_MATRIX2_H
