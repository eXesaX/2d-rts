#include "ofApp.h"
#include "Map.h"

//--------------------------------------------------------------
void ofApp::setup(){
	width = ofGetWindowWidth();
	height = ofGetWindowHeight();
	worldMap.setup("map.png", "minimap.png", &width, &height);

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	worldMap.draw();
	worldMap.drawMinimap();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	ofPoint delta = { 0, 0 };
	if (key == 'w') {
		delta += {0, -0.01f};
	}
	if (key == 'a') {
		delta += {0.01f, 0};
	}
	if (key == 's') {
		delta += {0, 0.01f};
	}
	if (key == 'd') {
		delta += {-0.01f, 0};
	}
	worldMap.scrollOn(delta);
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	worldMap.mouseMinimapCallback(x, y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}