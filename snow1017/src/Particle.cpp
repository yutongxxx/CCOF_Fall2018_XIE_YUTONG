//
//  Particle.cpp
//  snow1017
//
//  Created by Yutong Xie on 10/17/18.
//

#include "Particle.hpp"

void Particle::setup(){
    
    
    ofSetFrameRate(10);
    mass = ofRandom(0.5, 1);
    loc.set(ofRandomWidth(), ofRandomHeight());
    vel.set(0, 0);
    acc.set(0, 0);


  
}
//--------------------------------------------------------------
void Particle::applyForce(ofPoint _f){
    acc += _f/mass;
}


//--------------------------------------------------------------
void Particle::addGravityForce(float _g){
    ofPoint gravity;
    gravity.set(0, _g * mass);
    
    applyForce(gravity);
}


//--------------------------------------------------------------
void Particle::update(){
    
    vel += acc;
    loc += vel;
    
    acc.set(0, 0);
    
    if(loc.y > (ofGetWindowHeight()-5)){
        
        vel.x = 0;
        vel.y = 0;
    }
    
}

//--------------------------------------------------------------
void Particle::draw(){
    
    ofSetColor(255, ofRandom(95,100));
    ofDrawEllipse(loc.x, loc.y, ofRandom(mass * 5,mass * 5),ofRandom(mass * 5,mass * 6));
    
   
}

//--------------------------------------------------------------
void Particle::keyPressed(int key){
    
if(key == ' '){
 
    ofSetFrameRate(0);
}
}
