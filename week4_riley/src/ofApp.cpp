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
    
    int y = 400;
    for (int i=0; i<8; i++){
        int x = 400;
        int r = 200;
        if (i%2 == 1){
            ofSetColor(0);
        }
        else{
            ofSetColor(255);
        }
        ofDrawCircle(x-10*i,y,r-20*i);
    }
    

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's'){
        ofImage image;
        int width = ofGetWindowWidth();
        int height = ofGetWindowHeight();
        image.grabScreen(0, 0, width, height);
        string fileName = "file_"+ofGetTimestampString()+".jpg";
        ofSaveImage(image,fileName); //save to disk
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
