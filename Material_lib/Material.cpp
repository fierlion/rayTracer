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
    Vector lightVector = lightIn.getPosition() - positionIn;
    Vector normalizedLightVector = lightVector.normalize();
    Color ambientColor = effectiveColor * this->getAmbient();
    Color specularColor = Color();
    Color diffuseColor = Color();
    float lightDotNormal = normalizedLightVector.dotProduct(normalVector);
    if (lightDotNormal < 0.0) {
        diffuseColor = Color::black();
        specularColor = Color::black();
    } else {
        diffuseColor = effectiveColor * this->getDiffuse() * lightDotNormal;
        Vector negativeLightVector = -normalizedLightVector;
        Vector reflectVector = negativeLightVector.reflect(normalVector);
        float reflectDotEye = reflectVector.dotProduct(eyeVector);
        //TODO there's a bug here that's messing with the reflection
        //if (reflectDotEye <= 0.0) {
        //    specularColor = Color::black();
        //} else {
            float factor = pow(reflectDotEye, this->getShininess());
            specularColor = lightIn.getIntensity() * this->getSpecular() * factor;
        //}
    }
    std::cout << "final diffuseColor: " << diffuseColor.toString() << std::endl;
    return ambientColor + specularColor + diffuseColor;
}