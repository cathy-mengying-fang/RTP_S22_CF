#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    ofDirectory dir;
    dir.listDir("villain");
    for (int i = 0; i < dir.size(); i++){
        ofImage img;
        images.push_back(img);
        images.back().load(dir.getPath(i));
        cout << "loaded " << i << " of " << dir.size() << endl;
        
//        ofRectangle targetDim(0,0,640,480);
//        ofRectangle imageDim(0,0,images.back().getWidth(),
//                             images.back().getHeight());
//
//        targetDim.scaleTo(imageDim);
//
//        images.back().crop(targetDim.x, targetDim.y, targetDim.width, targetDim.height);
//        images.back().resize(640,480);
        
    }
    
    average.allocate(images[0].getWidth(),images[0].getHeight(), OF_IMAGE_COLOR);
    
    for (int i = 0; i < images[0].getWidth(); i++){
        for (int j = 0; j < images[0].getHeight(); j++){
            
            // average:
            // (1) add all values up
            float sumRed = 0;
            float sumBlue = 0;
            float sumGreen = 0;
            for (int k = 0; k < images.size(); k++){
                ofColor color = images[k].getColor(i,j);
                sumRed += color.r;
               
                sumGreen += color.g;
                 sumBlue += color.b;
            }
            // (2) divide
            sumRed /= (float)images.size();
            sumBlue /= (float)images.size();
            sumGreen /= (float)images.size();
            average.setColor(i,j, ofColor(sumRed, sumGreen, sumBlue));
            
            
        }
    }
    
    average.update();
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){

    average.draw(0,0);
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
