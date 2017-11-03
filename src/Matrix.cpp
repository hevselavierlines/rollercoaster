//
//  Matrix.cpp
//  rollercoaster
//
//  Created by Manuel Baumgartner on 19/10/2017.
//
//

#include "Matrix.hpp"

Matrix::Matrix() {
    a = 1.0; b = 0.0; c = 0.0; tx = 0.0;
    d = 0.0; e = 1.0; f = 0.0; ty = 0.0;
    g = 0.0; h = 0.0; i = 1.0; tz = 0.0;
}

ofVec3f Matrix::apply(ofVec3f point) {
    ofVec3f ret;
    ret.x = a * point.x + b * point.x + c * point.x + tx;
    ret.y = d * point.y + e * point.y + f * point.y + ty;
    ret.z = g * point.z + h * point.z + i * point.z + tz;
    return ret;
}

void Matrix::setTranslation(float x, float y, float z) {
    tx = x;
    ty = y;
    tz = z;
}

void Matrix::setScale(float x, float y, float z) {
    a = x;
    e = y;
    i = z;
}
