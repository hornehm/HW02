#pragma once

#include "cinder/app/AppBasic.h"

/**
Circle Class
**/
class Circle{
public:

	Circle(int x1, int y1, int r, Color8u c);
	void draw();
	int getX();
	int getY();
	int getRadius();
	void setX(int x1);
	void setY(int y2);
	void setRadius(int r);

private:
	int x, y;
	int radius;
	Color8u color;
};