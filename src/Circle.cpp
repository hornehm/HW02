#include "Circle.h"
#include "cinder/app/AppBasic.h"

using namespace ci;
using namespace std;

Circle::Circle(int x1, int y1, float r, Color8u c){
	x = x1;
	y = y1;
	radius = r;
	color = c;
}

float Circle::getRadius(){
	return radius;
}
int Circle::getX(){
	return x;
}
int Circle::getY(){
	return y;
}

void Circle::setX(int x1){
	x = x1;
}
void Circle::setY(int y1){
	y = y1;
}

void Circle::setRadius(float r){
	radius = r;
}

void Circle::draw(uint8_t* pixels, int boldness){
	float tmpRadius;
	for(int cy = 0; cy < appHeight-1; cy++){
		for(int cx = 0; cx < appWidth-1; cx++){
			//See if points are on circle
			tmpRadius = sqrt(((float)(cx-x)*(cx-x))+((float)(cy-y)*(cy-y)));
			//If the radius is within a certain range, change 9 surrounding pixels
			if((tmpRadius >= radius-boldness)&&(tmpRadius <= radius + boldness)){
				for(int i = cy; i < cy+2; i++){
					for(int j = cx; j < cx+2; j++){
						pixels[3*(cx+cy*textureSize)] = color.r;
						pixels[3*(cx+cy*textureSize) +1] = color.g;
						pixels[3*(cx+cy*textureSize) +2] = color.b;
					}
				}
		}
		
	}
}
}