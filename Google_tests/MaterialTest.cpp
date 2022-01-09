//
// Created by Allan, Ray on 1/8/22.
//

#include "gtest/gtest.h"
#include "../Tuples_lib/Point.h"
#include "../Tuples_lib/Color.h"
#include "../Material_lib/Material.h"
#include "../Light/Light.h"

#include <math.H>


TEST(MaterialTestSuite, ExampleMaterial){
    Material testDefaultMaterial = Material();
    Color expectedDefaultColor = Color(1.0, 1.0, 1.0);

    EXPECT_TRUE(expectedDefaultColor == testDefaultMaterial.getMaterialColor());
    EXPECT_TRUE(abs(testDefaultMaterial.getAmbient() - 0.1) < EPSILON);
    EXPECT_TRUE(abs(testDefaultMaterial.getDiffuse() - 0.9) < EPSILON);
    EXPECT_TRUE(abs(testDefaultMaterial.getSpecular() - 0.9) < EPSILON);
    EXPECT_TRUE(abs(testDefaultMaterial.getShininess() - 200.0) < EPSILON);
}

TEST(MaterialTestSuite, LightingEyeBetweenLightAndSurface) {
    Material testMaterial = Material();
    Point testPosition = Point(0.0, 0.0, 0.0);
    Vector testEyeVector = Vector(0.0, 0.0, -1.0);
    Vector normalVector = Vector(0.0, 0.0, -1.0);
    Color initialColor = Color(1.0, 1.0, 1.0);
    Light pointLight = Light(Point(0.0, 0.0, -10.0), initialColor);
    Color expectedColor = Color(1.9, 1.9, 1.9);
    Color resultColor = testMaterial.lighting(pointLight, testPosition, testEyeVector, normalVector);
    EXPECT_TRUE(expectedColor == resultColor);
}

TEST(MaterialTestSuite, LightingEyeBetweenLightAndSurfaceOffset45) {
    Material testMaterial = Material();
    Point testPosition = Point(0.0, 0.0, 0.0);
    Vector testEyeVector = Vector(0.0, sqrt(2)/2, -(sqrt(2))/2);
    Vector normalVector = Vector(0.0, 0.0, -1.0);
    Color initialColor = Color(1.0, 1.0, 1.0);
    Light pointLight = Light(Point(0.0, 0.0, -10.0), initialColor);
    Color expectedColor = Color(1.0, 1.0, 1.0);
    Color resultColor = testMaterial.lighting(pointLight, testPosition, testEyeVector, normalVector);
    EXPECT_TRUE(expectedColor == resultColor);
}

TEST(MaterialTestSuite, LightingEyeOppositeLightAndSurfaceOffset45) {
    Material testMaterial = Material();
    Point testEyePosition = Point(0.0, 0.0, 0.0);
    Vector testEyeVector = Vector(0.0, 0.0, -1.0);
    Vector normalVector = Vector(0.0, 0.0, -1.0);
    Color initialColor = Color(1.0, 1.0, 1.0);
    Light pointLight = Light(Point(0.0, 10.0, -10.0), initialColor);
    Color expectedColor = Color(0.7364, 0.7364, 0.7364);
    Color resultColor = testMaterial.lighting(pointLight, testEyePosition, testEyeVector, normalVector);
    EXPECT_TRUE(expectedColor == resultColor);
}

TEST(MaterialTestSuite, LightingEyeInReflectionVectorPath) {
    Material testMaterial = Material();
    Point testEyePosition = Point(0.0, 0.0, 0.0);
    Vector testEyeVector = Vector(0.0, -(sqrt(2))/2, -(sqrt(2))/2);
    Vector normalVector = Vector(0.0, 0.0, -1.0);
    Color initialColor = Color(1.0, 1.0, 1.0);
    Light pointLight = Light(Point(0.0, 10.0, -10.0), initialColor);
    Color expectedColor = Color(1.6364, 1.6364, 1.6364);
    Color resultColor = testMaterial.lighting(pointLight, testEyePosition, testEyeVector, normalVector);
    EXPECT_TRUE(expectedColor == resultColor);
}

TEST(MaterialTestSuite, LightingSourceBehindSurface) {
    Material testMaterial = Material();
    Point testEyePosition = Point(0.0, 0.0, 0.0);
    Vector testEyeVector = Vector(0.0, 0.0, -1.0);
    Vector normalVector = Vector(0.0, 0.0, -1.0);
    Color initialColor = Color(1.0, 1.0, 1.0);
    Light pointLight = Light(Point(0.0, 0.0, 10.0), initialColor);
    Color expectedColor = Color(0.1, 0.1, 0.1);
    Color resultColor = testMaterial.lighting(pointLight, testEyePosition, testEyeVector, normalVector);
    EXPECT_TRUE(expectedColor == resultColor);
}