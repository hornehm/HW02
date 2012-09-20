#include "Circle.h"

Circle::Circle(Vec2f c, int r){
	center = c;
	radius = r;
}

Circle::Circle(){
	center = Vec2f(0.0, 0.0);
	radius = 0;
}

void Circle::draw(){
	gl::drawSolidCircle(center, radius);
}