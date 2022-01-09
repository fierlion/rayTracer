#include "Tuples_lib/Tuple.h"
#include "Tuples_lib/Tuple.cpp"
#include "Tuples_lib/Point.h"
#include "Tuples_lib/Point.cpp"
#include "Tuples_lib/Vector.h"
#include "Tuples_lib/Vector.cpp"
#include "Tuples_lib/Color.h"
#include "Tuples_lib/Color.cpp"
#include "Canvas_lib/Canvas.h"
#include "Canvas_lib/Canvas.cpp"
#include "Matrix_lib/Matrix.h"
#include "Matrix_lib/Matrix.cpp"
#include "Matrix_lib/Transform.h"
#include "Matrix_lib/Transform.cpp"
#include "Ray_lib/Ray.h"
#include "Ray_lib/Ray.cpp"
#include "Shape_lib/Shape.h"
#include "Shape_lib/Shape.cpp"
#include "Shape_lib/Sphere.h"
#include "Shape_lib/Sphere.cpp"
#include "Intersection_lib/Intersection.h"
#include "Intersection_lib/Intersection.cpp"

#include <fstream>
#include <iostream>

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

void writePPMToFile(Canvas canvasIn, std::string fileName) {
    std::string fileOutput = canvasIn.canvasToPpm();
    // write out to file
    std::fstream file_out;
    file_out.open(fileName, std::ios_base::out);
    if (!file_out.is_open()) {
        std::cout << "failed to open " << fileName << '\n';
    } else {
        file_out << fileOutput;
        std::cout << "Done Writing!" << std::endl;
    }
}

int main()
{
    // projectile starts at a unit above origin
    Vector normalizedStart = Vector(1.0, 1.8, 0.0).normalize() * 11.25;
    Projectile arcProjectile = Projectile(Point(0.0, 1.0, 0.0), normalizedStart);
    Environment arcEnvironment = Environment(Vector(0.0, -0.1, 0.0), Vector(-0.01, 0.0, 0.0));
    Canvas arcCanvas = Canvas(900, 550);
    Color red = Color::red();
    while (arcProjectile.getPoint().getY() > 0.0) {
        Point thisPoint = arcProjectile.getPoint();
        // cast to int uses floor -- add 0.5 to round to the nearest int
        int canvasX = int(thisPoint.getX() + 0.5);
        // canvas Y is inverted -- subtract it from canvas height
        int canvasY = arcCanvas.getHeight() - int(thisPoint.getY() + 0.5);
        arcCanvas.setLocationColor(canvasX, canvasY, red);
        arcProjectile = tick(arcEnvironment, arcProjectile);
    }
    writePPMToFile(arcCanvas, "arc.ppm");

    // generate clock with transformations
    Canvas clockCanvas = Canvas(500, 500);
    double pi = std::atan(1)*4;
    Color yellow = Color::yellow();
    Point origin = Point(0.0, 0.0, 0.0);
    Point noon = Point(0.0, 0.0, 1.0);

    Transform canvasCenter = Transform::translate(clockCanvas.getWidth()/2.0, clockCanvas.getHeight()/2.0, clockCanvas.getHeight()/2.0);
    Transform clockScale = Transform::scale((500 * 3.0)/8.0, (500 * 3.0)/8.0, (500 * 3.0)/8.0);
    Point centerPoint = canvasCenter * clockScale * origin;

    int canvasX = int(centerPoint.getX() + 0.5);
    int canvasY = clockCanvas.getHeight() - int(centerPoint.getZ() + 0.5);
    clockCanvas.setLocationColor(canvasX, canvasY, yellow);

    Point noonPoint = canvasCenter * clockScale * noon;
    int noonX = int(noonPoint.getX() + 0.5);
    int noonY = clockCanvas.getHeight() - int(noonPoint.getZ() + 0.5);
    std::cout << std::to_string(noonX) << " " << std::to_string(noonY) << std::endl;
    clockCanvas.setLocationColor(noonX, noonY, yellow);

    for (unsigned int i = 0; i < 12; i++) {
        Transform rotation = Transform::rotateY(i * pi/6.0);
        Point thisPoint = canvasCenter * clockScale * rotation * noon;
        int thisX = int(thisPoint.getX() + 0.5);
        int thisY = clockCanvas.getHeight() - int(thisPoint.getZ() + 0.5);
        std::cout << std::to_string(thisX) << " " << std::to_string(thisY) << std::endl;
        clockCanvas.setLocationColor(thisX, thisY, yellow);
    }

    writePPMToFile(clockCanvas, "clock.ppm");

    // generate ray-traced shadow
    Point rayOrigin = Point(0.0, 0.0, -5.0);
    float wallZ = 10.0;
    float wallSize = 7.0;
    float canvasPixels = 500.0;
    float pixelSize = wallSize / canvasPixels;
    float halfWall = wallSize / 2.0;
    Canvas shadowCanvas = Canvas(canvasPixels, canvasPixels, Color::blue());
    Sphere unitSphere = Sphere(Point(0.0, 0.0, 0.0), 1.0);
    Transform translation = Transform::translate(2.25, 0.0, 0.0);
    Transform scale = Transform::scale(0.5, 0.5, 0.5);
    unitSphere.setTransform(translation * scale);
    for (unsigned int y = 0; y < canvasPixels; y++) {
        float worldY = halfWall - pixelSize * y;
        for (unsigned int x = 0; x < canvasPixels; x++) {
            float worldX = halfWall + pixelSize * x;
            Point currentPosition = Point(worldX, worldY, wallZ);
            Vector rayVector = currentPosition - rayOrigin;
            Vector normalizedVector = rayVector.normalize();
            Ray currentRay = Ray(rayOrigin, normalizedVector);
            std::vector<Intersection> resultIntersections = Intersection::intersect(unitSphere, currentRay);
            Intersection hitIntersection = Intersection::getVisibleHit(resultIntersections);
            if (hitIntersection.getTValue() != std::numeric_limits<float>::min()) {
                shadowCanvas.setLocationColor(x, y, Color::black());
            }
        }
    }
    writePPMToFile(shadowCanvas, "shadow.ppm");

    return 0;
}
