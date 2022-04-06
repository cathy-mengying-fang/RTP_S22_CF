#pragma once

#include "ofMain.h"
#include "hand.h"
#include "ofxCv.h"
//#include "data.h"


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
		
        ofImage camGray;
    
    int interaction = 0;
    ofVideoGrabber cam;
//    HAND handl;
    HAND hand;
//    AxiSerial plot;
    float pz = -1;
    ofFbo fbo;
    ofFbo inp;
    
//    ofVideoPlayer player;
//    ContourFinder finder;
  
    vector < ofPolyline > lines;
    vector < ofPoint > pts;


};
