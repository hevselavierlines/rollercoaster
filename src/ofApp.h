#pragma once

#include <iostream>
#include <vector>

#include "ofMain.h"
#include "ofxImGui.h"
#include "ofxXmlSettings.h"
#include "Matrix.hpp"

#include "Track.hpp"

#include "YAMPE/Particle.h"

#include "ParticleForceGeneratorRegistry.h"

class ofApp : public ofBaseApp {
    
public:
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    void mouseMoved(int x, int y );
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    void mouseReleased(int x, int y, int button);
    void mouseEntered(int x, int y);
    void mouseExited(int x, int y);
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
		
    // simple 3D world with ground and axes
    const float RANGE = 16;
    ofEasyCam easyCam;
    float cameraHeightRatio = 0.02f;
    ofPoint easyCamTarget = ofPoint(0,5,0);
    void cameraHeightRatioChanged(float & cameraHeightRatio);

    ofPlanePrimitive ground;
    
    ofxImGui::Gui gui;                      // single entery to ImGUI subsystem
    ofRectangle mainWindowRectangle;        // used to ignore mouse drags for camera
    ofRectangle loggingWindowRectangle;     // used to ignore mouse drags for camera
    void drawAppMenuBar();
    void drawMainWindow();
    void drawLoggingWindow();
    
    // simimulation (generic)
    void reset();
    void quit();
    float t = 0.0f;
    bool isRunning = true;
    
    ofParameter<bool> isAxisVisible = true;
    ofParameter<bool> isXGridVisible = false;
    ofParameter<bool> isYGridVisible = true;;
    ofParameter<bool> isZGridVisible = false;;
    ofParameter<bool> isGroundVisible = true;
    ofParameter<bool> isFullScreen;
    ofParameter<std::string> position;
    
    ofPolyline track;
    std::vector<string> tracks;
    int trackSelection;
    
    float lineAngle;
    float circleRadius = 1.0f;
    
    int loopA;
    int loopB;
    int loopC;
    float strokeWidth;
    float velocity = 0.001f;
    float currAngle;
    float force;
    bool animate = false;
    // TODO - simimulation (specific stuff)
    void toggleAnimation();
    
private:
    YAMPE::Particle ball;
    Track trackElem;
    float ballPos;
    // or here

    YAMPE::P::ForceGeneratorRegistry forceGenerators;
    YAMPE::ParticleRegistry particles;
    
    bool isForceVisible;

};
