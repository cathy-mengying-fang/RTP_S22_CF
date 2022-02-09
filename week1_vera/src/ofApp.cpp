#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(mouseX);
    ofBackground(239,237,229);
    ofSetColor(92,111,133);
    ofSetLineWidth(0.5);
    for (int row = 0; row < 24; row ++){
        int gap = 27.5;
        int rowHeight = 75 + row * gap;
        int startX = 100;
        // endX = 700
        float prevX = startX;
        float prevY = rowHeight + ofRandom(5,10);
        for (int seg = 0; seg < 80; seg ++){
            if (seg > 40){
                float y1 = rowHeight - ofRandom(0,15);
                float xNoise = ofRandom(15,20);
                float midX = prevX + xNoise;
                ofDrawLine(prevX, prevY, midX, y1);
                
                float x2 = ofRandom(prevX,midX);
                float y2 = rowHeight + ofRandom(0,15);
                ofDrawLine(midX, y1, x2, y2);
                prevX = x2;
                prevY = y2;
                
            }
            else{
    //            float yNoise = 10 + ofRandom(0,1)*2;
                float y1 = rowHeight - ofRandom(5,10);
                float xNoise = ofRandom(15,20);
                float midX = prevX + xNoise;
                ofDrawLine(prevX, prevY, midX, y1);
                
                float x2 = ofRandom(prevX+5,midX-5);
                float y2 = rowHeight + ofRandom(5,10);
                ofDrawLine(midX, y1, x2, y2);
                prevX = x2;
                prevY = y2;
            }
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
