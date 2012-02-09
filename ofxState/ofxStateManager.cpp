#include "ofxStateManager.h"

ofxStateManager::ofxStateManager() {
	currentState = NULL;
	addListeners();
}

ofxStateManager::~ofxStateManager() {
}

void ofxStateManager::addListeners() {
	ofAddListener(ofEvents.update, this, &ofxStateManager::update);
	ofAddListener(ofEvents.draw, this, &ofxStateManager::draw);
	ofAddListener(ofEvents.mouseDragged, this, &ofxStateManager::mouseDragged);
	ofAddListener(ofEvents.mouseMoved,this,&ofxStateManager::mouseMoved);
	ofAddListener(ofEvents.mousePressed,this,&ofxStateManager::mousePressed);
	ofAddListener(ofEvents.mouseReleased,this,&ofxStateManager::mouseReleased);
	ofAddListener(ofEvents.keyPressed,this,&ofxStateManager::keyPressed);
	ofAddListener(ofEvents.keyReleased,this,&ofxStateManager::keyReleased);
	ofAddListener(ofEvents.messageEvent ,this,&ofxStateManager::gotMessage);
}

void ofxStateManager::removeListeners() {
	ofRemoveListener(ofEvents.update, this, &ofxStateManager::update);
	ofRemoveListener(ofEvents.draw, this, &ofxStateManager::draw);
	ofRemoveListener(ofEvents.mouseDragged, this, &ofxStateManager::mouseDragged);
	ofRemoveListener(ofEvents.mouseMoved,this,&ofxStateManager::mouseMoved);
	ofRemoveListener(ofEvents.mousePressed,this,&ofxStateManager::mousePressed);
	ofRemoveListener(ofEvents.mouseReleased,this,&ofxStateManager::mouseReleased);
	ofRemoveListener(ofEvents.keyPressed,this,&ofxStateManager::keyPressed);
	ofRemoveListener(ofEvents.keyReleased,this,&ofxStateManager::keyReleased);
	ofRemoveListener(ofEvents.messageEvent ,this,&ofxStateManager::gotMessage);
}

void ofxStateManager::update(ofEventArgs &e) {
	update();
}

void ofxStateManager::draw(ofEventArgs &e) {
	draw();
}

void ofxStateManager::update() {
	if(currentState!=NULL) {
		currentState->update();
	}
}

void ofxStateManager::draw() {
	if(currentState!=NULL) {
		currentState->draw();
	}
}

void ofxStateManager::mouseDragged(ofMouseEventArgs &e) {
	if(currentState!=NULL) {
		currentState->mouseDragged(e);
	}
}

void ofxStateManager::mouseMoved(ofMouseEventArgs &e) {
	if(currentState!=NULL) {
		currentState->mouseMoved(e);
	}
}

void ofxStateManager::mousePressed(ofMouseEventArgs &e) {
	if(currentState!=NULL) {
		currentState->mousePressed(e);
	}
}

void ofxStateManager::mouseReleased(ofMouseEventArgs &e) {
	if(currentState!=NULL) {
		currentState->mouseReleased(e);
	}
}

void ofxStateManager::keyPressed(ofKeyEventArgs &e) {
	if(currentState!=NULL) {
		currentState->keyPressed(e);
	}
}

void ofxStateManager::keyReleased(ofKeyEventArgs &e) {
	if(currentState!=NULL) {
		currentState->keyReleased(e);
	}
}

void ofxStateManager::gotMessage(ofMessage &e) {
	if(currentState!=NULL) {
		currentState->gotMessage(e);
	}
}

void ofxStateManager::setState(ofxState *state) {
	if(state->getStateName()==currentStateName)
		return;
	
	if(currentState) currentState->stop();
	state->start();
	currentState = state;
	currentStateName = currentState->getStateName();
	
}

string ofxStateManager::getStateName() {
	return currentStateName;
}

void ofxStateManager::clearState() {
	if(currentState!=NULL) {
		currentState->stop();
	}
	currentStateName = "";
	currentState = NULL;
}


