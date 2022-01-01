//
// Created by Allan, Ray on 12/31/21.
//

#ifndef GOOGLE_TESTS_TRANSFORM_H
#define GOOGLE_TESTS_TRANSFORM_H

#include "../Matrix_lib/Matrix.h"

enum class TransformType {Translate,
                          Scale,
                          RotateX,
                          RotateY,
                          RotateZ,
                          Shear};

// Transform class is a library of Transformation Matrices
class Transform : public Matrix {
protected:
    TransformType transformType;
public:
    Transform() : Matrix() {};
    Transform(std::array<float, 16> matrixIn, TransformType typeIn) : Matrix(matrixIn), transformType(typeIn) {
        transformType = typeIn;
    };
    static Transform translate(float xIn, float yIn, float zIn);
    static Transform scale(float xIn, float yIn, float zIn);
    static Transform rotateX(float radians);
    static Transform rotateY(float radians);
    static Transform rotateZ(float radians);
    static Transform shear(float xy, float xz, float yx, float yz, float zx, float zy);
};

#endif //GOOGLE_TESTS_TRANSFORM_H