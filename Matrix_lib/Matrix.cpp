//
// Created by Allan, Ray on 12/29/21.
//

#include <iostream>
#include "Matrix.h"
#include "../Tuples_lib/Tuple.h"

float Matrix::getPosition(unsigned int x, unsigned int y) {
    // TODO throw out of bounds exception
    if ((x < dimension && y < dimension) && (x >= 0 && y >= 0)) {
        return matrix[x][y];
    }
}

void Matrix::displayMatrixContents() {
    for(unsigned int h = 0; h < dimension; h++) {
        for (unsigned int w = 0; w < dimension; w++) {
            std::cout << std::to_string(matrix[h][w]) + " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool Matrix::operator==(const Matrix& rhs) {
    bool isEqual = true;
    for(unsigned int h = 0; h < dimension; h++) {
        for (unsigned int w = 0; w < dimension; w++) {
            if (std::abs(matrix[h][w] - rhs.matrix[h][w]) < EPSILON) {
                continue;
            } else {
                isEqual = false;
            }
        }
    }
    return isEqual;
}

// TODO figure out how to invert `bool Matrix::operator==(const Matrix& rhs)`
bool Matrix::operator!=(const Matrix& rhs) {
    bool isEqual = true;
    for(unsigned int h = 0; h < dimension; h++) {
        for (unsigned int w = 0; w < dimension; w++) {
            if (std::abs(matrix[h][w] - rhs.matrix[h][w]) < EPSILON) {
                continue;
            } else {
                isEqual = false;
            }
        }
    }
    return !(isEqual);
}

// TODO figure out how to make this work for all dimensions
Matrix Matrix::operator*(const Matrix& rhs) {
    std::array<float, 16> resultArray;
    for(unsigned int r = 0; r < dimension; r++) {
        for (unsigned int c = 0; c < dimension; c++) {
            float result = 0.0;
            for (unsigned int i = 0; i < dimension; i++) {
                result += matrix[r][i] * rhs.matrix[i][c];
            }
            resultArray[(dimension * r) + c] = result;
        }
    }
    return Matrix(resultArray);
}

Tuple Matrix::operator*(const Tuple& rhs) {
    std::array<float, 4> resultArray;
    for (unsigned int r = 0; r < dimension; r++) {
        float result = 0.0;
        result += matrix[r][0] * rhs.getX();
        result += matrix[r][1] * rhs.getY();
        result += matrix[r][2] * rhs.getZ();
        result += matrix[r][3] * rhs.getW();
        resultArray[r] = result;
    }
    return Tuple(resultArray[0], resultArray[1], resultArray[2], resultArray[3]);
}

Matrix Matrix::identityMatrix() {
    std::array<float, 16> matrixIn = {1.0, 0.0, 0.0, 0.0,
                                      0.0, 1.0, 0.0, 0.0,
                                      0.0, 0.0, 1.0, 0.0,
                                      0.0, 0.0, 0.0, 1.0};
    return Matrix(matrixIn);
}

Matrix Matrix::transpose() {
    std::array<float, 16> resultArray;
    for(unsigned int r = 0; r < dimension; r++) {
        for (unsigned int c = 0; c < dimension; c++) {
            resultArray[(dimension * c) + r] = matrix[r][c];
        }
    }
    return Matrix(resultArray);
}

float Matrix::determinant() {
    if (dimension == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    }
    // TODO else throw exception
}

Matrix Matrix::subMatrix3(unsigned int row, unsigned int col) {
    std::array<float, 9> resultArray;
    unsigned int current = 0;
    for(unsigned int r = 0; r < dimension; r++) {
        for (unsigned int c = 0; c < dimension; c++) {
            if ((r != row) && (c != col)) {
                resultArray[current] = matrix[r][c];
                current += 1;
            }
        }
    }
    return Matrix(resultArray);
}

Matrix Matrix::subMatrix2(unsigned int row, unsigned int col) {
    std::array<float, 4> resultArray;
    unsigned int current = 0;
    for(unsigned int r = 0; r < dimension; r++) {
        for (unsigned int c = 0; c < dimension; c++) {
            if ((r != row) && (c != col)) {
                resultArray[current] = matrix[r][c];
                current += 1;
            }
        }
    }
    return Matrix(resultArray);
}