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
    int window = 5;
    for (int i = 0; i < 400; i++){
        int sumR = 0;
        int sumG = 0;
        int sumB = 0;
        int avgR = 0;
        int avgG = 0;
        int avgB = 0;
        for (int j = 0; j <= 800-window; j++){
            sumR = 0;
            sumG = 0;
            sumB = 0;
            avgR = 0;
            avgG = 0;
            avgB = 0;
            for (int k = j; k < j + window; k++){
                sumR += davinci.getColor(i, j).r;
                sumG += davinci.getColor(i, j).g;
                sumB += davinci.getColor(i, j).b;
                sumR += monalisa.getColor(i, j).r;
                sumG += monalisa.getColor(i, j).g;
                sumB += monalisa.getColor(i, j).b;
            }
            avgR = int(sumR/window);
            avgG = int(sumG/window);
            avgB = int(sumB/window);
            
//            if (int(j/10)%2 ==0){
//                color = davinci.getColor(i, j);
//            }
//            else if(int(j/10)%2 ==1){
//                color = monalisa.getColor(i, j);
//            }
            monaleo.setColor(i,j,ofColor(avgR,avgG,avgB));
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
