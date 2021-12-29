//
// Created by Allan, Ray on 12/29/21.
//

#ifndef RAYTRACER_MATRIX_H
#define RAYTRACER_MATRIX_H

#define EPSILON 0.00001

#include <array>

class Matrix {
public:
    Matrix(){
        // default to 4x4 matrix
        dimension = 4;
    };
    Matrix(std::array<float, 16> matrixIn) {
        // assign to matrix
        dimension = 4;
        for (unsigned int r = 0; r < dimension; r++) {
            for (unsigned int c = 0; c < dimension; c++) {
                matrix[c][r] = matrixIn[(dimension * c) + r];
            }
        }
    };

    int getDimension() {return dimension;}
    float getPosition(unsigned int x, unsigned int y);
protected:
    std::array<std::array<float, 4>, 4> matrix;

    //float matrix[4][4];
    unsigned int dimension;
};


#endif //RAYTRACER_MATRIX_H
