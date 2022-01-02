//
// Created by Allan, Ray on 1/1/22.
//

#include "gtest/gtest.h"
#include "../Shape_lib/Shape.h"
#include "../Shape_lib/Sphere.h"
#include "../Ray_lib/Ray.h"

#include <vector>


TEST(ShapeTestSuite, RayIntersectsSphereTwoPoints){
    Point testOrigin = Point(0.0, 0.0, -5.0);
    Vector testDirection = Vector(0.0, 0.0, 1.0);
    Ray testRay = Ray(testOrigin, testDirection);
    // unit sphere
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    std::vector<float> resultIntersects = testSphere.intersect(testRay);
    EXPECT_EQ(resultIntersects.size(), 2);
    EXPECT_TRUE(std::abs(resultIntersects[0] - 4.0) < EPSILON);
    EXPECT_TRUE(std::abs(resultIntersects[1] - 6.0) < EPSILON);
}

TEST(ShapeTestSuite, RayIntersectsSphereTangent){
    Point testOrigin = Point(0.0, 1.0, -5.0);
    Vector testDirection = Vector(0.0, 0.0, 1.0);
    Ray testRay = Ray(testOrigin, testDirection);
    // unit sphere
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    std::vector<float> resultIntersects = testSphere.intersect(testRay);
    EXPECT_EQ(resultIntersects.size(), 2);
    EXPECT_TRUE(std::abs(resultIntersects[0] - 5.0) < EPSILON);
    EXPECT_TRUE(std::abs(resultIntersects[1] - 5.0) < EPSILON);
    // test that intersects are equal
    EXPECT_TRUE(std::abs(resultIntersects[0] - resultIntersects[1]) < EPSILON);
}

TEST(ShapeTestSuite, RayNoIntersectsSphere){
    Point testOrigin = Point(0.0, 2.0, -5.0);
    Vector testDirection = Vector(0.0, 0.0, 1.0);
    Ray testRay = Ray(testOrigin, testDirection);
    // unit sphere
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    std::vector<float> resultIntersects = testSphere.intersect(testRay);
    EXPECT_EQ(resultIntersects.size(), 0);
}

TEST(ShapeTestSuite, InternalRayIntersectsSphere){
    // ray extends behind starting point
    Point testOrigin = Point(0.0, 0.0, 0.0);
    Vector testDirection = Vector(0.0, 0.0, 1.0);
    Ray testRay = Ray(testOrigin, testDirection);
    // unit sphere
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    std::vector<float> resultIntersects = testSphere.intersect(testRay);
    EXPECT_EQ(resultIntersects.size(), 2);
    EXPECT_TRUE(std::abs(resultIntersects[0] - -1.0) < EPSILON);
    EXPECT_TRUE(std::abs(resultIntersects[1] - 1.0) < EPSILON);
}

TEST(ShapeTestSuite, SphereBehindRay){
    // ray extends behind starting point
    Point testOrigin = Point(0.0, 0.0, 5.0);
    Vector testDirection = Vector(0.0, 0.0, 1.0);
    Ray testRay = Ray(testOrigin, testDirection);
    // unit sphere
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    std::vector<float> resultIntersects = testSphere.intersect(testRay);
    EXPECT_EQ(resultIntersects.size(), 2);
    EXPECT_TRUE(std::abs(resultIntersects[0] - -6.0) < EPSILON);
    EXPECT_TRUE(std::abs(resultIntersects[1] - -4.0) < EPSILON);
}

TEST(ShapeTestSuite, SphereEquality) {
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Sphere equalSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Sphere nonEqualSphere = Sphere(Point(1.0, 0.0, 0.0), 1.0);
    EXPECT_TRUE( testSphere.equals(equalSphere));
    EXPECT_FALSE(testSphere.equals(nonEqualSphere));
    // test parent Shape operator==
    EXPECT_TRUE(testSphere == equalSphere);
    EXPECT_FALSE(testSphere == nonEqualSphere);
}