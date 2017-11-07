//
//  Track.hpp
//  rollercoaster
//
//  Created by Manuel Baumgartner on 03/11/2017.
//
//

#ifndef Track_hpp
#define Track_hpp

#include <stdio.h>
#include "TrackNode.hpp"

class Track {
private:
    bool changed;
    float radius;
    float zAngle;
    float steps;
    float ltlA, ltlB, ltlC;
    float range;
    ofPolyline path;
    vector<TrackNode::Ref> nodes;
public:
    enum class Type {
        LINE, CIRCLE, LOOP
    };
    
    Type type;
    
    void setLineArguments(float _angle);
    void setCircleArguments(float _angle, float _radius);
    void setLoopTheLoopArguments(float _radius, float _ltlA, float _ltlB, float _ltlC);
    
    Track();
    void draw();
    void generate();
    
    void checkDifference();
    
    void setType(Type _type);
    
    ofVec3f getPositionByScale(float scale);
    TrackNode::Ref getTrackNodeByScale(float scale);
};

#endif /* Track_hpp */
