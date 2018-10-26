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
    lullaby.load("lullaby.mp3");
    
    
 

}

//--------------------------------------------------------------
void ofApp::update(){
    
    ofPoint wind;
    wind.set(0.006, 0.005);
    
    for(int i = 0; i<TOTALNUM; i++){
        
        particles[i].applyForce(wind);
        particles[i].addGravityForce(0.0008);
        
        
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

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
    if (key ==' ') {
        
        for(int i = 0; i<TOTALNUM * 2; i++){
            particles[i].draw();
        }
        
        lullaby.play();
    }
    
}









