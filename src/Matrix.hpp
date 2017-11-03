//
//  Matrix.hpp
//  rollercoaster
//
//  Created by Manuel Baumgartner on 19/10/2017.
//
//

#ifndef Matrix_hpp
#define Matrix_hpp

#include "ofMain.h"

class Matrix {
private:
    float a;
    float b;
    float c;
    float d;
    float e;
    float f;
    float g;
    float h;
    float i;
    float tx;
    float ty;
    float tz;
    
public:
    Matrix();
    ofVec3f apply(ofVec3f point);
    void setTranslation(float x, float y, float z);
    void setScale(float x, float y, float z);
    void setRotationX(float angle);
    void setRotationY(float angle);
    void setRotationZ(float angle);
};

#endif /* Matrix_hpp */
