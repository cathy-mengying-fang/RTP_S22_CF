#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground (255);
    ofSeedRandom(mouseX);
    int width = ofGetWidth();
    int height = ofGetHeight();
    int lines = 13;
    int dots = 52;
    
    for (int line = 0; line < 13; line++){
//        int prevX = 0;
        for (int dot = 0; dot < 52; dot ++){
            
//            float offset = ofRandom(0,width/lines/2);
//            float x = width/lines*line + offset;
            float pct = ofMap(line, 0, 12, 0, 1);
            float pow = ofRandom(0,1);
            pct = powf(pct,pow);
            float x = ofMap(pct,0,1,0,width);
//            prevX = x;
            float y = ofMap(dot,0,51,0,height);
            
            ofSetColor(0);
            ofDrawCircle(x+50, y+20, 2);
        }

    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
