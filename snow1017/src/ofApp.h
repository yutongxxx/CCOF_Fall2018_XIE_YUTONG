#pragma once

#include "ofMain.h"
#include "Particle.hpp"
#define TOTALNUM 400

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();
        void keyPressed(int key);
        

    
       
    
    vector<Particle> particles;
    
    ofImage bg;
    ofSoundPlayer lullaby;
		
};
