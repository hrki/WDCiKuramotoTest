//
//  WDCiKuramotoController.h
//  basicApp
//
//  Created by Hiroki Sato on 2013/05/28.
//
//

#ifndef __basicApp__WDCiKuramotoController__
#define __basicApp__WDCiKuramotoController__

#include <iostream>
#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/params/Params.h"
#include "WDCiKuramoto.h"


using namespace ci;
using namespace ci::app;
using namespace std;

class WDCiKuramotoController{
public:
    WDCiKuramotoController(int _numOscs);
    ~WDCiKuramotoController();
    
    void setup();
    void update();
    void draw();
    
    void setNoiseAll();  // add noise to all oscillators
    void setJointStrengthAll();
    void initializeAll();
    
    params::InterfaceGl mParams;
    
private:
    int numOscs;
    
    float jStrength;
    float noiseLevel;
    vector<WDCiKuramoto> oscs;
    
    
    
};
#endif /* defined(__basicApp__WDCiKuramotoController__) */
