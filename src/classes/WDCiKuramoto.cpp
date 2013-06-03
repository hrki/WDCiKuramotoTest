//
//  WDCiKuramoto.cpp
//  basicApp
//
//  Created by Hiroki Sato on 2013/05/28.
//
//

#include "WDCiKuramoto.h"

WDCiKuramoto::WDCiKuramoto(int _myId, float _z)
{
    myId = _myId;
    z = _z / 25;
    K = 1.0;
}


WDCiKuramoto::~WDCiKuramoto()
{
    
}


#pragma mark - setup, update, draw


void WDCiKuramoto::setup()
{
    // randomize initial theta and position
    theta = randFloat(2 * M_PI);
    pos.set(0, 0, 0);
    
    // Angle Rate (freq = 0.5 here)
    omega =  2 * M_PI * 0.5;
    omega += omega * randFloat(-0.15 , 0.15);
    
    deltaT = 1.0 / getFrameRate();
}


void WDCiKuramoto::update(vector<float> othersTheta)
{
    // Kuramoto phase synchronization
    int N = othersTheta.size();
    float sumSin = 0;
    for (int i=0; i<N; i++) {
        sumSin += sin(othersTheta[i] - theta);
    }
    theta += (omega + noise + K/N*sumSin) * deltaT;
    
    // Set Position
    pos.set(sin(theta), abs(cos(theta)), z);
    //    pos.set(cos(theta), z+sin(theta)/10, sin(theta)); // Particle version
    
    // Initialize noise
    noise = 0;
}


void WDCiKuramoto::draw()
{
    glColor4f( 0.3f, 0.5f, 0.6f, 1.0f );
    gl::drawSphere(pos*getWindowWidth()/8, 5);
}


#pragma mark - Utilities


float WDCiKuramoto::getTheta()
{
    return theta;
}


void WDCiKuramoto::setNoise(float _noise)
{
    noise = _noise;
}


void WDCiKuramoto::setJointStrength(float _jointStrength)
{
    K = _jointStrength / 100;
}


void WDCiKuramoto::initialize()
{
    setup();
}

