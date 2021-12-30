//
// Created by Allan, Ray on 12/29/21.
//

#include <iostream>
#include "Matrix.h"

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
            if (!(std::abs(matrix[h][w] - rhs.matrix[h][w]) < EPSILON)) {
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
            if (!(std::abs(matrix[h][w] - rhs.matrix[h][w]) < EPSILON)) {
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
        for (unsigned int c = 0; c < dimension; c++) {    //r0c0 r0c1 r0c2 r0c3
            float result = 0.0;
            for (unsigned int i = 0; i < dimension; i++) {
                //std::cout << "row: " << std::to_string(r) << " i: " << std::to_string(i) << std::endl;
                //std::cout << "i: " << std::to_string(i) << " col: " << std::to_string(c) << std::endl;
                result += matrix[r][i] * rhs.matrix[i][c];
            }
            //std::cout << std::endl;
            resultArray[(dimension * r) + c] = result;
        }
    }
    return Matrix(resultArray);
}