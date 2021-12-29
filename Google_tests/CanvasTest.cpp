//
// Created by Allan, Ray on 12/28/21.
//

#include "gtest/gtest.h"
#include "../Canvas_lib/Canvas.h"
#include <iostream>

TEST(CanvasTestSuite, InitializeCanvas){
    Canvas testCanvas(10, 20);
    Color black(0.0, 0.0, 0.0);
    EXPECT_EQ(testCanvas.getHeight(), 20);
    EXPECT_EQ(testCanvas.getWidth(), 10);

    bool allBlack = true;
    for(unsigned int h = 0; h < testCanvas.getHeight(); h++) {
        for (unsigned int w = 0; w < testCanvas.getWidth(); w++) {
            if (!(testCanvas.getLocationColor(w, h) == black)) {
                allBlack = false;
            }
        }
    }
    EXPECT_EQ(allBlack, true);
}

TEST(CanvasTestSuite, SetColor) {
    Canvas testCanvas(10, 1);
    Color red(1.0, 0.0, 0.0);
    Color black(0.0, 0.0, 0.0);
    testCanvas.setLocationColor(0, 5, red);

    EXPECT_TRUE(testCanvas.getLocationColor(0,4) == black);
    EXPECT_TRUE(testCanvas.getLocationColor(0,5) == red);
    EXPECT_TRUE(testCanvas.getLocationColor(0,6) == black);
}

TEST(CanvasTestSuite, ToEmptyPPMFileString) {
    Canvas testCanvas(0, 0);
    std::string emptyResult = testCanvas.canvasToPpm();
    std::string expectedEmptyResult = "P3\n0 0\n255\n";
    EXPECT_EQ(expectedEmptyResult, emptyResult);
}

TEST(CanvasTestSuite, ToPPMFileString) {
    Canvas testCanvas(2, 2);
    Color red(1.0, 0.0, 0.0);
    Color green(0.0, 1.0, 0.0);
    Color blue(0.0, 0.0, 1.0);
    testCanvas.setLocationColor(0, 1, red);
    testCanvas.setLocationColor(1, 0, green);
    testCanvas.setLocationColor(1, 1, blue);
    std::string canvasResult = testCanvas.canvasToPpm();
    std::string expectedCanvasResult = "P3\n2 2\n255\n0 0 0 255 0 0 0 255 0 0 0 255\n";
    EXPECT_EQ(expectedCanvasResult, canvasResult);
}