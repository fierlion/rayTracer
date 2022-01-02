//
// Created by Allan, Ray on 1/1/22.
//

#include "gtest/gtest.h"
#include "../Intersection_lib/Intersection.h"
#include "../Shape_lib/Shape.h"
#include "../Shape_lib/Sphere.h"


//TODO compare child and parent object for equality (Shape == Sphere)
TEST(IntersectionTestSuite, IntersectionEncapsulatesObjectAndT){
    Sphere testSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Intersection testIntersection(3.5, testSphere);
    Shape resultShape = testIntersection.getShape();
    Shape *spherePointer = (Sphere *) &resultShape;
    std::cout << spherePointer->getCenter().toString() << " " << std::endl;
    EXPECT_TRUE(std::abs(testIntersection.getTValue() - 3.5) < EPSILON);
}


