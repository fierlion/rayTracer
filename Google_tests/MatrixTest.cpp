//
// Created by Allan, Ray on 12/29/21.
//

#include "gtest/gtest.h"
#include "../Matrix_lib/Matrix.h"
#include "../Matrix_lib/Matrix2.h"
#include "../Matrix_lib/Matrix3.h"
#include <array>

TEST(MatrixTestSuite, EmptyFourByFourTestMatrix){
    Matrix testMatrix;
    EXPECT_EQ(testMatrix.getDimension(), 4);
}

TEST(MatrixTestSuite, FourByFourTestMatrix){
    std::array<float, 16> matrixIn = {1.0, 2.0, 3.0, 4.0,
                                      5.5, 6.5, 7.5, 8.5,
                                      9.0, 10.0, 11.0, 12.0,
                                      13.5, 14.5, 15.5, 16.5};
    Matrix testMatrix(matrixIn);
    EXPECT_TRUE(testMatrix.getPosition(0,0) - 1.0 < EPSILON);
    EXPECT_TRUE(testMatrix.getPosition(0,3) - 4.0 < EPSILON);
    EXPECT_TRUE(testMatrix.getPosition(1,0) - 5.5 < EPSILON);
    EXPECT_TRUE(testMatrix.getPosition(1,2) - 7.5 < EPSILON);
    EXPECT_TRUE(testMatrix.getPosition(2,2) - 11.0 < EPSILON);
    EXPECT_TRUE(testMatrix.getPosition(3,0) - 13.5 < EPSILON);
    EXPECT_TRUE(testMatrix.getPosition(3,2) - 15.5 < EPSILON);
}

TEST(MatrixTestSuite, ThreeByThreeTestMatrix){
    std::array<float, 9> matrixIn = {-3.0, 5.0, 0.0,
                                     1.0, -2.0, -7.0,
                                     0.0, 1.0, 1.0};

    Matrix3 testMatrix(matrixIn);
    EXPECT_TRUE(std::abs(testMatrix.getPosition(0,0) - -3.0) < EPSILON);
    EXPECT_TRUE(std::abs(testMatrix.getPosition(1,1) - -2.0) < EPSILON);
    EXPECT_TRUE(testMatrix.getPosition(2,2) - 1.0 < EPSILON);
}

TEST(MatrixTestSuite, TwoByTwoTestMatrix) {
    std::array<float, 4> matrixIn = {-3.0, 5.0, 1.0, -2.0};
    Matrix2 testMatrix(matrixIn);
    EXPECT_TRUE(std::abs(testMatrix.getPosition(0,0) - -3.0) < EPSILON);
    EXPECT_TRUE(testMatrix.getPosition(0,1) - 5.0 < EPSILON);
    EXPECT_TRUE(testMatrix.getPosition(1,0) - 1.0 < EPSILON);
    EXPECT_TRUE(std::abs(testMatrix.getPosition(1,1) - -2.0) < EPSILON);
}

TEST(MatrixTestSuite, MatrixEquality) {
    std::array<float, 4> matrixIn = {-3.0, 5.0, 1.0, -2.0};
    std::array<float, 4> matrixInNotEqual = {-4.0, 5.0, 1.0, -2.0};
    Matrix2 testMatrixA(matrixIn);
    Matrix2 testMatrixB(matrixIn);
    Matrix2 testMatrixC(matrixInNotEqual);
    EXPECT_TRUE(testMatrixA == testMatrixB);
    EXPECT_FALSE(testMatrixA == testMatrixC);
    EXPECT_TRUE(testMatrixA != testMatrixC);
    EXPECT_FALSE(testMatrixA != testMatrixB);
}

TEST(MatrixTestSuite, MatrixMultiplication) {
    std::array<float, 16> matrixInA = {1.0, 2.0, 3.0, 4.0,
                                      5.0, 6.0, 7.0, 8.0,
                                      9.0, 8.0, 7.0, 6.0,
                                      5.0, 4.0, 3.0, 2.0};

    std::array<float, 16> matrixInB = {-2.0, 1.0, 2.0, 3.0,
                                      3.0, 2.0, 1.0, -1.0,
                                      4.0, 3.0, 6.0, 5.0,
                                      1.0, 2.0, 7.0, 8.0};
    std::array<float, 16> expectedResult = {20.0, 22.0, 50.0, 48.0,
                                       44.0, 54.0, 114.0, 108.0,
                                       40.0, 58.0, 110.0, 102.0,
                                       16.0, 26.0, 46.0, 42.0};
    Matrix testMatrixA(matrixInA);
    Matrix testMatrixB(matrixInB);
    Matrix expectedMatrix(expectedResult);
    Matrix resultMatrix = testMatrixA * testMatrixB;
    EXPECT_TRUE(expectedMatrix == resultMatrix);
}

TEST(MatrixTestSuite, MatrixTupleMultiplication) {
    std::array<float, 16> matrixIn = {1.0, 2.0, 3.0, 4.0,
                                       2.0, 4.0, 4.0, 2.0,
                                       8.0, 6.0, 4.0, 1.0,
                                       0.0, 0.0, 0.0, 1.0};
    Matrix testMatrix(matrixIn);
    Tuple testTuple(1.0, 2.0, 3.0, 1.0);
    Tuple resultTuple = testMatrix * testTuple;
    Tuple expectedTuple(18.0, 24.0, 33.0, 1.0);
    EXPECT_TRUE(expectedTuple == resultTuple);
}

TEST(MatrixTestSuite, IdentityMatrix) {
    std::array<float, 16> identityMatrixIn = {1.0, 0.0, 0.0, 0.0,
                                      0.0, 1.0, 0.0, 0.0,
                                      0.0, 0.0, 1.0, 0.0,
                                      0.0, 0.0, 0.0, 1.0};
    std::array<float, 16> matrixIn = {1.0, 2.0, 3.0, 4.0,
                                      2.0, 4.0, 4.0, 2.0,
                                      8.0, 6.0, 4.0, 1.0,
                                      0.0, 0.0, 0.0, 1.0};
    Matrix expectedIdentityMatrix(identityMatrixIn);
    Matrix testMatrix(matrixIn);
    Matrix resultIdentityMatrix = Matrix::identityMatrix();
    EXPECT_TRUE(expectedIdentityMatrix == resultIdentityMatrix);
    Matrix resultMatrix = testMatrix * Matrix::identityMatrix();
    EXPECT_TRUE(testMatrix == resultMatrix);
}

TEST(MatrixTestSuite, MatrixTranspose) {
    std::array<float, 16> matrixIn = {0.0, 9.0, 3.0, 0.0,
                                      9.0, 8.0, 0.0, 8.0,
                                      1.0, 8.0, 5.0, 3.0,
                                      0.0, 0.0, 5.0, 8.0};
    std::array<float, 16> matrixTransposeIn = {0.0, 9.0, 1.0, 0.0,
                                               9.0, 8.0, 8.0, 0.0,
                                               3.0, 0.0, 5.0, 5.0,
                                               0.0, 8.0, 3.0, 8.0};
    Matrix testMatrix(matrixIn);
    Matrix resultMatrix = testMatrix.transpose();
    Matrix expectedMatrix(matrixTransposeIn);
    EXPECT_TRUE(expectedMatrix == resultMatrix);
}

TEST(MatrixTestSuite, DeterminantMatrixTwo) {
    std::array<float, 4> matrixIn = {1.0, 5.0, -3.0, 2.0};
    Matrix2 testMatrix(matrixIn);
    EXPECT_TRUE(testMatrix.determinant() - 17.0 < EPSILON);
}