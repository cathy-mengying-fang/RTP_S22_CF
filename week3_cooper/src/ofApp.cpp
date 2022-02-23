#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("helvetica.ttf", 350, true, true, true);
    ofEnableAlphaBlending();
    shaderBlurX.load("shadersGL3/shaderBlurX");
    shaderBlurY.load("shadersGL3/shaderBlurY");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofBackground(194,176,159);
//    ofBackground(255,255,255,255);
//    int alpha = 3;
    ofColor red = ofColor(163,65,55);
    ofColor yellow = ofColor(195,159,54);
    ofColor blue = ofColor(17,97,118);
    ofColor colors [3] = {red,yellow,blue};
    
    vector < ofPath > paths = font.getStringAsPoints("5");
    for (int num=0; num<7; num++){
        ofPushMatrix();
        ofTranslate(400+120*num, 550);
        for (int i=0; i<paths.size(); i++){
            ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
            paths[i].setColor(colors[num%3]);
            paths[i].draw();
//            ofDisableBlendMode();
           
            paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
            vector < ofPolyline > lines = paths[i].getOutline();
            for (int j=0; j<lines.size();j++){
//                ofEnableSmoothing();
                lines[j].setClosed(true);
                lines[j] = lines[j].getResampledBySpacing(10);
//                lines[j] = lines[j].getSmoothed(10);
                ofSetColor(colors[num%3],2);
                for (int k=0; k<lines[j].size();k++){
                    ofDrawCircle(lines[j][k],20);
                }
                
                
                
/*                ofPath smoothedPath;
//                ofPolyline smoothedPolyline = lines[j];
////                https://forum.openframeworks.cc/t/fill-polyline/10800/2
//                for( int k = 0; k < smoothedPolyline.getVertices().size(); k++) {
//                        if(k == 0) {
//                            smoothedPath.newSubPath();
//                            smoothedPath.moveTo(smoothedPolyline.getVertices()[k] );
//                        } else {
//                            smoothedPath.lineTo(smoothedPolyline.getVertices()[k] );
//                        }
//                    }
//                smoothedPath.close();
//                smoothedPath.setColor(colors[num%3]);
//                smoothedPath.draw();
*/
                
            }
            ofDisableBlendMode();
//
        }
        
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
