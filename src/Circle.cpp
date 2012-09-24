#include "circle.h"
#include "cinder/gl/gl.h"

Circle::Circle(){
	x = 0;
	y = 0;
	radius = 0;
	color = Color8u(0, 0, 0);
}

Circle::Circle(int x1, int y1, int r, Color8u c){
	x = x1;
	y = y1;
	radius = r;
	color = c;
}

void Circle::draw(){
	gl::drawSolidCircle(Vec2f((float)x, (float)y), (float)radius);
	gl::color(color);
}
int Circle::getX(){
	return x;
}
int Circle::getY(){
	return y;
}
int Circle::getRadius(){
	return radius;
}
void Circle::setX(int x1){
	x = x1;
}
void Circle::setY(int y1){
	y = y1;
}
void Circle::setRadius(int r){
	radius = r;
}
void Circle::setColor(Color8u c){
	color = c;
}
