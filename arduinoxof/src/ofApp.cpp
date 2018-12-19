#include "ofApp.h"
//int for storing the byte data from Arduino.
int byteData;
//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetWindowTitle("demo");
    mainOutputSyphonServer.setName("demo");
    mClient.setup();
    mClient.setApplicationName("Simple Server");
    mClient.setServerName("demo");
    ofSetFrameRate(60); // caps the framerate at 60fps.
  ofEnableSmoothing();
    ofBackground (0);
    
    //if get too close
    videos[0].load("bg.mp4");
    //always there
    videos[1].load("glitchbg.mp4");
    
    videos[0].play();
    videos[1].play();
    
    
    serial.setup("/dev/cu.usbmodem1411", 9600);
    
    
    
}
//--------------------------------------------------------------
void ofApp::update(){
    
    videos[0].update();
    videos[1].update();
    
    ofGetElapsedTimef();
    byteData = serial.readByte();
    byteData = ofClamp(byteData, 0, 200);
    cout<< "filtered byteData: " + std::to_string(byteData) << endl;
    
    
    //
    //    if (byteData > 5) {
    //        videos[1].play();
    //    } else {
    //        //While statement looping through serial messages when serial is being provided.
    //        while (byteData > 0 && !videos[1].isPlaying()) {
    ////            cout << "FUCK YOU MOTHER FUCKER - Sean" << endl;
    //
    ////            ofSetColor(255, 255, 255, 255*ofGetElapsedTimef());
    //            cout<< "am i here?" << endl;
    //            //videos[0].stop();
    //
    //            videos[1].play();
    //            cout<< "1 playing" <<endl;
    
    
    
    //video part tests
    
    //
    //            float time = ofGetElapsedTimef();
    //
    //            vid.update();
    //            if (vid.isFrameNew())
    //            {
    //                float time          = ofGetElapsedTimef();
    //                glm::vec2 mouse     = glm::vec2(ofGetMouseX(), ofGetMouseY());
    //                glm::vec2 mouseNorm = mouse / ofGetWindowSize();    // normalized 0-1
    //                glm::vec2 vidSize   = glm::vec2(vid.getWidth(), vid.getHeight());
    //
    //                // loop through video frame's pixels
    //                for (int y=0; y < vidSize.y; y++){
    //                    for (int x=0; x < vidSize.x; x++){
    //
    //                        glm::vec2 pos       = glm::vec2(x,y) / vidSize;     // normalize pos
    //
    //                        ofColor color       = vid.getPixels().getColor(x,y);
    //
    //                        float brightness    = color.getLightness() / 255;   // normalize 0-1
    //
    //                        // calc amount to move the pixel
    //
    //                        glm::vec2 offset;
    //
    //                        offset.x    = cos(time) * mouseNorm.x * brightness * 200;
    //                        offset.y    = sin(time) * mouseNorm.y * brightness * 200;
    //
    //                        int newX = int(x + offset.x) % int(vid.getWidth());
    //                        int newY = int(y + offset.y) % int(vid.getHeight());
    //
    //                        vidShift.setColor(newX, newY, color);
    //                    }
    //                }
    //                vidShift.update();
    //            }
    
    //video part ends
    
    
    
    
    
    //        }
    //    }
    
    
    
}
//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableAlphaBlending();
    mClient.draw(500,500);
    mainOutputSyphonServer.publishScreen();
    
    
    //  vidShift.draw(0,0, ofGetWidth(), ofGetHeight());
    
    videos[0].draw(200,200,500,400);
    
    if(byteData < 10 && byteData != 0){
        videos[1].draw(200,200,500,400);
    }
    
    
    ofEnableAlphaBlending();
}

