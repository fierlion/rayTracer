//
// Created by Allan, Ray on 12/27/21.
//

#include "Color.h"

// Adding A Vector to a Point returns a Point
Color Color::operator+(const Color& rhs) {
    return Color((x + rhs.getRed()), (y + rhs.getGreen()), (z + rhs.getBlue()));
}

Color Color::operator-(const Color& rhs) {
    return Color((x - rhs.getRed()), (y - rhs.getGreen()), (z - rhs.getBlue()));
}

Color Color::operator*(const float scalar) {
    return Color((x * scalar), (y * scalar), (z * scalar));
}

Color Color::operator*(const Color& rhs) {
    return Color((x * rhs.getRed()), (y * rhs.getGreen()), (z * rhs.getBlue()));
}

// this could also be an alias to Color Color::operator*(const Color& rhs)
Color Color::hadamardProduct(const Color &rhs) {
    return Color((x * rhs.getRed()), (y * rhs.getGreen()), (z * rhs.getBlue()));
}
