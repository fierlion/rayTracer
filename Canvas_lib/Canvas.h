//
// Created by Allan, Ray on 12/28/21.
//

#ifndef GOOGLE_TESTS_CANVAS_H
#define GOOGLE_TESTS_CANVAS_H

#define PPM_MAX_LINE_CHARS 70

#include "../Tuples_lib/Color.h"

#include <vector>


class Canvas {
public:
    Canvas() {}
    Canvas(unsigned int widthIn, unsigned int heightIn) {
        height = heightIn;
        width = widthIn;
        for (unsigned int i=0; i<heightIn; i++) {
            // default to all black canvas
            Color black = Color::black();
            canvas.push_back(std::vector<Color>(widthIn, black));
        }
    }
    void displayCanvasContents();
    unsigned int getHeight() {return height;}
    unsigned int getWidth() {return width;}
    Color getLocationColor(unsigned int x, unsigned int y) {return canvas[y][x];}
    // Color location is zero-based from the top down
    void setLocationColor(unsigned int x, unsigned int y, Color colorIn);
    std::string canvasToPpm();
private:
    std::vector<std::vector<Color> > canvas;
    unsigned int height;
    unsigned int width;
};

#endif //GOOGLE_TESTS_CANVAS_H
