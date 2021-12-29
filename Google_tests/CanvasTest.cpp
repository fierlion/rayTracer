//
// Created by Allan, Ray on 12/28/21.
//

#include "gtest/gtest.h"
#include "../Canvas_lib/Canvas.h"

TEST(CanvasTestSuite, InitializeCanvas){
    Canvas testCanvas(10, 20);
    Color black(0.0, 0.0, 0.0);
    EXPECT_EQ(testCanvas.getHeight(), 20);
    EXPECT_EQ(testCanvas.getWidth(), 10);

    bool allBlack = true;
    for(unsigned int i = 0; i < testCanvas.getHeight(); i++) {
        for (unsigned int j = 0; j < testCanvas.getWidth(); j++) {

            if (!(testCanvas.getLocationColor(j, i) == black)) {
                allBlack = false;
            }
        }
    }
    EXPECT_EQ(allBlack, true);
}
