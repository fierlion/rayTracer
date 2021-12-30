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

bool Matrix::operator!=(const Matrix& rhs) {
    return !this->operator==(rhs);
}

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

float Matrix::minor4(unsigned int row, unsigned int col) {
    return this->subMatrix3(row, col).determinant();
}

float Matrix::coFactor4(unsigned int row, unsigned int col) {
    float minor = this->minor4(row, col);
    if(((row + col) & 1) == 0) {
        return minor;
    } else {
        return minor * -1;
    }
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

float Matrix::minor3(unsigned int row, unsigned int col) {
    return this->subMatrix2(row, col).determinant();
}

float Matrix::coFactor3(unsigned int row, unsigned int col) {
    float minor = this->minor3(row, col);
    if(((row + col) & 1) == 0) {
        return minor;
    } else {
        return minor * -1;
    }
}

float Matrix::determinant() {
    // todo throw exception for out of range dimension
    // todo ew gross need to fix this.
    if (dimension == 2) {
        return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
    } else if (dimension == 3) {
        float result = 0.0;
        for (unsigned int i = 0; i < dimension; i++) {
            result += matrix[0][i] * this->coFactor3(0, i);
        }
        return result;
    } else if (dimension == 4) {
        float result = 0.0;
        for (unsigned int i = 0; i < dimension; i++) {
            result += matrix[0][i] * this->coFactor4(0, i);
        }
        return result;
    }
}