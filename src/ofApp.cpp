#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    image.loadImage("seamless_wood_planks_texture_by_10ravens-d3991v1.jpg");
    texture = image.getTextureReference();
    
    
    xTexWrapMode = yTexWrapMode = 0;
    xTexWrapConst = yTexWrapConst = GL_CLAMP;
    xTexWrapString = yTexWrapString = "GL_CLAMP";
    texture.setTextureWrap(xTexWrapConst, yTexWrapConst);
    
    plane.set(400, 400);
    plane.mapTexCoords(0, 0, texture.getWidth(), texture.getHeight());
    
    ofBackground(25);

    //    px0 = ofGetWidth()/2 - 200;
    //    py0 = ofGetHeight()/2 - 200;
    //    px1 = ofGetWidth()/2 + 200;
    //    py1 = ofGetHeight()/2 + 200;
}

//--------------------------------------------------------------
void ofApp::update(){
    tx0 = mouseX;
    ty0 = mouseY;
    tx1 = mouseX + texture.getWidth();
    ty1 = mouseY + texture.getHeight();
    
    plane.mapTexCoords(tx0, ty0, tx1, ty1);
}

//--------------------------------------------------------------
void ofApp::draw(){
    texture.bind();
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    plane.draw();
    //    glBegin( GL_QUADS );
    //    glTexCoord2f(tx0,ty0);			glVertex3i(px0, py0,0);
    //    glTexCoord2f(tx1,ty0);			glVertex3i(px1, py0,0);
    //    glTexCoord2f(tx1,ty1);			glVertex3i(px1, py1,0);
    //    glTexCoord2f(tx0,ty1);			glVertex3i(px0, py1,0);
    //    glEnd();
    ofPopMatrix();
    
    texture.unbind();
    
    ofDrawBitmapString("move mouse to displace texture \n'x' - horizontal wrap mode: " + xTexWrapString + "\n" + "'y' - vertical wrap mode: " + yTexWrapString, 20,20);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'x') {
        xTexWrapMode++;
        xTexWrapMode%=3;
        
        switch (xTexWrapMode) {
            case 0:
                xTexWrapConst = GL_CLAMP;
                xTexWrapString = "GL_CLAMP";
                break;
                
            case 1:
                xTexWrapConst = GL_CLAMP_TO_BORDER;
                xTexWrapString = "GL_CLAMP_TO_BORDER";
                break;
                
            case 2:
                xTexWrapConst = GL_CLAMP_TO_EDGE;
                xTexWrapString = "GL_CLAMP_TO_EDGE";
                break;
                
        }
    }
    
    if (key == 'y') {
        yTexWrapMode++;
        yTexWrapMode%=3;
        
        switch (yTexWrapMode) {
            case 0:
                yTexWrapConst = GL_CLAMP;
                yTexWrapString = "GL_CLAMP";
                break;
                
            case 1:
                yTexWrapConst = GL_CLAMP_TO_BORDER;
                yTexWrapString = "GL_CLAMP_TO_BORDER";
                break;
                
            case 2:
                yTexWrapConst = GL_CLAMP_TO_EDGE;
                yTexWrapString = "GL_CLAMP_TO_EDGE";
                break;
        }
    }
    
    
    
    texture.setTextureWrap(xTexWrapConst, yTexWrapConst);
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
