//
//  TrackNode.cpp
//  rollercoaster
//
//  Created by Manuel Baumgartner on 03/11/2017.
//
//

#include "TrackNode.hpp"

TrackNode::TrackNode() {
    
}

void TrackNode::setElement(float _x, float _y, float _z) {
    element.x = _x;
    element.y = _y;
    element.z = _z;
}

void TrackNode::setElement(ofVec3f _element) {
    element = _element;
}

ofVec3f TrackNode::getElement() {
    return element;
}

void TrackNode::setTangent(float _x, float _y, float _z) {
    tangent.x = _x;
    tangent.y = _y;
    tangent.z = _z;
}

void TrackNode::setTangent(ofVec3f _tangent) {
    tangent = _tangent;
}

ofVec3f TrackNode::getTangent() {
    return tangent;
}

void TrackNode::setNormal(float _x, float _y, float _z) {
    normal.x = _x;
    normal.y = _y;
    normal.z = _z;
}

void TrackNode::setNormal(ofVec3f _normal) {
    normal = _normal;
}

ofVec3f TrackNode::getNormal() {
    return normal;
}

void TrackNode::setScale(float _scale) {
    scale = _scale;
}

float TrackNode::getScale() {
    return scale;
}