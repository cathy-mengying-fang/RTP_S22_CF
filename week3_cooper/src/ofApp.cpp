#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
//    font.load("helvetica.ttf", 350, true, true, true);
    font.load("helvetica.ttf", 350);
//    font.drawStringAsShapes("5", 0, 0);
//      ofPixels pixels;
//      font.getFontTexture().readToPixels(pixels);
//
//      image.setFromPixels(pixels);
    ofEnableAlphaBlending();
#ifdef TARGET_OPENGLES
        shaderBlurX.load("shadersES2/shaderBlurX");
        shaderBlurY.load("shadersES2/shaderBlurY");
    #else
        if(ofIsGLProgrammableRenderer()){
            shaderBlurX.load("shadersGL3/shaderBlurX");
            shaderBlurY.load("shadersGL3/shaderBlurY");
        }else{
            shaderBlurX.load("shadersGL2/shaderBlurX");
            shaderBlurY.load("shadersGL2/shaderBlurY");
        }
    #endif

    // say how big you want each FBO to be
    fboBlurOnePass.allocate(800, 800);
    fboBlurTwoPass.allocate(800, 800);
    
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
    
    for (int num=0; num<7; num++){
        ofPushMatrix();
        ofTranslate(400+120*num, 550);
        font.drawString("5", 0, 0);
//        ofPixels pixels;
//        font.getFontTexture().readToPixels(pixels);
//        ofImage image;
//        image.setFromPixels(pixels);
        float blur = ofMap(mouseX, 0, ofGetWidth(), 0, 10, true);

        //----------------------------------------------------------
            fboBlurOnePass.begin();

        shaderBlurX.begin();
        shaderBlurX.setUniform1f("blurAmnt", blur);
        font.drawString("5", 0, 0);
//        image.draw(0,0);

        shaderBlurX.end();

        fboBlurOnePass.end();

        //----------------------------------------------------------
        fboBlurTwoPass.begin();

        shaderBlurY.begin();
        shaderBlurY.setUniform1f("blurAmnt", blur);

        fboBlurOnePass.draw(0,0);

        shaderBlurY.end();

        fboBlurTwoPass.end();

        //----------------------------------------------------------
        ofSetColor(colors[num%3]);
        fboBlurTwoPass.draw(0,0);

        
        
        
    
    
    
//    vector < ofPath > paths = font.getStringAsPoints("5");
//    for (int num=0; num<7; num++){
//        ofPushMatrix();
//        ofTranslate(400+120*num, 550);
//        for (int i=0; i<paths.size(); i++){
//            ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
////            paths[i].setColor(colors[num%3]);
////            paths[i].draw();
////            ofDisableBlendMode();
//
//            paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
//            vector < ofPolyline > lines = paths[i].getOutline();
//            for (int j=0; j<lines.size();j++){
////                ofEnableSmoothing();
//                lines[j].setClosed(true);
//                lines[j] = lines[j].getResampledBySpacing(10);
//                lines[j] = lines[j].getSmoothed(10);
////                ofSetColor(colors[num%3]);
////                for (int k=0; k<lines[j].size();k++){
////                    ofDrawCircle(lines[j][k],20);
////                }
//
//
//
//                ofPath smoothedPath;
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
//
////                float blur = ofMap(mouseX, 0, ofGetWidth(), 0, 10, true);
////
////                //----------------------------------------------------------
////                    fboBlurOnePass.begin();
////
////                shaderBlurX.begin();
////                shaderBlurX.setUniform1f("blurAmnt", blur);
////
////                smoothedPath.draw(0,0);
////
////                shaderBlurX.end();
////
////                    fboBlurOnePass.end();
////
////                //----------------------------------------------------------
////                    fboBlurTwoPass.begin();
////
////                shaderBlurY.begin();
////                shaderBlurY.setUniform1f("blurAmnt", blur);
////
////                    fboBlurOnePass.draw(0,0);
////
////                shaderBlurY.end();
////
////                    fboBlurTwoPass.end();
////
////                //----------------------------------------------------------
////                ofSetColor(colors[num%3]);
////                fboBlurTwoPass.draw(0,0);
//                smoothedPath.setColor(colors[num%3]);
//                smoothedPath.draw();
//
//
//            }
//            ofDisableBlendMode();
////
//        }
//
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
