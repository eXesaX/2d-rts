#pragma once
#include <string.h>
#include "Map.h"

void Map::setup(std::string mapBitmap, std::string minimapBitmap, int *winWidth, int *winHeight) {
	map.load(mapBitmap);
	minimap.load(minimapBitmap);

	width = map.getWidth();
	height = map.getHeight();
	minimapHeight = minimap.getHeight();
	minimapWidth = minimap.getWidth();
	center.x = 0.0;
	center.y = 0.0;

	windowWidth = winWidth;
	windowHeight = winHeight;
}

void Map::draw() {
	map.draw(width * center.x + *windowHeight / 2, height * center.y + *windowWidth / 2);
}

void Map::drawMinimap() {
	minimap.draw(0, *windowHeight - minimap.getHeight());
	ofSetColor(255, 255, 0);
	float w = map.getWidth() / *windowWidth;
	float h = map.getHeight() / *windowHeight;

	float x1 = minimap.getWidth() * -center.x - w / 2;
	float y1 = minimap.getHeight() * -center.y + *windowHeight - minimap.getHeight() - h / 2;


	ofDrawRectangle(x1, y1, w, h);
	ofSetColor(255, 255, 255);
}

ofPoint Map::getCameraCenter() {
	return center;
}

void Map::setCameraCenter(ofPoint center) {
	this->center = center;
}

void Map::scrollOn(ofPoint delta) {
	center += delta;
	if (center.x > 1) {
		center.x = 1;
	}
	if (center.y > 1) {
		center.y = 1;
	}
	if (center.x < -1) {
		center.x = -1;
	}
	if (center.y < -1) {
		center.y = -1;
	}
}

void Map::mouseMinimapCallback(int x, int y) {
	float centerX = -x / minimap.getWidth();
	float centerY = -(1+(y - *windowHeight) / minimap.getHeight());

	setCameraCenter(ofPoint(centerX, centerY));
}