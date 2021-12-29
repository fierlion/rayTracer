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
    Matrix2(float matrixIn[4]) {
        dimension = 2;
    };
};


#endif //RAYTRACER_MATRIX2_H
