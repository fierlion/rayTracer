//
// Created by Allan, Ray on 1/8/22.
//

#ifndef GOOGLE_TESTS_MATERIAL_H
#define GOOGLE_TESTS_MATERIAL_H

#define EPSILON 0.0001

#include "../Tuples_lib/Color.h"
#include "../Light/Light.h"

class Material {
private:
    Color materialColor;
    float ambient;
    float diffuse;
    float specular;
    float shininess;
public:
    Material() {
        this->materialColor = Color(1.0, 1.0, 1.0);
        this->ambient = 0.1;
        this->diffuse = 0.9;
        this->specular = 0.9;
        this->shininess = 200.0;
    };
    Material(Color materialColorIn, float ambientIn, float diffuseIn, float specularIn, float shininessIn) {
        this->materialColor = materialColorIn;
        this->ambient = ambientIn;
        this->diffuse = diffuseIn;
        this->specular = specularIn;
        this->shininess = shininessIn;
    }
    Color getMaterialColor() {return this->materialColor;}
    float getAmbient() {return this->ambient;}
    float getDiffuse() {return this->diffuse;}
    float getSpecular() {return this->specular;}
    float getShininess() {return this->shininess;}

    void setMaterialColor(Color materialColorIn) {this->materialColor = materialColorIn;}
    void setAmbient(float ambientIn) {this->ambient = ambientIn;}
    void setDiffuse(float diffuseIn) {this->diffuse = diffuseIn;}
    void setSpecular(float specularIn) {this->specular = specularIn;}
    void setShininess(float shininessIn) {this->shininess = shininessIn;}

    bool operator==(Material& rhs);
    Color lighting(Light lightIn, Point positionIn, Vector eyeVector, Vector normalVector);
};

#endif //GOOGLE_TESTS_MATERIAL_H
