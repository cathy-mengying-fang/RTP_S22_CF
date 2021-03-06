#pragma once

#include "ofMain.h"
#include "ofxCv.h"
#include "ofxGui.h"


using namespace ofxCv;

class ofApp : public ofBaseApp{

    public:
        void setup();
        void update();
        void draw();

        void keyPressed(int key);
        void keyReleased(int key);
        void mouseMoved(int x, int y );
        void mouseDragged(int x, int y, int button);
        void mousePressed(int x, int y, int button);
        void mouseReleased(int x, int y, int button);
        void mouseEntered(int x, int y);
        void mouseExited(int x, int y);
        void windowResized(int w, int h);
        void dragEvent(ofDragInfo dragInfo);
        void gotMessage(ofMessage msg);
    
    
        ofVideoGrabber grabber;
        ofImage camGray;
        ofImage bgGray;
        ofImage diffImg;
        ofImage threshImg;
        ContourFinder finder;
//        ofVideoPlayer grabber;
    
        bool bRecordBg = false;
        float thresVal = 10;
        
        vector <ofVec3f> centroids;
    
#define MAX_SHADOW 128
        ofPath shadow [MAX_SHADOW];
        int shadow_idx = 0;
    
    
    ofxPanel gui;
    ofxSlider<float> slider;
};
