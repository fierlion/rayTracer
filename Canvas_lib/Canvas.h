//
// Created by Allan, Ray on 12/28/21.
//

#ifndef GOOGLE_TESTS_CANVAS_H
#define GOOGLE_TESTS_CANVAS_H

#define PPM_MAX_LINE_CHARS 70

#include "../Tuples_lib/Color.h"

#include <vector>


class Canvas {
private:
    std::vector<std::vector<Color> > canvas;
    unsigned int height;
    unsigned int width;
    Color background;
public:
    // background default to black
    Canvas() {
        this->background = Color::black();
    };
    Canvas(unsigned int widthIn, unsigned int heightIn){
        this->height = heightIn;
        this->width = widthIn;
        this->background = Color::black();
        for (unsigned int i=0; i<heightIn; i++) {
            // default to all black canvas
            this->canvas.push_back(std::vector<Color>(widthIn, this->background));
        }
    };
    Canvas(unsigned int widthIn, unsigned int heightIn, Color backgroundIn){
        this->height = heightIn;
        this->width = widthIn;
        this->background = backgroundIn;
        for (unsigned int i=0; i<heightIn; i++) {
            // default to all black canvas
            this->canvas.push_back(std::vector<Color>(widthIn, this->background));
        }
    };
    void displayCanvasContents();
    unsigned int getHeight() {return this->height;}
    unsigned int getWidth() {return this->width;}
    Color getLocationColor(unsigned int x, unsigned int y) {return this->canvas[y][x];}
    // Color location is zero-based from the top down
    void setLocationColor(unsigned int x, unsigned int y, Color colorIn);
    std::string canvasToPpm();
};

#endif //GOOGLE_TESTS_CANVAS_H
