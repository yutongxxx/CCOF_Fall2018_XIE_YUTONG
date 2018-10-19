//
//  Particle.hpp
//  snow1017
//
//  Created by Yutong Xie on 10/17/18.
//

#ifndef Particle_hpp
#define Particle_hpp

#include <ofMain.h>
class Particle{
    
public:
    void setup();
    void update();
    void draw();
    void keyPressed(int key);
    
    void applyForce(ofPoint _f);
    void addGravityForce(float _g);
    
    ofPoint loc;
    ofPoint vel;
    ofPoint acc;
    
    float mass;

    
};

#endif /* Particle_hpp */
