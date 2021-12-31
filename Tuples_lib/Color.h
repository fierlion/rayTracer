//
// Created by Allan, Ray on 12/27/21.
//

#ifndef RAYTRACER_COLOR_H
#define RAYTRACER_COLOR_H

#include "Tuple.h"

#include <iostream>


class Color : public Tuple {
public:
    Color(){
        w = COLOR_FLOAT;
    };
    Color(float red, float green, float blue) {
        x = red;
        y = green;
        z = blue;
        w = COLOR_FLOAT;
    }

    float getRed() const {return x;}
    float getGreen() const {return y;}
    float getBlue() const {return z;}

    bool operator==(const Color& rhs) const;
    bool operator!=(const Color& rhs) const;
    Color operator+(const Color& rhs);
    Color operator-(const Color& rhs);
    Color operator*(const Color& rhs);
    Color operator*(float scalar);

    Color hadamardProduct(const Color& rhs);
    std::string toScaledString();
};


#endif //RAYTRACER_COLOR_H