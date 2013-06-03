//
//  WDCiKuramoto.h
//  basicApp
//
//  Created by Hiroki Sato on 2013/05/28.
//
//

#ifndef __basicApp__WDCiKuramoto__
#define __basicApp__WDCiKuramoto__

#include <iostream>
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/CinderMath.h"
#include <list>

using namespace ci;
using namespace ci::app;
using namespace std;

class WDCiKuramoto{
public:
    WDCiKuramoto(int _myId, float _z);
    ~WDCiKuramoto();
    
    void setup();
    void update(vector<float> othersTheta);
    void draw();
    
    float getTheta();
    void setNoise(float _noise);
    void setJointStrength(float _jointStrength);
    void initialize();
    
private:
    int   myId;    // Unique scillator id
    float theta;
    float omega;
    float deltaT;
    float noise;
    
    float z;
    
    float K;
    
    Vec3f pos;
    
    
    
};

#endif /* defined(__basicApp__WDCiKuramoto__) */
