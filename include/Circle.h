#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "cinder/app/AppBasic.h"
/**
 *Circle Class
 *
 *I used my circle draw method from homework number one. 
**/

using namespace ci;

class Circle{
public:
	//Constructor
	Circle(int x1, int y1, float r, Color8u c);

	//draw Circle
	void draw(uint8_t* pixels, int boldness);

	//Gets radius
	float getRadius();

	//Gets x
	int getX();
	
	//Gets y
	int getY();

	//Sets x to x1
	void setX(int x1);

	//Sets y to y1
	void setY(int y1);

	//Sets radius to r
	void setRadius(float r);

private:
	int x, y;
	float radius;
	Color8u color;

	static const int appWidth = 800;
	static const int appHeight = 600;
	static const int textureSize = 1024;
};

#endif