#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("Insta");

	ofBackground(39);
	//ofNoFill();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	ofTranslate(ofGetWidth() * 0.5, ofGetHeight() * 0.5);

	int radius = 80;
	for (int x_index = -1; x_index <= 1; x_index++) {

		for (int y_index = -1; y_index <= 1; y_index++) {

			ofPoint location(x_index * 230, y_index * 230);
			ofPushMatrix();
			ofTranslate(location);

			for (int i = 0; i < 1; i++) {

				ofColor line_color;
				line_color.setHsb(ofRandom(255), 200, 255);
				ofSetColor(line_color);

				vector<ofPoint> vertices;
				ofBeginShape();
				for (int deg = 0; deg < 360; deg++) {

					ofPoint point = ofPoint(radius * cos(deg * DEG_TO_RAD), radius * sin(deg * DEG_TO_RAD));
					vertices.push_back(point * 0.85);
					float noise_value = ofNoise(ofRandom(100), point.x * 0.005, point.y * 0.005, ofGetFrameNum() * 0.01);
					if (noise_value > 0.5) { 
						
						point = ofPoint(radius * (noise_value + 0.5) * cos(deg * DEG_TO_RAD), radius * (noise_value + 0.5) * sin(deg * DEG_TO_RAD)); 
					}
					ofVertex(point);
				}

				ofNextContour(true);
				ofVertices(vertices);
				ofEndShape(true);
			}

			ofPopMatrix();
		}
	}
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}