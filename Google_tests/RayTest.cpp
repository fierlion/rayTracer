//
// Created by Allan, Ray on 1/1/22.
//

#include "gtest/gtest.h"
#include "../Ray_lib/Ray.h"
#include "../Matrix_lib/Transform.h"


TEST(RayTestSuite, ExampleRay){
    Point testOrigin = Point(1.0, 2.0, 3.0);
    Vector testDirection = Vector(4.0, 5.0, 6.0);
    Ray testRay = Ray(testOrigin, testDirection);

    EXPECT_TRUE(testRay.getOrigin() == testOrigin);
    EXPECT_TRUE(testRay.getDirection() == testDirection);
}

TEST(RayTestSuite, PointPositionFromDistance) {
    Point rayOrigin = Point(2.0, 3.0, 4.0);
    Vector rayDirection = Vector(1.0, 0.0, 0.0);
    Ray testRay = Ray(rayOrigin, rayDirection);
    Point expectedPosition0 = Point(2.0, 3.0, 4.0);
    Point expectedPosition1 = Point(3.0, 3.0, 4.0);
    Point expectedPosition2 = Point(1.0, 3.0, 4.0);
    Point expectedPosition3 = Point(4.5, 3.0, 4.0);
    EXPECT_TRUE(expectedPosition0 == testRay.position(0.0));
    EXPECT_TRUE(expectedPosition1 == testRay.position(1.0));
    EXPECT_TRUE(expectedPosition2 == testRay.position(-1.0));
    EXPECT_TRUE(expectedPosition3 == testRay.position(2.5));
}

TEST(RayTestSuite, TranslateRay) {
    Point rayOrigin = Point(1.0, 2.0, 3.0);
    Vector rayDirection = Vector(0.0, 1.0, 0.0);
    Ray testRay = Ray(rayOrigin, rayDirection);
    Transform translation = Transform::translate(3.0, 4.0, 5.0);
    Ray resultRay = testRay.transform(translation);
    Point expectedResultPoint = Point(4.0, 6.0, 8.0);
    Vector expectedResultVector = Vector(0.0, 1.0, 0.0);
    EXPECT_TRUE(resultRay.getOrigin() == expectedResultPoint);
    EXPECT_TRUE(resultRay.getDirection() == expectedResultVector);
}

TEST(RayTestSuite, ScaleRay) {
    Point rayOrigin = Point(1.0, 2.0, 3.0);
    Vector rayDirection = Vector(0.0, 1.0, 0.0);
    Ray testRay = Ray(rayOrigin, rayDirection);
    Transform scaling = Transform::scale(2.0, 3.0, 4.0);
    Ray resultRay = testRay.transform(scaling);
    Point expectedResultPoint = Point(2.0, 6.0, 12.0);
    Vector expectedResultVector = Vector(0.0, 3.0, 0.0);
    EXPECT_TRUE(resultRay.getOrigin() == expectedResultPoint);
    EXPECT_TRUE(resultRay.getDirection() == expectedResultVector);
}