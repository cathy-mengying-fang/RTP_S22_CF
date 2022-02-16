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
    float xorig = 400;
    float yorig = 400;
    float radius = 200;
    float elem_angle;
    float unit_radius = 50;
    
//    ofNoFill();
//    ofDrawCircle(xorig,yorig,radius);
    
    for (int j = 0; j < 16; j++){
//        cout<<j<<endl;
        float angle = 2*PI/16*j;
        
        float rot_xorig = xorig + radius * cos(angle);
        float rot_yorig = yorig + radius * sin(angle);

       
        
        
        float unit_xorig = xorig + (radius-unit_radius) * cos(angle);
        float unit_yorig = yorig + (radius-unit_radius) * sin(angle);
        
        float newX = (rot_xorig-unit_xorig);
        float newY = (rot_yorig-unit_yorig);
        //set center of rotation
        ofSetRectMode(OF_RECTMODE_CENTER);
        ofPushMatrix();
        ofTranslate(unit_xorig,unit_yorig);
        
        
//        trail.begin(); # this somehow duplicates multiple polylines...
        elem_angle = 0;
//        ofDrawCircle(0,0,10);
        while(elem_angle<2*PI){
            float x = newX + unit_radius * cos(elem_angle*2);
            float y = newY + unit_radius * sin(elem_angle*3);
//            cout<<x<<endl;
            ofSetColor(63,111,181);
            trail.addVertex(x,y);
            elem_angle+=2*PI/100;
        }
        trail.end();
        ofRotateZDeg(ofMap(sin(ofGetElapsedTimef()*2),-2,2,0,360));
        trail.draw();
        trail.clear();
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
