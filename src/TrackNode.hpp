//
//  TrackNode.hpp
//  rollercoaster
//
//  Created by Manuel Baumgartner on 03/11/2017.
//
//

#ifndef TrackNode_hpp
#define TrackNode_hpp

#include <stdio.h>

#include "ofMain.h"

class TrackNode {
private:
    ofVec3f element;
    ofVec3f tangent;
    ofVec3f normal;
    float scale;
public:
    typedef ofPtr<TrackNode> Ref;
    TrackNode();
    
    void setElement(float _x, float _y, float _z);
    void setElement(ofVec3f _element);
    ofVec3f getElement();
    
    void setTangent(float _x, float _y, float _z);
    void setTangent(ofVec3f _tangent);
    ofVec3f getTangent();
    
    void setNormal(float _x, float _y, float _z);
    void setNormal(ofVec3f _normal);
    ofVec3f getNormal();
    
    void setScale(float _scale);
    float getScale();
};

#endif /* TrackNode_hpp */
