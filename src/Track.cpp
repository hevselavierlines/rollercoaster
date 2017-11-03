//
//  Track.cpp
//  rollercoaster
//
//  Created by Manuel Baumgartner on 03/11/2017.
//
//

#include "Track.hpp"

Track::Track() {
    steps = 200;
    range = 16;
    changed = true;
    
    nodes.reserve(steps + 1);
}

void Track::draw() {
    ofSetLineWidth(5.0f);
    ofSetColor(255, 255, 255);
    path.draw();
    
    for(int i = 0; i < nodes.size(); i++) {
        ofVec3f element = nodes[i]->getElement();
        ofVec3f normal = nodes[i]->getNormal();
        ofVec3f tangent = nodes[i]->getTangent();
        
        ofSetLineWidth(1.0f);
        ofSetColor(255, 0, 0);
        ofDrawLine(element.x, element.y, element.z, element.x + normal.x, element.y + normal.y, element.z + normal.z);
        
        ofSetColor(0, 255, 0);
        ofDrawLine(element.x, element.y, element.z, element.x + tangent.x, element.y + tangent.y, element.z + tangent.z);
    }
}

void Track::setLineArguments(float _zAngle) {
    if(_zAngle != zAngle) {
        changed = true;
    }
    zAngle = _zAngle;
}

void Track::setCircleArguments(float _angle, float _radius) {
    if(_angle != zAngle || _radius != radius) {
        changed = true;
    }
    zAngle = _angle;
    radius = _radius;
}

void Track::setLoopTheLoopArguments(float _radius, float _ltlA, float _ltlB, float _ltlC) {
    if(_radius != radius || _ltlA != ltlA || _ltlB != ltlB || _ltlC != ltlC) {
        changed = true;
    }
    radius = _radius;
    ltlA = _ltlA;
    ltlB = _ltlB;
    ltlC = _ltlC;
}

void Track::setType(Type _type) {
    if(type != _type) {
        changed = true;
    }
    type = _type;
}

void Track::generate() {
    path.clear();
    nodes.clear();
    if(type == Type::LINE) {
        ofMatrix4x4 ofMatrix;
        ofMatrix.rotate(zAngle, 0, 0, 1);
        ofMatrix.translate(0, 5, 0);
        float seti = 0.0f;
        for(int i = 0; i <= steps; ++i) {
            float s {float(1.0) / steps * i};
            float x {(s - 0.5f) * range};
            float y {0.0f};
            
            ofVec3f pos;
            pos.x = x;
            pos.y = y;
            pos.z = 0.0f;
            ofVec3f newPos = pos * ofMatrix;
            path.addVertex(newPos);
            
            TrackNode::Ref trackNode(new TrackNode());
            trackNode->setElement(newPos);
            trackNode->setNormal(path.getNormalAtIndex(i));
            trackNode->setTangent(path.getTangentAtIndex(i));
            
            if(i == 0) {
                trackNode->setScale(0);
            } else {
                seti += newPos.distance(nodes[i - 1]->getElement());
                trackNode->setScale(seti);
            }
            
            nodes.push_back(trackNode);
        }
        
        float totalDistance = nodes[nodes.size() - 1]->getScale();
        float distanceScaleFactor = 1.0f / totalDistance;
        for(int i = 0; i < nodes.size(); ++i) {
            nodes[i]->setScale(nodes[i]->getScale() * distanceScaleFactor);
        }
    } else if (type == Type::CIRCLE) {
        float t = 0;
        ofMatrix4x4 ofMatrix;
        ofMatrix.rotate(zAngle, 0, 0, 1);
        ofMatrix.translate(0, 5, 0);
        float seti = 0.0f;
        for(int i = 0; i <= steps; ++i) {
            t = (2*3.141592654) / 200 * i;
            float x = radius * cos(t);
            float y = radius * sin(t);
            
            ofVec3f point;
            point.x = x;
            point.y = 0.0f;
            point.z = y;
            ofVec3f newPos = point * ofMatrix;
            //ofVec3f newPoint = matrix.apply(point);
            path.addVertex(newPos);
            
            TrackNode::Ref trackNode(new TrackNode());
            trackNode->setElement(newPos);
            trackNode->setNormal(path.getNormalAtIndex(i));
            trackNode->setTangent(path.getTangentAtIndex(i));
            
            if(i == 0) {
                trackNode->setScale(0);
            } else {
                seti += newPos.distance(nodes[i - 1]->getElement());
                trackNode->setScale(seti);
            }
            
            nodes.push_back(trackNode);
        }
        
        float totalDistance = nodes[nodes.size() - 1]->getScale();
        float distanceScaleFactor = 1.0f / totalDistance;
        for(int i = 0; i < nodes.size(); ++i) {
            nodes[i]->setScale(nodes[i]->getScale() * distanceScaleFactor);
        }
    } else if(type == Type::LOOP) {
        float t = 0;
        float r = radius;
        float seti = 0.0f;
        for(int i = 0; i <= steps; ++i) {
            t = (2*3.141592654) / 200 * i;
            float x = cos(ltlA * t) * r;
            float y = sin(ltlB * t) * r * 0.25f;
            float z = sin(ltlC * t) * r;
            ofVec3f newPos;
            newPos.x = x;
            newPos.y = y;
            newPos.z = z;
            path.addVertex(newPos);
            
            TrackNode::Ref trackNode(new TrackNode());
            trackNode->setElement(newPos);
            trackNode->setNormal(path.getNormalAtIndex(i));
            trackNode->setTangent(path.getTangentAtIndex(i));
            
            if(i == 0) {
                trackNode->setScale(0);
            } else {
                seti += newPos.distance(nodes[i - 1]->getElement());
                trackNode->setScale(seti);
            }
            
            nodes.push_back(trackNode);
        }
        
        float totalDistance = nodes[nodes.size() - 1]->getScale();
        float distanceScaleFactor = 1.0f / totalDistance;
        for(int i = 0; i < nodes.size(); ++i) {
            nodes[i]->setScale(nodes[i]->getScale() * distanceScaleFactor);
        }
    }
    
    changed = false;
}

void Track::checkDifference() {
    if(changed == true) {
        changed = false;
        generate();
    }
}

