//
// Created by Allan, Ray on 1/8/22.
//

#include "gtest/gtest.h"
#include "../Light/Light.h"


TEST(LightTestSuite, ExampleLight){
    Point testPosition = Point(0.0, 0.0, 0.0);
    Color testIntensity = Color(1.0, 1.0, 1.0);
    Light testPointLight = Light(testPosition, testIntensity);

    EXPECT_TRUE(testPointLight.getPosition() == testPosition);
    EXPECT_TRUE(testPointLight.getIntensity() == testIntensity);
}