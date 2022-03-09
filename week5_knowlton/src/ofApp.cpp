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
//    int window = 100;
//    int sumR;
//    int sumG;
//    int sumB;
//    float pct = ofMap(mouseX, 0, 1200, 0, 1);
    for (int i = 0; i < 400; i++){
//        sumR = 0;
//        sumG = 0;
//        sumB = 0;
        for (int j = 0; j < 800; j++){
            
            float distance = ofDist(mouseX, mouseY, i, j);
            if (distance < 100){
                float pct = ofMap(distance, 0, 100, 1,0);
                monaleo.setColor(i,j, ofColor(davinci.getColor(i,j)*pct + monalisa.getColor(i,j)*(1-pct)));

            } else {
                monaleo.setColor(i,j, ofColor(monalisa.getColor(i, j)));

            }
                        
//            sumR = sumR + (davinci.getColor(i, j).r*pct + monalisa.getColor(i, j).r*(1-pct));
//            sumG = sumG + (davinci.getColor(i, j).g*pct + monalisa.getColor(i, j).g*(1-pct));
//            sumB = sumB + (davinci.getColor(i, j).b*pct + monalisa.getColor(i, j).b*(1-pct));
            
//            if (int(j/10)%2 ==0){
//                color = davinci.getColor(i, j);
//            }
//            else if(int(j/10)%2 ==1){
//                color = monalisa.getColor(i, j);
//            }
//            monaleo.setColor(i,j,ofColor(sumR,sumG,sumB));
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
