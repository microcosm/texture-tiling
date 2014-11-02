#pragma once

#include "ofMain.h"

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
    void windowResized(int w, int h);
    void dragEvent(ofDragInfo dragInfo);
    void gotMessage(ofMessage msg);
    
    ofImage image;
    ofTexture texture;
    ofPlanePrimitive plane;
    
    float tx0, ty0, tx1, ty1, px0, py0, px1, py1;
    
    int xTexWrapMode, yTexWrapMode, xTexWrapConst, yTexWrapConst;
    string xTexWrapString, yTexWrapString;
};
