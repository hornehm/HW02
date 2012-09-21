#include "cinder/gl/gl.h"
#include "cinder/app/AppBasic.h"
#include "Circle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

Circle::Circle(int x1, int y1, int r){
	x = x1;
	y =y1;
	radius = r;
}


void Circle::draw(){
	//gl::drawSolidCircle(, radius);
}