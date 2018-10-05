#pragma once
#include "ofxGui.h"
#include "ofMain.h"
#include "Particle.hpp"

#define TOTALNUM 100

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
    
    void exit();
    
    void circleResolutionChanged(int & circleResolution);
    void ringButtonPressed();
    
    ofxPanel gui;
    ofxFloatSlider radius;
    ofxFloatSlider frame;
    ofxColorSlider color;
    ofParameter<ofVec2f> center;
    ofParameter<int> circleResolution;
    ofParameter<bool> filled;
    ofxButton twoCircles;
    ofxButton ringButton;

    Particle p;
    ofColor colorDatabase[4];
    vector<Particle> particles;
    

    ofPoint pos[TOTALNUM];
    ofPoint pos2[TOTALNUM];
//    ofPoint vel[TOTALNUM];
    
//    int radius = 5;
   ofSoundPlayer future;
    
 
        
};
