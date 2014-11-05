#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofDisableArbTex();
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
    tx0 = ofMap(mouseX, 0, ofGetWidth(), 0, 1);
    ty0 = ofMap(mouseY, 0, ofGetHeight(), 0, 1);
    tx1 = tx0 + 1;
    ty1 = ty0 + 1;
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
        xTexWrapMode%=7;
        
        xTexWrapConst = toConst(xTexWrapMode);
        xTexWrapString = toString(xTexWrapMode);
    }
    
    if (key == 'y') {
        yTexWrapMode++;
        yTexWrapMode%=7;
        
        yTexWrapConst = toConst(yTexWrapMode);
        yTexWrapString = toString(yTexWrapMode);
    }
    
    texture.setTextureWrap(xTexWrapConst, yTexWrapConst);
}

int ofApp::toConst(int texWrapMode) {
    switch (texWrapMode) {
        case 0:
            return GL_CLAMP;
        case 1:
            return GL_CLAMP_TO_BORDER;
        case 2:
            return GL_CLAMP_TO_EDGE;
        case 3:
            return GL_REPEAT;
        case 4:
            return GL_MIRRORED_REPEAT;
        case 5:
            return GL_MIRROR_CLAMP_ATI;
        case 6:
            return GL_MIRROR_CLAMP_TO_EDGE_ATI;
    }
}

string ofApp::toString(int texWrapMode) {
    switch (texWrapMode) {
        case 0:
            return "GL_CLAMP";
        case 1:
            return "GL_CLAMP_TO_BORDER";
        case 2:
            return "GL_CLAMP_TO_EDGE";
        case 3:
            return "GL_REPEAT";
        case 4:
            return "GL_MIRRORED_REPEAT";
        case 5:
            return "GL_MIRROR_CLAMP_ATI";
        case 6:
            return "GL_MIRROR_CLAMP_TO_EDGE_ATI";
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
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
