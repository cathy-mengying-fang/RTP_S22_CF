
//Hand tracking adapted code from Lingdong Huang: https://lingdong.works
//video example from Zach Lieberman


#include "ofApp.h"

//#include "data.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
//    player.load("input.mov");
//    player.play();
//    player.setLoopState(OF_LOOP_NORMAL);
    
    cam.listDevices();
    cam.setDeviceID(2);
    cam.initGrabber(640,480);
    
    fbo.allocate(640,480);
    inp.allocate(640,480);
    
//    for (int i = 0; i < 100; i++){
//        float x = ofMap(i, 0, 100, 0, cam.getWidth());
//        float y = 0;
//        ofPoint pt;
//        pt.set(x,y);
//        pts.push_back(pt);
//    }
    

}

//--------------------------------------------------------------
void ofApp::update(){
    
   
    cam.update();
    if (cam.isFrameNew()){
      ofPixels pixels;
      inp.readToPixels(pixels);

      hand.detect(pixels);
    }
    
//    player.update();
//    if (player.isFrameNew()){
//        finder.findContours(player);
//    }
    
    float x0 = hand.index.x;
    float y0 = hand.index.y;
    float x1 = hand.index.x;
    float y1 = hand.index.y;
    float d = ofDist(x0,y0,x1,y1);
    
//    for (int i = 0; i < 100; i++){
//
////        ofColor color = threshold.getColor(pts[i].x, pts[i].y);
//
//        if (pts[i].x<x1 or pts[i].x>x0){
//            pts[i].y += 1;
//        } else {
//            for (int j = pts[i].y; j >= 0; j--){
////                ofColor check = threshold.getColor(pts[i].x, j);
//                if (pts[i].y<y1 or pts[i].y>y0){
//                    pts[i].y = j;
//                    break;
//                }
//            }
//
//        }
//        if (pts[i].y >= cam.getHeight()){
//            pts[i].y = 0;
//        }
//    }
//

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    float x0 = hand.index.x;
    float y0 = hand.index.y;
    float x1 = hand.index.x;
    float y1 = hand.index.y;
    float d = ofDist(x0,y0,x1,y1);
    float z = ofClamp(ofMap(d,5,100,0,1),0,1);
    
//    if (interaction == 1){
//      if (fabs(z-pz) > 0.05){
//        plot.penz(z);
//        pz = z;
//      }
//      float x = (x0 + x1)/2;
//      float y = (y0 + y1)/2;
//      plot.moveabs(x*10,y*10);
//      fbo.begin();
//      ofDrawCircle(x,y,20-z*20);
//      fbo.end();
//
//    }else if (interaction == 2){
//      float x = x1;
//      float y = y1;
//      plot.moveabs(x*10,y*10);
//      fbo.begin();
//      ofDrawCircle(x,y,10);
//      fbo.end();
//    }
//    
    inp.begin();
    cam.draw(640+160,480+120,-640*1.5,-480*1.5);
//    cam.draw(0,0);
    inp.end();
    
    
    inp.draw(0,0);
    fbo.draw(0,0);
    
    ofPushStyle();
    ofNoFill();
    ofSetLineWidth(3);
    ofSetColor(0,255,0);
    ofDrawLine(x0,y0,x1,y1);
    ofPopStyle();
    
//    ofPushStyle();
//    ofSetColor(255,0,0);
//    for (int i = 0; i < 100; i++){
//        ofDrawCircle(pts[i].x, pts[i].y, 3);
//    }
//    ofPopStyle();
    
//    player.draw(x0,y0);
//
//    ofTranslate(0,0);
//    ofScale(2,2);
//
//    if (finder.size() > 0){
//        ofPolyline line = finder.getPolyline(0);
//
//
//        ofPoint top;
//        for (int i = 0; i<line.size(); i++){
//            if (i==0){
//                top = line[i];
//            }
//            else if (line[i].y < top.y){
//                top = line[i];
//            }
//        }
//
//        line.getSmoothed(ofDist(x0,y0,top.x,top.y));
//        line.draw();
////        line = line.getResampledBySpacing(0.5);
////        line = line.getSmoothed(3);
////        line.draw();
////
////        lines.push_back(line);
////        if (lines.size() > 100){
////            lines.erase(lines.begin());
////        }
////        for (int i = 0; i < lines.size(); i++){
////            lines[i].draw();
////        }
//
//    }
    
    
    
   

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

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
