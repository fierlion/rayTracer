//
// Created by Allan, Ray on 12/28/21.
//

#include "Canvas.h"
#include <iostream>

void Canvas::displayCanvasContents() {
    for(unsigned int i = 0; i < height; i++) {
        for (unsigned int j = 0; j < width; j++) {
            std::cout << canvas[i][j].getBlue() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}