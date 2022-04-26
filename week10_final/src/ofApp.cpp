#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

    
//    grabber.load("cathy_brush.MOV");
//    grabber.play();
//    grabber.setLoopState(OF_LOOP_NORMAL);


    grabber.listDevices();
    grabber.setDeviceID(1);
    grabber.initGrabber(640, 480);
    
    camGray.allocate(grabber.getWidth(),
                     grabber.getHeight(),
                     OF_IMAGE_GRAYSCALE);
    
    bgGray.allocate(grabber.getWidth(),
                    grabber.getHeight(),
                    OF_IMAGE_GRAYSCALE);
    
    diffImg.allocate(grabber.getWidth(),
                    grabber.getHeight(),
                    OF_IMAGE_GRAYSCALE);
    
    
    threshImg.allocate(grabber.getWidth(),
                      grabber.getHeight(),
                      OF_IMAGE_GRAYSCALE);
    
    bRecordBg = true;
//    gui.setup();
//    gui.add(slider.setup("threshold",0,1,0.5));
    
}

//--------------------------------------------------------------
void ofApp::update(){

    
    grabber.update();
    if (grabber.isFrameNew()){

        convertColor(grabber,camGray, CV_RGB2GRAY );
        camGray.update();
        
        if (bRecordBg){
            bgGray.setFromPixels(camGray.getPixels());
            bgGray.update();
            bRecordBg = false;
        }
        
        absdiff(camGray, bgGray, diffImg);
        diffImg.update();
        
        threshImg.setFromPixels(diffImg.getPixels());
//        thresVal = slider;
        threshold(threshImg, thresVal);
        
        
        threshImg.update();
        
        finder.setSortBySize(true);
//        finder.setMinArea(10);
        
        finder.findContours(threshImg);
        
        
        
    }
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofPushMatrix();
    ofSetBackgroundAuto(false);
    ofSetColor(255,10);
//    ofScale(2, 2);
//    ofSetColor(80);
//    grabber.draw(10,10);
    
//    camGray.draw(grabber.getWidth(), 0);
//    bgGray.draw(0, grabber.getHeight());
//    diffImg.draw(grabber.getWidth(), grabber.getHeight());
//    threshImg.draw(grabber.getWidth()*2, 0);
    
    bgGray.draw(grabber.getWidth()+20, 10);
    diffImg.draw(10, grabber.getHeight()+20);
    threshImg.draw(grabber.getWidth()+20, grabber.getHeight()+20);
    ofSetColor(255,10);
//    ofDrawRectangle(0,0,1024,768);
    ofDrawRectangle(10, grabber.getHeight()+20, grabber.getWidth(), grabber.getHeight());
    
    ofPath path;
    
    if (finder.size() > 0){
        ofPolyline line = finder.getPolyline(0);
        
        ofPoint center;
        
        
        for( int i = 0; i < line.getVertices().size(); i++) {
            if(i == 0) {
                path.newSubPath();
                path.moveTo(line.getVertices()[i] );
            } else {
                path.lineTo(line.getVertices()[i] );
            }
        }
        path.close();
        path.simplify();
        
        //todo: add delay, noise
        // add GUI
        center.set(line.getCentroid2D());
//        centroids.push_back(center);
        
        
        
       
        
//        path.translate(-center);
//        path.scale(0.1,0.1);
//        float shiftX = ofMap(sin(ofGetElapsedTimef()*1.5 + 0.001), -1, 1, -5, 5);
//        float shiftY = ofMap(sin(ofGetElapsedTimef()*1.5 + 0.001), -1, 1, -5, 5);
//         center.set(center.x + shiftX), center.y+shiftY,center.z;
//        cout<<center<<endl;
//        path.translate(center);
        
//        ofSetColor(0,255);
   
    }
    shadow[shadow_idx] = path;
    shadow_idx = (shadow_idx + 1)% MAX_SHADOW;
    ofPath oldshadow = shadow[(shadow_idx + MAX_SHADOW - 10) % MAX_SHADOW];
    oldshadow.setColor(ofColor(0));
    oldshadow.draw(10, grabber.getHeight()+20);
//    oldshadow.draw(200,200);
    
    ofPopMatrix();
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

    if (key == ' ' ){
        bRecordBg = true;
    }
    if (key == 's' ){
        thresVal = mouseX;
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
