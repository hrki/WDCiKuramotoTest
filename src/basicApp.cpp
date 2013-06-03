//
//  basicApp.cpp
//  basicApp
//
//  Created by Hiroki Sato on 2013/05/28.
//
//

#include "basicApp.h"


void BasicApp::setup()
{
    controller = new WDCiKuramotoController(50);
    controller->setup();
    
    
    // set up the camera
	CameraPersp cam;
	cam.setEyePoint( Vec3f(120.0f, 100.0f, 100.0f) );
	cam.setCenterOfInterestPoint( Vec3f(0.0f, 0.0f, 0.0f) );
	cam.setPerspective( 60.0f, getWindowAspectRatio(), 1.0f, 1000.0f );
	mMayaCam.setCurrentCam( cam );
    
}


void BasicApp::update()
{
    controller->update();
}


void BasicApp::draw()
{
	gl::clear( Colorf(0.7f, 0.7f, 0.7f) );
    
    // setup camera
	gl::pushMatrices();
	gl::setMatrices( mMayaCam.getCamera() );
    // enable the depth buffer
	gl::enableDepthRead();
	gl::enableDepthWrite();
    
    drawGrid();
    controller->draw();
    
    gl::popMatrices();
    
}


void BasicApp::mouseDrag( MouseEvent event )
{
    // UI, camera
    mMayaCam.mouseDrag( event.getPos(), event.isLeftDown(), event.isMiddleDown(), event.isRightDown() );
}


void BasicApp::keyDown( KeyEvent event )
{
    if( event.getChar() == 'r' )
		controller->initializeAll();
}


void BasicApp::drawGrid(float size, float step)
{
	gl::color( Colorf(0.2f, 0.2f, 0.2f) );
	for(float i=-size;i<=size;i+=step) {
		gl::drawLine( Vec3f(i, 0.0f, -size), Vec3f(i, 0.0f, size) );
		gl::drawLine( Vec3f(-size, 0.0f, i), Vec3f(size, 0.0f, i) );
	}
}



// This line tells Flint to actually create the application
CINDER_APP_BASIC( BasicApp, RendererGl )