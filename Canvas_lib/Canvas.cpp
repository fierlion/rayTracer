//
// Created by Allan, Ray on 12/28/21.
//

#include "Canvas.h"
#include <cmath>
#include <iostream>
#include <numeric>

void Canvas::displayCanvasContents() {
    for(unsigned int h = 0; h < height; h++) {
        for (unsigned int w = 0; w < width; w++) {
            std::cout << canvas[h][w].getRed() << ":" << canvas[h][w].getGreen() << ":" << canvas[h][w].getBlue() << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

std::string Canvas::canvasToPpm() {
    std::string ppmString = "P3\n"+ std::to_string(width) + " " + std::to_string(height) + "\n255\n";
    unsigned int lineLen = 0;

    for(unsigned int h = 0; h < height; h++) {
        for (unsigned int w = 0; w < width; w++) {
            Color thisColor = canvas[h][w];
            std::string rescaledString = thisColor.toScaledString();
            if (lineLen + rescaledString.length()  >= PPM_MAX_LINE_CHARS) {
                ppmString.append("\n" + rescaledString + " ");
                lineLen = rescaledString.length() + 1;
            } else {
                ppmString.append(rescaledString + " ");
                lineLen += rescaledString.length() + 1;
            }
        }
    }
    return ppmString.replace(ppmString.end()-1, ppmString.end(), "\n");
}