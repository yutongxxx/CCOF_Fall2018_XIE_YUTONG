#include "ofApp.h"
#

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetBackgroundColor(0);
    ofEnableSmoothing();
    ofSetCircleResolution(50);
    ofSetBackgroundAuto(false);
    
    for(int i = 0; i<TOTALNUM; i++){
        Particle p;
        p.setup();
        particles.push_back(p);
    }
    
    bg.load("bg.jpg");
    
 

}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofPoint wind;
    wind.set(0.008, 0.005);
    
    for(int i = 0; i<TOTALNUM; i++){
        
        particles[i].applyForce(wind);
        particles[i].addGravityForce(0.008);
        
        
        particles[i].update();
        
       
            
        
    }

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    bg.draw(0,0);
    
    for(int i = 0; i<TOTALNUM; i++){
        particles[i].draw();
    }
    
  

}












