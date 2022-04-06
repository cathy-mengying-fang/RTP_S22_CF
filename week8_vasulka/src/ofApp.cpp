#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    grabber.listDevices();
    grabber.setDeviceID(1);
    
    grabber.setup(640, 480);
    
    img.allocate(grabber.getWidth(), grabber.getHeight(), OF_IMAGE_COLOR);
    
//    beat.load("sounds/jdee_beat.mp3");
//
//    beat.setLoop(true);
//    beat.play();
//
}

//--------------------------------------------------------------
void ofApp::update(){

    // update the sound playing system:
    ofSoundUpdate();
    
    
    // (4) we use velocity for volume of the samples:
//    float vel = sqrt(vx*vx + vy*vy);
    float prc = ofMap(mouseY, 0, ofGetHeight(),0,1);
    float vel = ofMap(prc,0,1,0,2);
    beat.setSpeed(vel);
//    cout << vel << endl;
    volume = MIN(vel/5.0f, 1);
//    cout << volume << endl;
    beat.setVolume(volume);
    
    

    // (5) grab the fft, and put in into a "smoothed" array,
    //        by taking maximums, as peaks and then smoothing downward
    float * val = ofSoundGetSpectrum(nBandsToGet);        // request 128 values for fft
//    float maxFFT;
    for (int i = 0;i < nBandsToGet; i++){
        
        // let the smoothed value sink to zero:
        fftSmoothed[i] *= 0.96f;
        
        // take the max, either the smoothed or the incoming:
        if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
    }

    
    
    
    grabber.update();
    if (grabber.isFrameNew()){
        
        ofImage imgTemp;
        images.push_back(imgTemp);
        images.back().setUseTexture(false);
        images.back().setFromPixels(grabber.getPixels());
        
        if (images.size() > 80){
            images.erase(images.begin());
        }
    }
//
//    if (images.size() > 0){
//        for (int y = 0; y < grabber.getHeight(); y++){
//            int whichImage = ofMap(y, 0, grabber.getHeight(), 0, images.size());
//                cout << whichImage << endl;
//            for (int x = 0; x < grabber.getWidth(); x++){
//                ofColor color = images[whichImage].getColor(x,y);
//                img.setColor(x, y, color);
//            }
//        }
//    }
//    img.update();
//
    
//     noise version
    
//    float time = ofGetElapsedTimef();
//
//    if (images.size() > 1){
//        for (int y = 0; y < grabber.getHeight(); y+=10){
//
//            for (int x = 0; x < grabber.getWidth(); x+=10){
//
//                float phaseShift = mouseX * 0.01;
//                float shiftX = ofMap(sin(ofGetElapsedTimef() + phaseShift), -1, 1, 0, grabber.getWidth());
//
//                int whichImage = ofMap(ofNoise(x+shiftX,
//                                               y, time), 0, 1, 0, images.size()-1);
//
//                    ofColor color = images[whichImage].getColor(x,y);
//                    img.setColor(x, y, color);
//                }
//        }
//    }
//    img.update();
    
    
    float time = ofGetElapsedTimef();

    if (images.size() > 1){

            for (int x = 0; x < grabber.getWidth(); x+=2){
                int whichImage = ofMap(x, 0, grabber.getWidth(), 0, images.size());
                for (int y = 0; y < grabber.getHeight(); y+=10){
                    float freq = ofMap(mouseX,0,ofGetWidth(),0,10);
                        cout << freq << endl;
                    float shiftX = ofMap(sin(ofGetElapsedTimef()*freq + x*0.001), -1, 1, -100, 100);

                    int xSelect = ofClamp(x+shiftX,0, grabber.getWidth());
                        ofColor color = images[whichImage].getColor(xSelect,y);
                        img.setColor(x, y, color);
                    }
        }
    }
    img.update();
    
    

    
}

//--------------------------------------------------------------
void ofApp::draw(){

//    grabber.draw(0,0);
    img.draw(grabber.getWidth(), 0);
    
    float width = (float)(5*128) / nBandsToGet;
    for (int i = 0;i < nBandsToGet; i++){
        // (we use negative height here, because we want to flip them
        // because the top corner is 0,0)
        ofDrawRectangle(100+i*width,ofGetHeight()-100,width,-(fftSmoothed[i] * 200));
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 's'){
        beat.setVolume(volume);
    }
    else if (key == 'e'){
        beat.setVolume(0);
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
