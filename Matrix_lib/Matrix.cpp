//
// Created by Allan, Ray on 12/29/21.
//

#include "Matrix.h"

float Matrix::getPosition(unsigned int x, unsigned int y) {
    // TODO throw out of bounds exception
    if ((x < dimension && y < dimension) && (x >= 0 && y >= 0)) {
        return matrix[x][y];
    }
}
