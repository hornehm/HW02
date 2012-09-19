#include "Circle.h"

Circle::Circle(Vec2f c, int r){
	center = c;
	radius = r;
}

void Circle::draw(){
	gl::drawSolidCircle(center, radius);
}