//
// Created by Allan, Ray on 12/28/21.
//

#ifndef GOOGLE_TESTS_CANVAS_H
#define GOOGLE_TESTS_CANVAS_H

#include "../Tuples_lib/Color.h"
#include <vector>

class Canvas {
public:
    Canvas() {}
    Canvas(unsigned int widthIn, unsigned int heightIn) {
        height = heightIn;
        width = widthIn;
        for (unsigned int i=0; i<heightIn; i++) {
            // fill with black color (0, 0, 0)
            canvas.push_back(std::vector<Color>(widthIn, Color(0.0, 0.0, 0.0)));
        }
    }
    void displayCanvasContents();
    unsigned int getHeight() {return height;}
    unsigned int getWidth() {return width;}
    Color getLocationColor(unsigned int x, unsigned int y) {return canvas[y][x];}
private:
    std::vector<std::vector<Color> > canvas;
    unsigned int height;
    unsigned int width;
};

#endif //GOOGLE_TESTS_CANVAS_H
