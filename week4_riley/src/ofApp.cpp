#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground (0);
    int xInc;
    int yInc;
    int x = 400;
    int y = 400;
    int r = 500;
    int prevX = x;
    int prevY = y;
    int prevR = r;
    for (int j = 0; j<3; j++){
        x = prevX;
        y = prevY;
        r = prevR;
        if (j==0){
            xInc = 20;
            yInc = 20;
        }
        else if (j==1){
            xInc = 20;
            yInc = -20;
        }
        else {
            xInc = -20;
            yInc = 0;
        }
        for (int i = 0; i<4; i++){
            x = x+xInc;
            y = y+yInc;
//            float pct = ofMap(j,1,4,1,0);
            float pct = powf((4-j), 0.8);
            r = r-15*pct;
//            ofSetColor(255,0,0);
//            ofDrawCircle(x,y,2);
            if (i%2 == 0){
                ofSetColor(255);
            }
            else{
                ofSetColor(0);
            }
//            ofNoFill();
//            ofSetColor(255);
            ofSetCircleResolution(100);
            ofDrawCircle(x,y,r);
        }
        prevX = x;
        prevY = y;
        prevR = r;
    }
    
    
    
    
    
    
    
    
    
////    for (int j=0;j<3;j++){
////        if (j==0){
//            int y = 400;
//            for (int i=0; i<8; i++){
//                int x = 400;
//                int r = 20;
//                if (i%2 == 0){
//                    ofSetColor(255);
//                }
//                else{
//                    ofSetColor(0);
//                }
////                ofNoFill();
//                ofDrawCircle(x+10*i,y,r+20*i);
////            }
////        }
////        if (j==1){
////
////        }
//    }
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
