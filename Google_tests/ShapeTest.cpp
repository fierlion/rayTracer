//
// Created by Allan, Ray on 1/1/22.
//

#include "gtest/gtest.h"
#include "../Shape_lib/Shape.h"
#include "../Shape_lib/Sphere.h"
#include "../Ray_lib/Ray.h"

#include <vector>


TEST(SphereTestSuite, RayIntersectsSphereTwoPoints){
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

TEST(SphereTestSuite, RayIntersectsSphereTangent){
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

TEST(SphereTestSuite, RayNoIntersectsSphere){
    Point testOrigin = Point(0.0, 2.0, -5.0);
    Vector testDirection = Vector(0.0, 0.0, 1.0);
    Ray testRay = Ray(testOrigin, testDirection);
    // unit sphere
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    std::vector<float> resultIntersects = testSphere.intersect(testRay);
    EXPECT_EQ(resultIntersects.size(), 0);
}

TEST(SphereTestSuite, InternalRayIntersectsSphere){
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

TEST(SphereTestSuite, SphereBehindRay){
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