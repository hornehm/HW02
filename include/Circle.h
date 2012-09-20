#include "cinder\gl\gl.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class Circle{
public:

	Circle(Vec2f c, int r);
	Circle();
	void draw();

private:
	Vec2f center;
	int radius;

};