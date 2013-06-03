//
//  basicApp.h
//  basicApp
//
//  Created by Hiroki Sato on 2013/05/28.
//
//

#ifndef basicApp_basicApp_h
#define basicApp_basicApp_h

#include "cinder/app/AppBasic.h"
#include "cinder/Rand.h"
#include "cinder/Font.h"
#include "cinder/Utilities.h"
#include "cinder/MayaCamUI.h"

#include "WDCiKuramotoController.h"

using namespace ci;
using namespace ci::app;


class BasicApp : public AppBasic {
public:
    
    void setup();
    void update();
    void draw();
	void mouseDrag( MouseEvent event );
	void keyDown( KeyEvent event );
    
    void drawGrid(float size=100.0f, float step=10.0f);
    
    
    MayaCamUI mMayaCam;
    WDCiKuramotoController *controller;
    
};

#endif
