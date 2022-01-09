//
// Created by Allan, Ray on 1/1/22.
//

#include "gtest/gtest.h"
#include "../Shape_lib/Shape.h"
#include "../Shape_lib/Sphere.h"
#include "../Ray_lib/Ray.h"
#include "../Matrix_lib/Transform.h"

#include <vector>
#include <math.h>


TEST(ShapeTestSuite, RayIntersectsSphereTwoPoints){
    Point testOrigin = Point(0.0, 0.0, -5.0);
    Vector testDirection = Vector(0.0, 0.0, 1.0);
    Ray testRay = Ray(testOrigin, testDirection);
    // unit sphere
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    std::vector<float> resultIntersects = testSphere.getRayIntersects(testRay);
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
    std::vector<float> resultIntersects = testSphere.getRayIntersects(testRay);
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
    std::vector<float> resultIntersects = testSphere.getRayIntersects(testRay);
    EXPECT_EQ(resultIntersects.size(), 0);
}

TEST(ShapeTestSuite, InternalRayIntersectsSphere){
    // ray extends behind starting point
    Point testOrigin = Point(0.0, 0.0, 0.0);
    Vector testDirection = Vector(0.0, 0.0, 1.0);
    Ray testRay = Ray(testOrigin, testDirection);
    // unit sphere
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    std::vector<float> resultIntersects = testSphere.getRayIntersects(testRay);
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
    std::vector<float> resultIntersects = testSphere.getRayIntersects(testRay);
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

TEST(ShapeTestSuite, SphereDefaultTransformation) {
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Matrix resultTransform = testSphere.getTransform();
    EXPECT_TRUE(resultTransform == Matrix::identityMatrix());
}

TEST(ShapeTestSuite, SphereUpdateTransformation) {
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Matrix translation = Transform::scale(2.0, 3.0, 4.0);
    testSphere.setTransform(translation);
    Matrix resultTransform = testSphere.getTransform();
    EXPECT_TRUE(resultTransform == translation);
}

TEST(ShapeTestSuite, IntersectScaledSphereWithRay) {
    Point testOrigin = Point(0.0, 0.0, -5.0);
    Vector testDirection = Vector(0.0, 0.0, 1.0);
    Ray testRay = Ray(testOrigin, testDirection);
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Matrix scaling = Transform::scale(2.0, 2.0, 2.0);
    testSphere.setTransform(scaling);
    std::vector<float> resultIntersects = testSphere.getRayIntersects(testRay);
    EXPECT_EQ(resultIntersects.size(), 2);
    EXPECT_TRUE(std::abs(resultIntersects[0] - 3.0) < EPSILON);
    EXPECT_TRUE(std::abs(resultIntersects[1] - 7.0) < EPSILON);
}

TEST(ShapeTestSuite, IntersectTranslatedSphereWithRay) {
    Point testOrigin = Point(0.0, 0.0, -5.0);
    Vector testDirection = Vector(0.0, 0.0, 1.0);
    Ray testRay = Ray(testOrigin, testDirection);
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Matrix translation = Transform::translate(5.0, 0.0, 0.0);
    testSphere.setTransform(translation);
    std::vector<float> resultIntersects = testSphere.getRayIntersects(testRay);
    EXPECT_EQ(resultIntersects.size(), 0);
}

TEST(ShapeTestSuite, SphereNormalAtXAxisPoint) {
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Vector expectedVector = Vector(1.0, 0.0, 0.0);
    Vector resultVector = testSphere.normalAt(Point(1.0, 0.0, 0.0));
    EXPECT_TRUE(expectedVector == resultVector);
}

TEST(ShapeTestSuite, SphereNormalAtYAxisPoint) {
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Vector expectedVector = Vector(0.0, 1.0, 0.0);
    Vector resultVector = testSphere.normalAt(Point(0.0, 1.0, 0.0));
    EXPECT_TRUE(expectedVector == resultVector);
}

TEST(ShapeTestSuite, SphereNormalAtZAxisPoint) {
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Vector expectedVector = Vector(0.0, 0.0, 1.0);
    Vector resultVector = testSphere.normalAt(Point(0.0, 0.0, 1.0));
    EXPECT_TRUE(expectedVector == resultVector);
}

TEST(ShapeTestSuite, SphereNormalAtNonAxisPoint) {
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    float sqrtThreeByThree = sqrt(3.0) / 3.0;
    Vector expectedVector = Vector(sqrtThreeByThree, sqrtThreeByThree, sqrtThreeByThree);
    Vector resultVector = testSphere.normalAt(Point(sqrtThreeByThree, sqrtThreeByThree, sqrtThreeByThree));
    EXPECT_TRUE(expectedVector == resultVector);
}

TEST(ShapeTestSuite, NormalIsNormalizedVector) {
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    float sqrtThreeByThree = sqrt(3.0) / 3.0;
    Vector resultVector = testSphere.normalAt(Point(sqrtThreeByThree, sqrtThreeByThree, sqrtThreeByThree));
    EXPECT_TRUE(resultVector.normalize() == resultVector);
}

TEST(ShapeTestSuite, NormalOnTranslatedSphere) {
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Transform translation = Transform::translate(0.0, 1.0, 0.0);
    testSphere.setTransform(translation);
    Vector expectedVector = Vector(0.0, 0.70711, -0.70711);
    Vector resultVector = testSphere.normalAt(Point(0.0, 1.70711, -0.70711));
    EXPECT_TRUE(expectedVector == resultVector);
}

TEST(ShapeTestSuite, NormalOnTransrofmedSphere) {
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Transform scaling = Transform::scale(1.0, 0.5, 1.0);
    testSphere.setTransform(scaling);
    Vector expectedVector = Vector(0.0, 0.97014, -0.24254);
    Vector resultVector = testSphere.normalAt(Point(0.0, sqrt(2.0)/2, -(sqrt(2)/2)));
    EXPECT_TRUE(expectedVector == resultVector);
}