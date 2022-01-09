//
// Created by Allan, Ray on 1/1/22.
//

#ifndef GOOGLE_TESTS_RAY_H
#define GOOGLE_TESTS_RAY_H

#include "../Tuples_lib/Point.h"
#include "../Tuples_lib/Vector.h"
#include "../Matrix/Matrix.h"

class Ray {
private:
    Point origin;
    Vector direction;
public:
    Ray() {};
    Ray(Point originIn, Vector directionIn) {
        origin = originIn;
        direction = directionIn;
    };
    Point getOrigin() {return this->origin;}
    Vector getDirection() {return this->direction;}
    Point position(float time);
    Ray transform(Matrix transformMatrix);
};

#endif //GOOGLE_TESTS_RAY_H
