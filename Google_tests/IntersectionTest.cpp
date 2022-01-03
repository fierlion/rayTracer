//
// Created by Allan, Ray on 1/1/22.
//

#include "gtest/gtest.h"
#include "../Intersection_lib/Intersection.h"
#include "../Shape_lib/Shape.h"
#include "../Shape_lib/Sphere.h"


TEST(IntersectionTestSuite, IntersectionEncapsulatesObjectAndT){
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Intersection testIntersection(3.5, &testSphere);
    Shape* resultShape = testIntersection.getShape();
    Shape *spherePointer = (Sphere *) &resultShape;
    EXPECT_TRUE(std::abs(testIntersection.getTValue() - 3.5) < EPSILON);
}

TEST(IntersectionTestSuite, IntersectionEncapsulation) {
    Point testOrigin = Point(0.0, 0.0, 5.0);
    Vector testDirection = Vector(0.0, 0.0, 1.0);
    Ray testRay = Ray(testOrigin, testDirection);
    // unit sphere
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    std::vector<Intersection> resultIntersections = Intersection::intersect(testSphere, testRay);
    EXPECT_EQ(resultIntersections.size(), 2);
    EXPECT_TRUE(std::abs(resultIntersections[0].getTValue() - -6.0) < EPSILON);
    EXPECT_TRUE(std::abs(resultIntersections[1].getTValue() - -4.0) < EPSILON);
}

TEST(IntersectionTestSuite, IntersectionEquality) {
    Sphere testSphereA = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Sphere testSphereB = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Sphere testSphereC = Sphere(Point(0.0, 0.0, 0.0), 2.0);
    Intersection testIntersectionA = Intersection(1.0, &testSphereA);
    Intersection testIntersectionB = Intersection(1.0, &testSphereB);
    Intersection testIntersectionC = Intersection(2.0, &testSphereC);
    EXPECT_TRUE(testIntersectionA == testIntersectionB);
    EXPECT_FALSE(testIntersectionA == testIntersectionC);
}

TEST(IntersectionTestSuite, GetVisibleHits) {
    Sphere testSphere = Sphere();
    Intersection testIntersectionA = Intersection(1.0, &testSphere);
    Intersection testIntersectionB = Intersection(2.0, &testSphere);
    std::vector<Intersection> testIntersections;
    testIntersections.push_back(testIntersectionA);
    testIntersections.push_back(testIntersectionB);
    Intersection resultIntersection = Intersection::getVisibleHit(testIntersections);
    std::cout << std::to_string(resultIntersection.getTValue()) << std::endl;
}