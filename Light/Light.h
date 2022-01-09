//
// Created by Allan, Ray on 1/8/22.
//

#ifndef GOOGLE_TESTS_LIGHT_H
#define GOOGLE_TESTS_LIGHT_H

#include "../Tuples_lib/Point.h"
#include "../Tuples_lib/Color.h"


class Light {
private:
    Point position;
    Color intensity;
public:
    Light() {};
    Light(Point positionIn, Color intensityIn) {
        this->position = positionIn;
        this->intensity = intensityIn;
    };
    Point getPosition() {return this->position;}
    Color getIntensity() {return this->intensity;}
};


#endif //GOOGLE_TESTS_LIGHT_H
