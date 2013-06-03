//
//  WDCiKuramotoController.cpp
//  basicApp
//
//  Created by Hiroki Sato on 2013/05/28.
//
//

#include "WDCiKuramotoController.h"

WDCiKuramotoController::WDCiKuramotoController(int _numOscs)
{
    numOscs = _numOscs;
    for (int i=0; i<numOscs; i++) {
        int oscId = i;
        oscs.push_back(WDCiKuramoto(oscId, i-numOscs/2));
    }
}


WDCiKuramotoController::~WDCiKuramotoController()
{
    
}


#pragma mark - setup, update, draw


void WDCiKuramotoController::setup()
{
    for (int i=0; i<oscs.size(); i++){
        oscs[i].setup();
    }
    
    // Setup Parameter GUI
    jStrength = 0;
    noiseLevel = 0;
    mParams = params::InterfaceGl( "Parameters", Vec2i( 200, 50 ) );
    mParams.addParam( "Joint Strength", &jStrength );
    //    mParams.addParam( "Noise Level",    &noiseLevel );
}


void WDCiKuramotoController::update()
{
    vector<float> othersTheta;
    for (int i=0; i<oscs.size(); i++){
        othersTheta.push_back(oscs[i].getTheta());
    }
    
    for (int i=0; i<oscs.size(); i++){
        oscs[i].update(othersTheta);
    }
    
    // Update GUI Parameters
    setNoiseAll();
    setJointStrengthAll();
}


void WDCiKuramotoController::draw()
{
    for (int i=0; i<oscs.size(); i++) {
        oscs[i].draw();
    }
    
    // Draw Parameter GUI
    params::InterfaceGl::draw();
}



#pragma mark - Utilities


void WDCiKuramotoController::setNoiseAll()
{
    for (int i=0; i<oscs.size(); i++){
        oscs[i].setNoise(noiseLevel);
    }
}


void WDCiKuramotoController::setJointStrengthAll()
{
    for (int i=0; i<oscs.size(); i++){
        oscs[i].setJointStrength(jStrength);
    }
}


void WDCiKuramotoController::initializeAll()
{
    for (int i=0; i<oscs.size(); i++){
        oscs[i].initialize();
    }
}
