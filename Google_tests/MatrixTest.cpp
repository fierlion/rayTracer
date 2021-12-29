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