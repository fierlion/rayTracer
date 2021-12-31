//
// Created by Allan, Ray on 12/27/21.
//

#include "Color.h"

#include <cmath>
#include <iostream>


bool Color::operator==(const Color& rhs) const {
    return (std::abs(x - rhs.x) < EPSILON &&
            std::abs(y - rhs.y) < EPSILON &&
            std::abs(z - rhs.z) < EPSILON);
}

bool Color::operator!=(const Color& rhs) const {
    return !(this->operator==(rhs));
}

// Adding A Vector to a Point returns a Point
Color Color::operator+(const Color& rhs) {
    return Color((x + rhs.getRed()), (y + rhs.getGreen()), (z + rhs.getBlue()));
}

Color Color::operator-(const Color& rhs) {
    return Color((x - rhs.getRed()), (y - rhs.getGreen()), (z - rhs.getBlue()));
}

Color Color::operator*(const Color& rhs) {
    return Color((x * rhs.getRed()), (y * rhs.getGreen()), (z * rhs.getBlue()));
}

Color Color::operator*(const float scalar) {
    return Color((x * scalar), (y * scalar), (z * scalar));
}



// this could also be an alias to the unary * operator, `Color::operator*(const Color& rhs)`
Color Color::hadamardProduct(const Color &rhs) {
    return Color((x * rhs.getRed()), (y * rhs.getGreen()), (z * rhs.getBlue()));
}

// helper to scale a float from 0.0 - 1.0 to 0 - 255
int rescaleToInt(float colorIn) {
    if (colorIn < 0.0) {
        return 0;
    } else if (colorIn > 1.0) {
        return 255;
    } else {
        return roundf(255.0 * colorIn);
    }
}

std::string Color::toScaledString() {
    std::string redString = std::to_string(rescaleToInt(x));
    std::string greenString = std::to_string(rescaleToInt(y));
    std::string blueString = std::to_string(rescaleToInt(z));
    return (redString + " " + greenString + " " + blueString);
}

