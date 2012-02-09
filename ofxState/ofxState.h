#ifndef _OFX_STATE_H_
#define _OFX_STATE_H_

#include "ofMain.h"

class ofxState {
public:
	ofxState(){};
	virtual ~ofxState(){};
	virtual void stop(){};
	virtual void start(){};
	virtual void update(){};
	virtual void draw(){};
	virtual void mouseDragged(ofMouseEventArgs &e){};
	virtual void mousePressed(ofMouseEventArgs &e){};
	virtual void mouseReleased(ofMouseEventArgs &e){};
	virtual void mouseMoved(ofMouseEventArgs &e){};
	virtual void keyPressed(ofKeyEventArgs &e){};
	virtual void keyReleased(ofKeyEventArgs &e){};
	virtual void gotMessage(ofMessage &e){};
	virtual string getStateName(){
		return "";
	};
};

#endif;