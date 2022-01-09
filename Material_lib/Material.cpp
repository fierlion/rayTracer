//
// Created by Allan, Ray on 1/8/22.
//

#include "Material.h"

#include <math.h>

bool Material::operator==(Material& rhs) {
    return (this->getMaterialColor() == rhs.getMaterialColor() &&
            std::abs(this->getAmbient() - rhs.getAmbient()) < EPSILON &&
            std::abs(this->getDiffuse() - rhs.getDiffuse()) < EPSILON &&
            std::abs(this->getSpecular() - rhs.getSpecular()) < EPSILON &&
            std::abs(this->getShininess() - rhs.getShininess()) < EPSILON);
}

Color Material::lighting(Light lightIn, Point positionIn, Vector eyeVector, Vector normalVector) {
    Color effectiveColor = this->getMaterialColor() * lightIn.getIntensity();
    Vector lightVector = (lightIn.getPosition() - positionIn).normalize();
    Color ambientColor = effectiveColor * this->getAmbient();
    Color specularColor = Color();
    Color diffuseColor = Color();
    float lightDotNormal = lightVector.dotProduct(normalVector);
    if (lightDotNormal < 0.0) {
        diffuseColor = Color::black();
        specularColor = Color::black();
    } else {
        diffuseColor = effectiveColor * this->getDiffuse() * lightDotNormal;
        Vector reflectVector = -(lightVector.reflect(normalVector));
        float reflectDotEye = reflectVector.dotProduct(eyeVector);
        if (reflectDotEye <= 0.0) {
            specularColor = Color::black();
        } else {
            float factor = pow(reflectDotEye, this->getShininess());
            specularColor = (lightIn.getIntensity() * this->getSpecular()) * factor;
        }
    }
    std::cout << "final diffuseColor: " << diffuseColor.toString() << std::endl;
    return ambientColor + specularColor + diffuseColor;
}