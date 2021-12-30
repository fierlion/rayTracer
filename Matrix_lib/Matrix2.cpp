//
// Created by Allan, Ray on 12/29/21.
//

#include "Matrix2.h"

float Matrix2::determinant() {
    return (matrix[0][0] * matrix[1][1]) - (matrix[0][1] * matrix[1][0]);
}