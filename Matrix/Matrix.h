//
// Created by Allan, Ray on 12/29/21.
//

#ifndef RAYTRACER_MATRIX_H
#define RAYTRACER_MATRIX_H

#define EPSILON 0.00001

#include "../Tuples_lib/Tuple.h"
#include "../Tuples_lib/Point.h"

#include <array>


class Matrix {
protected:
    std::array<std::array<float, 4>, 4> matrix;
    unsigned int dimension;
public:
    Matrix(){
        // default to 4x4 matrix
        dimension = 4;
    };
    Matrix(std::array<float, 16> matrixIn) {
        dimension = 4;
        for (unsigned int r = 0; r < dimension; r++) {
            for (unsigned int c = 0; c < dimension; c++) {
                matrix[c][r] = matrixIn[(dimension * c) + r];
            }
        }
    };
    Matrix(std::array<float, 9> matrixIn) {
        dimension = 3;
        for (unsigned int r = 0; r < dimension; r++) {
            for (unsigned int c = 0; c < dimension; c++) {
                matrix[c][r] = matrixIn[(dimension * c) + r];
            }
        }
    };
    Matrix(std::array<float, 4> matrixIn) {
        dimension = 2;
        for (unsigned int r = 0; r < dimension; r++) {
            for (unsigned int c = 0; c < dimension; c++) {
                matrix[c][r] = matrixIn[(dimension * c) + r];
            }
        }
    };

    int getDimension() {return dimension;}
    float getPosition(unsigned int x, unsigned int y);
    void displayMatrixContents();
    bool operator==(const Matrix& rhs);
    bool operator!=(const Matrix& rhs);
    Matrix operator*(const Matrix& rhs);
    Tuple operator*(const Tuple& rhs);
    Point operator*(const Point& rhs);
    Vector operator*(const Vector& rhs);
    float determinant();
    static Matrix identityMatrix();
    Matrix transpose();
    Matrix subMatrix3(unsigned int row, unsigned int col);
    float minor4(unsigned int row, unsigned int col);
    float coFactor4(unsigned int row, unsigned int col);
    Matrix subMatrix2(unsigned int row, unsigned int col);
    float minor3(unsigned int row, unsigned int col);
    float coFactor3(unsigned int row, unsigned int col);
    bool isInvertible();
    Matrix inverse();
};


#endif //RAYTRACER_MATRIX_H
