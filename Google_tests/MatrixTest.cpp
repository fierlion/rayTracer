//
// Created by Allan, Ray on 12/29/21.
//

#include "gtest/gtest.h"
#include "../Matrix_lib/Matrix.h"

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

    Matrix testMatrix(matrixIn);
    EXPECT_TRUE(std::abs(testMatrix.getPosition(0,0) - -3.0) < EPSILON);
    EXPECT_TRUE(std::abs(testMatrix.getPosition(1,1) - -2.0) < EPSILON);
    EXPECT_TRUE(testMatrix.getPosition(2,2) - 1.0 < EPSILON);
}

TEST(MatrixTestSuite, TwoByTwoTestMatrix) {
    std::array<float, 4> matrixIn = {-3.0, 5.0, 1.0, -2.0};
    Matrix testMatrix(matrixIn);
    EXPECT_TRUE(std::abs(testMatrix.getPosition(0,0) - -3.0) < EPSILON);
    EXPECT_TRUE(testMatrix.getPosition(0,1) - 5.0 < EPSILON);
    EXPECT_TRUE(testMatrix.getPosition(1,0) - 1.0 < EPSILON);
    EXPECT_TRUE(std::abs(testMatrix.getPosition(1,1) - -2.0) < EPSILON);
}

TEST(MatrixTestSuite, MatrixEquality) {
    std::array<float, 4> matrixIn = {-3.0, 5.0, 1.0, -2.0};
    std::array<float, 4> matrixInNotEqual = {-4.0, 5.0, 1.0, -2.0};
    Matrix testMatrixA(matrixIn);
    Matrix testMatrixB(matrixIn);
    Matrix testMatrixC(matrixInNotEqual);
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
    Matrix testMatrix(matrixIn);
    EXPECT_TRUE(testMatrix.determinant() - 17.0 < EPSILON);
}

TEST(MatrixTestSuite, SubmatrixFourThreeTwo) {
    std::array<float, 16> matrixFourIn = {-6.0, 1.0, 1.0, 6.0,
                                          -8.0, 5.0, 8.0, 6.0,
                                          -1.0, 0.0, 8.0, 2.0,
                                          -7.0, 1.0, -1.0, 1.0};

    std::array<float, 9> matrixThreeOut = {-6.0, 1.0, 6.0,
                                           -8.0, 8.0, 6.0,
                                           -7.0, -1.0, 1.0};

    std::array<float, 9> matrixThreeIn = {1.0, 5.0, 0.0,
                                          -3.0, 2.0, 7.0,
                                          0.0, 6.0, -3.0};

    std::array<float, 4> matrixTwoOut = {-3.0, 2.0, 0.0, 6.0};

    Matrix matrixFour = Matrix(matrixFourIn);
    Matrix resultMatrixThree = matrixFour.subMatrix3(2, 1);
    Matrix expectedMatrixThree = Matrix(matrixThreeOut);
    EXPECT_TRUE(expectedMatrixThree == resultMatrixThree);

    Matrix matrixThree = Matrix(matrixThreeIn);
    Matrix resultMatrixTwo = matrixThree.subMatrix2(0, 2);
    Matrix expectedMatrixTwo = Matrix(matrixTwoOut);
    EXPECT_TRUE(expectedMatrixTwo == resultMatrixTwo);
}

TEST(MatrixTestSuite, ThreeByThreeMinor) {
    std::array<float, 9> matrixThreeIn = {3.0, 5.0, 0.0,
                                          2.0, -1.0, -7.0,
                                          6.0, -1.0, 5.0};
    Matrix matrixThree(matrixThreeIn);
    Matrix subMatrixTwo = matrixThree.subMatrix2(1, 0);
    EXPECT_TRUE(std::abs(subMatrixTwo.determinant() - 25) < EPSILON);
    // .minor() combines subMatrix and determinant
    EXPECT_TRUE(std::abs(matrixThree.minor3(1, 0) - 25) < EPSILON);
}

TEST(MatrixTestSuite, ThreeByThreeCoFactor) {
    std::array<float, 9> matrixThreeIn = {3.0, 5.0, 0.0,
                                          2.0, -1.0, -7.0,
                                          6.0, -1.0, 5.0};
    Matrix matrixThree(matrixThreeIn);
    EXPECT_TRUE(std::abs(matrixThree.minor3(0, 0) - -12) < EPSILON);
    EXPECT_TRUE(std::abs(matrixThree.coFactor3(0, 0) - -12) < EPSILON);
    EXPECT_TRUE(std::abs(matrixThree.minor3(1, 0) - 25) < EPSILON);
    EXPECT_TRUE(std::abs(matrixThree.coFactor3(1, 0) - -25) < EPSILON);
}

TEST(MatrixTestSuite, ThreeByThreeDeterminant) {
    std::array<float, 9> matrixThreeIn = {1.0, 2.0, 6.0,
                                          -5.0, 8.0, -4.0,
                                          2.0, 6.0, 4.0};
    Matrix matrixThree(matrixThreeIn);
    EXPECT_TRUE(std::abs(matrixThree.coFactor3(0, 0) - 56) < EPSILON);
    EXPECT_TRUE(std::abs(matrixThree.coFactor3(0, 1) - 12) < EPSILON);
    EXPECT_TRUE(std::abs(matrixThree.coFactor3(0, 2) - -46) < EPSILON);
    EXPECT_TRUE(std::abs(matrixThree.determinant() - -196) < EPSILON);
}

TEST(MatrixTestSuite, FourByFourDeterminant) {
    std::array<float, 16> matrixFourIn = {-2.0, -8.0, 3.0, 5.0,
                                          -3.0, 1.0, 7.0, 3.0,
                                          1.0, 2.0, -9.0, 6.0,
                                          -6.0, 7.0, 7.0, -9.0};
    Matrix matrixFour(matrixFourIn);
    EXPECT_TRUE(std::abs(matrixFour.coFactor4(0, 0) - 690) < EPSILON);
    EXPECT_TRUE(std::abs(matrixFour.coFactor4(0, 1) - 447) < EPSILON);
    EXPECT_TRUE(std::abs(matrixFour.coFactor4(0, 2) - 210) < EPSILON);
    EXPECT_TRUE(std::abs(matrixFour.coFactor4(0, 3) - 51) < EPSILON);
    EXPECT_TRUE(std::abs(matrixFour.determinant() - -4071) < EPSILON);
}

TEST(MatrixTestSuite, MatrixIsInvertible) {
    std::array<float, 16> matrixFourInvertibleIn = {6.0, 4.0, 4.0, 4.0,
                                                   5.0, 5.0, 7.0, 6.0,
                                                   4.0, -9.0, 3.0, -7.0,
                                                   9.0, 1.0, 7.0, -6.0};
    std::array<float, 16> matrixFourNonInvertibleIn = {-4.0, 2.0, -2.0, -3.0,
                                                      9.0, 6.0, 2.0, 6.0,
                                                      0.0, -5.0, 1.0, -5.0,
                                                      0.0, 0.0, 0.0, 0.0};
    Matrix matrixFourInvertible(matrixFourInvertibleIn);
    Matrix matrixFourNonInvertible(matrixFourNonInvertibleIn);
    EXPECT_TRUE(matrixFourInvertible.isInvertible());
    EXPECT_FALSE(matrixFourNonInvertible.isInvertible());
}

TEST(MatrixTestSuite, InvertMatrix) {
    std::array<float, 16> matrixFourIn = {-5.0, 2.0, 6.0, -8.0,
                                         1.0, -5.0, 1.0, 8.0,
                                         7.0, 7.0, -6.0, -7.0,
                                         1.0, -3.0, 7.0, 4.0};
    std::array<float, 16> matrixFourInvertedIn = {0.21805, 0.45113, 0.24060, -0.04511,
                                                 -0.80827, -1.45677, -0.44361, 0.52068,
                                                 -0.07895, -0.22368, -0.05263, 0.19737,
                                                 -0.52256, -0.81391, -0.30075, 0.30639};
    Matrix matrixFour(matrixFourIn);
    Matrix resultMatrix = matrixFour.inverse();
    Matrix matrixFourExpectedInversion(matrixFourInvertedIn);
    EXPECT_TRUE(std::abs(matrixFour.determinant() - 532) < EPSILON);
    EXPECT_TRUE(std::abs(matrixFour.coFactor4(2,3) - -160) < EPSILON);
    EXPECT_TRUE(std::abs(matrixFour.coFactor4(3,2) - 105) < EPSILON);
    EXPECT_TRUE(matrixFourExpectedInversion == resultMatrix);

    std::array<float, 16> matrixFourInB = {8.0, -5.0, 9.0, 2.0,
                                           7.0, 5.0, 6.0, 1.0,
                                           -6.0, 0.0, 9.0, 6.0,
                                           -3.0, 0.0, -9.0, -4.0};
    std::array<float, 16> matrixFourInvertedInB = {-0.15385, -0.15385, -0.28205, -0.53846,
                                                   -0.07692, 0.12308, 0.02564, 0.03077,
                                                   0.35897, 0.35897, 0.43590, 0.92308,
                                                   -0.69231, -0.69231, -0.76923, -1.92308};
    Matrix matrixFourB(matrixFourInB);
    Matrix resultMatrixB = matrixFourB.inverse();
    Matrix matrixFourExpectedInversionB(matrixFourInvertedInB);
    EXPECT_TRUE(matrixFourExpectedInversionB == resultMatrixB);

    std::array<float, 16> matrixFourInC = {9.0, 3.0, 0.0, 9.0,
                                           -5.0, -2.0, -6.0, -3.0,
                                           -4.0, 9.0, 6.0, 4.0,
                                           -7.0, 6.0, 6.0, 2.0};
    std::array<float, 16> matrixFourInvertedInC = {-0.04074, -0.07778, 0.14444, -0.22222,
                                                   -0.07778, 0.03333, 0.36667, -0.33333,
                                                   -0.02901, -0.14630, -0.10926, 0.12963,
                                                   0.17778, 0.06667, -0.26667, 0.33333};
    Matrix matrixFourC(matrixFourInC);
    Matrix resultMatrixC = matrixFourC.inverse();
    Matrix matrixFourExpectedInversionC(matrixFourInvertedInC);
    EXPECT_TRUE(matrixFourExpectedInversionC == resultMatrixC);
}

TEST(MatrixTestSuite, MultiplyMatrixByInverse) {
    std::array<float, 16> matrixFourInA = {3.0, -9.0, 7.0, 3.0,
                                          3.0, -8.0, 2.0, -9.0,
                                          -4.0, 4.0, 4.0, 1.0,
                                          -6.0, 5.0, -1.0, 1.0};

    std::array<float, 16> matrixFourInB = {8.0, 2.0, 2.0, 2.0,
                                          3.0, -1.0, 7.0, 0.0,
                                          7.0, 0.0, 5.0, 4.0,
                                          6.0, -2.0, 0.0, 5.0};
    Matrix matrixFourA(matrixFourInA);
    Matrix matrixFourB(matrixFourInB);
    Matrix matrixFourC = matrixFourA * matrixFourB;

    Matrix inverseMatrixB = matrixFourB.inverse();
    Matrix resultMatrix = matrixFourC * inverseMatrixB;
    EXPECT_TRUE(matrixFourA == resultMatrix);
}