#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    davinci.load("davinci.jpg");
    monalisa.load("monalisa.jpg");
    lillian.load("lillian.jpg");
    monaleo.allocate(400,800,OF_IMAGE_COLOR);

}

//--------------------------------------------------------------
void ofApp::update(){
    ofColor color;
    for (int i = 0; i < 400; i++){
        for (int j = 0; j < 800; j++){
            if ((i+j)%2){
                color = davinci.getColor(i, j);
            }
            else{
                color = monalisa.getColor(i, j);
            }
            monaleo.setColor(i,j,color);
        }
    }
    monaleo.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    monaleo.draw(0,0);
    davinci.draw(400,0,400,800);
    monalisa.draw(800,0,400,800);
    
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
