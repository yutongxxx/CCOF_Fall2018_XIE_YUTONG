#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//
    ofBackground(0xffffff);
    ofEnableSmoothing();
    
    circleResolution.addListener(this, &ofApp::circleResolutionChanged);
    ringButton.addListener(this,&ofApp::ringButtonPressed);
    
    
    gui.setup();
    gui.add(radius.setup("closer", 9, 0.5, 50));
    gui.add(circleResolution.set("differences", 5, 3, 12));
    gui.add(ringButton.setup("future"));
    gui.add(color.setup("color", ofColor(100, 100, 140), ofColor(0, 0), ofColor(255, 255)));
    gui.add(frame.setup("framerate",10,0,100));
    
    future.load("ring.mp3");
    
    colorDatabase[0] = 0xFFEF00;
    colorDatabase[1] = 0xFFEF00;
    colorDatabase[2] = 0xFFFF00;
    colorDatabase[3] = 0xFFFF00;
    
    int colorIndex = (int)ofRandom(0, 3);
    p.color = colorDatabase[colorIndex];
    particles.push_back(p);
    
//    ofDrawCircle(ofGetWindowHeight()/2, ofGetWindowWidth()/2, 5);
   
    

    
    for(int i = 0; i< 10; i++){
        for (int y = 0; y< 10 ; y++) {
            pos2[y+i*10].set(100+y*100,30+i*100);


        }
    }
    
      
//        color[i] = ofRandom(0xFFFFFF);
    

    
}
//--------------------------------------------------------------
void ofApp::exit(){
    ringButton.removeListener(this,&ofApp::ringButtonPressed);
}
//--------------------------------------------------------------
void ofApp::update(){
    
    for(int i = 0; i< 10; i++){
        for (int y = 0; y< 10 ; y++) {
            ofSetColor(color);
            pos[y+i*10].set(200+y*100+20*sin(ofGetElapsedTimef()),30+i*100+20*cos(ofGetElapsedTimef()));
        }
    }
    
    
   
    
}
//--------------------------------------------------------------
void ofApp::circleResolutionChanged(int & circleResolution){
    ofSetCircleResolution(circleResolution);
}

//--------------------------------------------------------------
void ofApp::ringButtonPressed(){
    future.play();
}

//--------------------------------------------------------------

void ofApp::draw(){
//    ofSetFrameRate(ofRandom(20));
    gui.draw();
    
    for(int i = 0; i < TOTALNUM; i++){
       
        ofDrawCircle(pos[i], radius);
    }
    
    for(int i = 0; i < TOTALNUM; i++){
        
        ofSetColor(ofRandom(99), ofRandom(200,255), ofRandom(0,130), ofRandom(30,50));
        ofDrawCircle(pos2[i], radius+4);
    }
    
    for(int i = 0; i < TOTALNUM; i++){
        
        ofSetColor(ofRandom(40), ofRandom(200,255), ofRandom(0,130), ofRandom(30,50));
        ofDrawCircle(pos2[i], radius+5);
    }
    
    for(int i = 0; i < TOTALNUM; i++){
        
        ofDrawCircle(pos2[i], radius+2);
    }
    
   
}
    



