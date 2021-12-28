#include <iostream>
#include "Tuples_lib/Point.h"
#include "Tuples_lib/Point.cpp"
#include "Tuples_lib/Vector.h"
#include "Tuples_lib/Vector.cpp"

class Projectile {
public:
    Point position;
    Vector velocity;
    Projectile(Point pos, Vector vel) {
        position = pos;
        velocity = vel;
    }
    Point getPoint() {return position;}
};

class Environment {
public:
    Vector gravity;
    Vector wind;
    Environment(Vector gravityIn, Vector windIn) {
        gravity = gravityIn;
        wind = windIn;
    }
};

Projectile tick(Environment env, Projectile proj) {
    Point newPosition = proj.position + proj.velocity;
    Vector newVelocity = proj.velocity + (env.gravity + env.wind);
    return Projectile(newPosition, newVelocity);
}

int main()
{
    // projectile starts at a unit above origin
    Vector normalizedStart = Vector(1.0, 1.0, 0.0).normalize();
    Projectile mainProjectile = Projectile(Point(0.0, 1.0, 0.0), normalizedStart);
    Environment mainEnvironment = Environment(Vector(0.0, -0.1, 0.0), Vector(-0.01, 0.0, 0.0));
    while (mainProjectile.getPoint().getY() > 0.0) {
        Point thisPoint = mainProjectile.getPoint();
        std::cout << "x: " << thisPoint.getX() << " y: " << thisPoint.getY() << " z: " << thisPoint.getZ() << std::endl;
        mainProjectile = tick(mainEnvironment, mainProjectile);
    }

    return 0;
}

