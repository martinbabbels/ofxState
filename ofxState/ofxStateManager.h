#ifndef _OFX_STATE_MANAGER_H_
#define _OFX_STATE_MANAGER_H_

#include "ofMain.h"
#include "ofxState.h"

class ofxStateManager {
public:
	
	ofxStateManager();
	~ofxStateManager();
	
	void setState(ofxState *state);
	string getStateName();
	void clearState();
	void update();
	void draw();
	
	
private:
	
	void update(ofEventArgs &e);
	void draw(ofEventArgs &e);
	void mouseDragged(ofMouseEventArgs &e);
	void mousePressed(ofMouseEventArgs &e);
	void mouseReleased(ofMouseEventArgs &e);
	void mouseMoved(ofMouseEventArgs &e);
	void keyPressed(ofKeyEventArgs &e);
	void keyReleased(ofKeyEventArgs &e);
	void gotMessage(ofMessage &e);
	void addListeners();
	void removeListeners();
	
	ofxState *currentState;
	string currentStateName;
};

#endif;