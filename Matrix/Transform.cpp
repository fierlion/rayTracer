//
// Created by Allan, Ray on 12/31/21.
//

#include "Transform.h"
#include "Matrix.h"

#include <numeric>

Transform Transform::translate(float xIn, float yIn, float zIn) {
    std::array<float, 16> matrixIn = {1.0, 0.0, 0.0, xIn,
                                      0.0, 1.0, 0.0, yIn,
                                      0.0, 0.0, 1.0, zIn,
                                      0.0, 0.0, 0.0, 1.0};
    return Transform(matrixIn, TransformType::Translate);
};

Transform Transform::scale(float xIn, float yIn, float zIn) {
    std::array<float, 16> matrixIn = {xIn, 0.0, 0.0, 0.0,
                                      0.0, yIn, 0.0, 0.0,
                                      0.0, 0.0, zIn, 0.0,
                                      0.0, 0.0, 0.0, 1.0};
    return Transform(matrixIn, TransformType::Scale);
};

Transform Transform::rotateX(float radians) {
    float cosR = std::cos(radians);
    float negSinR = std::sin(radians) * -1.0;
    float sinR = std::sin(radians);
    std::array<float, 16> matrixIn = {1.0, 0.0, 0.0, 0.0,
                                      0.0, cosR, negSinR, 0.0,
                                      0.0, sinR, cosR, 0.0,
                                      0.0, 0.0, 0.0, 1.0};
    return Transform(matrixIn, TransformType::RotateX);
};

Transform Transform::rotateY(float radians) {
    float cosR = std::cos(radians);
    float negSinR = std::sin(radians) * -1.0;
    float sinR = std::sin(radians);
    std::array<float, 16> matrixIn = {cosR, 0.0, sinR, 0.0,
                                      0.0, 1.0, 0.0, 0.0,
                                      negSinR, 0.0, cosR, 0.0,
                                      0.0, 0.0, 0.0, 1.0};
    return Transform(matrixIn, TransformType::RotateY);
};

Transform Transform::rotateZ(float radians) {
    float cosR = std::cos(radians);
    float negSinR = std::sin(radians) * -1.0;
    float sinR = std::sin(radians);
    std::array<float, 16> matrixIn = {cosR, negSinR, 0.0, 0.0,
                                      sinR, cosR, 0.0, 0.0,
                                      0.0, 0.0, 1.0, 0.0,
                                      0.0, 0.0, 0.0, 1.0};
    return Transform(matrixIn, TransformType::RotateZ);
};

Transform Transform::shear(float xy, float xz, float yx, float yz, float zx, float zy) {
    std::array<float, 16> matrixIn = {1.0, xy, xz, 0.0,
                                      yx, 1.0, yz, 0.0,
                                      zx, zy, 1.0, 0.0,
                                      0.0, 0.0, 0.0, 1.0};
    return Transform(matrixIn, TransformType::Shear);
}