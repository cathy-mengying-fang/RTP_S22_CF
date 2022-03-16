#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    davinci.load("davinci.jpg");
    monalisa.load("monalisa.jpg");
    lillian.load("lillian.jpg");
    monaleo.allocate(400,800,OF_IMAGE_COLOR);
    
    monalisa.draw(0,0);
    
    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA, 8);
    fbo.begin();
    ofClear(255, 255, 255, 0);
    fbo.end();
        

}

//--------------------------------------------------------------
void ofApp::update(){
//    for (int i = 0; i < 400; i++){
//        for (int j = 0; j < 800; j++){
//            float distance = ofDist(mouseX, mouseY, i, j);
//            if (distance < 100){
//                float pct = ofMap(distance, 0, 100, 1,0);
//                monaleo.setColor(i,j, ofColor(davinci.getColor(i,j)*pct + monalisa.getColor(i,j)*(1-pct)));
//
//            } else {
//                monaleo.setColor(i,j, ofColor(monalisa.getColor(i, j)));
//            }
//        }
//    }
//    monaleo.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
//    monaleo.draw(0,0);
//    davinci.draw(400,0,400,800);
//    monalisa.draw(0,0);
    fbo.draw(0,0);

        // draw what the user is drawing
        if (drawing) {
            drawCircle();
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
    
    if (key == 'c') {
            fbo.begin();
            ofClear(255, 255, 255, 0);
            fbo.end();
        }

        if (key == 'f') {
            fill = !fill;
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
    toCenter = glm::vec2(x,y);
//    for (int i = 0; i < 400; i++){
//        for (int j = 0; j < 800; j++){
//            float distance = ofDist(mouseX, mouseY, i, j);
//            if (distance < 100){
//                float pct = ofMap(distance, 0, 100, 1,0);
//                monaleo.setColor(i,j, ofColor(davinci.getColor(i,j)*pct + monalisa.getColor(i,j)*(1-pct)));
//
//            }
////                else {
////                monaleo.setColor(i,j, ofColor(monalisa.getColor(i, j)));
////            }
//        }
//    }
//    monaleo.update();

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    drawing = true;
       toCenter = glm::vec2(x,y);
       center = glm::vec2(x,y);
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    fbo.begin();
        drawCircle();
        fbo.end();
        drawing = false;
}

//ofColor ofApp::pickColor(){
////    int saturation = 255;
////    int brightness = 255;
////    int alpha = 200;
////    float sinOfTime = sin(ofGetElapsedTimef() * 0.5);
////    float hue = ofMap(sinOfTime, -1, 1, 0, 255);
////    ofColor c = ofColor::fromHsb(hue, saturation, brightness);
////    c.a = alpha;
//    ofColor c;
//    for (int i = 0; i < 400; i++){
//        for (int j = 0; j < 800; j++){
//            float distance = ofDist(mouseX, mouseY, i, j);
//            if (distance < 100){
//                float pct = ofMap(distance, 0, 100, 1,0);
//                c += ofColor(davinci.getColor(i,j)*pct + monalisa.getColor(i,j)*(1-pct));
//            }
//        }
//    }
//
//    return c;
//}

void ofApp::drawCircle(){
    ofPushStyle();
    auto c = pickColor();
    ofSetColor(c);
    ofSetCircleResolution(resolution);
    if (!fill) {
        ofSetLineWidth(ofMap(sin(ofGetElapsedTimef() * 2.0), -1, 1, 1, 10));
        ofNoFill();
    }
//    ofDrawCircle(center, glm::distance(center, toCenter));
    ofTexture();
    ofPopStyle();
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
