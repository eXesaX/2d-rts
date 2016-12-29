#pragma once
#include <string>
#include "ofMain.h"

class Map {
	public:
		void setup(std::string mapBitmap, std::string minimapBitmap, int *winWidth, int *winHeight);
		void draw();
		void drawMinimap();
		ofPoint getCameraCenter();
		void setCameraCenter(ofPoint center);
		void scrollOn(ofPoint delta);
		void mouseMinimapCallback(int x, int y);
	private:
		ofPoint center;
		int width;
		int height;
		int minimapHeight;
		int minimapWidth;
		ofImage map;
		ofImage minimap;
		int *windowWidth;
		int *windowHeight;
};