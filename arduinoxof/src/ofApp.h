#pragma once
#include "ofxSyphon.h"
#include "ofMain.h"
class ofApp : public ofBaseApp{
public:
    //Standard oF functions.
    void setup();
    void update();
    void draw();
    
    
    //Custom variables for on screen string and font.
    string msg;

    
    ofVideoPlayer videos[2];
    ofImage vidShift;
    
    ofSerial serial;
    
    
    ofxSyphonServer mainOutputSyphonServer;
    ofxSyphonClient mClient;
    
};
