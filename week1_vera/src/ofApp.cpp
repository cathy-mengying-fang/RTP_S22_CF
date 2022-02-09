#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(239,237,229);
    ofSetColor(92,111,133);
    ofSetLineWidth(0.5);
    for (int row = 0; row < 24; row ++){
        int gap = 27.5;
        int rowHeight = 75 + row * gap;
        int startX = 100;
        // endX = 700
        for (int seg = 0; seg < 40; seg ++){
            int y = rowHeight + 10;
            int y1 = rowHeight - 10;
            int x = startX + seg * 15;
            ofDrawLine(x, y, x+7.5, y1);
            int y2 = rowHeight + 10;
            ofDrawLine(x+7.5, y1, x+15, y2);
        }
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's'){
        ofImage image;
        int width = ofGetWindowWidth();
        int height = ofGetWindowHeight();
        image.grabScreen(0, 0, width, height);
        ofSaveImage(image,"file.jpg"); //save to disk
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

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
