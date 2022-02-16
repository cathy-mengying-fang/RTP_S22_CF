#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofBackground(0,0,0);
    for (int j = 0; j < 16; j++){
        float xorig = 400;
        float yorig = 400;
        float radius = 200;
        float angle = 2*PI/16*j;
        

        
        float unit_xorig = xorig + radius * cos(angle);
        float unit_yorig = yorig + radius * sin(angle);

        float unit_radius = 50;
        float elem_angle = 0;
        
        //set center of rotation
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        ofTranslate(unit_xorig,unit_yorig);
//        ofDrawCircle(0,0,10);
//        ofDrawLine(0,0,unit_xorig-xorig,unit_yorig-yorig);
        
        trail.begin();
        while(elem_angle<2*PI){
//                float x = unit_xorig + unit_radius * cos(elem_angle*2);
//                float y = unit_yorig + unit_radius * sin(elem_angle*3);
            float x = unit_radius * cos(elem_angle*2);
            float y = unit_radius * sin(elem_angle*3);
            ofSetColor(63,111,181);
            trail.addVertex(x,y);
            elem_angle+=2*PI/100;
        }
        trail.end();

        
//        ofRotateZ(ofGetElapsedTimef()*10);
//        ofRotateDeg(ofMap(mouseX,0,ofGetWidth(),0,360),unit_xorig-xorig,unit_yorig-yorig,0);
        ofRotateZDeg(ofMap(mouseX,0,ofGetWidth(),0,360));
        trail.draw();
        ofPopMatrix();
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
