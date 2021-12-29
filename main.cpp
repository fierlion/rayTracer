#include <iostream>
#include <fstream>
#include "Tuples_lib/Point.h"
#include "Tuples_lib/Point.cpp"
#include "Tuples_lib/Vector.h"
#include "Tuples_lib/Vector.cpp"
#include "Canvas_lib/Canvas.h"
#include "Canvas_lib/Canvas.cpp"

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
    Canvas mainCanvas = Canvas(900, 550);
    Color red = Color(1.0, 0.0, 0.0);
    while (mainProjectile.getPoint().getY() > 0.0) {
        Point thisPoint = mainProjectile.getPoint();
        std::cout << "x: " << thisPoint.getX() << " y: " << thisPoint.getY() << " z: " << thisPoint.getZ() << std::endl;
        // cast to int uses floor -- add 0.5 to round to nearest int
        int canvasX = int(thisPoint.getX() + 0.5);
        // canvas Y is inverted -- subtract it from canvas height
        int canvasY = mainCanvas.getHeight() - int(thisPoint.getY() + 0.5);
        mainCanvas.setLocationColor(canvasX, canvasY, red);
        mainProjectile = tick(mainEnvironment, mainProjectile);
    }
    std::string fileOutput = mainCanvas.canvasToPpm();
    // write out to file
    std::string filename("tmp.ppm");
    std::fstream file_out;
    file_out.open(filename, std::ios_base::out);
    if (!file_out.is_open()) {
        std::cout << "failed to open " << filename << '\n';
    } else {
        file_out << fileOutput;
        std::cout << "Done Writing!" << std::endl;
    }

    return 0;
}

