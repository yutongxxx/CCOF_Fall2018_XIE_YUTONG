#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(250,250,250);
    gui.setup();
    gui.add(radius.setup("radius", 240, 10, 500));
    gui.add(radius2.setup("radius2", 100, 10, 500));
    gui.add(radius3.setup("radius3", 50, 10, 500));
    gui.add(framerate.setup("framerate", 3, 0, 24));

    inputPct = 0;

}

//--------------------------------------------------------------
void ofApp::update(){
    
    inputPct += 0.1;
    if(inputPct > 1) inputPct = 0;
    
  
    float color = (inputPct);
    

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radius);
    
    gui.draw();
//    ofSetColor(20, ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
    
    
     for(int i = 0; i<15; i++){
         ofSetFrameRate(framerate);

         ofSetColor(color,ofRandom(0,255), ofRandom(0,255), ofRandom(0,255));
 
                    
//         float t = ofRandom(180);
//         ofMap(10, 10, 10, 10, 10);
         ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radius2);
         ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, radius3);
         
     }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
