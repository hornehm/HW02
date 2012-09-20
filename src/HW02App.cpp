#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Circle.h"
#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

class HW02App : public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings(Settings* settings);

private:
	Node* last;
	Node* start;
	static const int appWidth = 800;
	static const int appHeight = 600;
	Circle* c1;
	Circle* c2;
};

void HW02App::prepareSettings(Settings* settings){
	settings->setWindowSize(appWidth, appHeight);
	settings->setResizable(false);
}
void HW02App::setup()
{
	//Make Circles!
	c1 = new Circle(Vec2f(50.0, 50.0), 10);
	c2 = new Circle(Vec2f(100.0, 100.0), 10);

	//Node list
	start = NULL;
	last = NULL;

	for(int i = 0; i < 2; i++){
		start = new Node(start*, c1);
		start -> next = start;
		
		  
	}

}

void HW02App::mouseDown( MouseEvent event )
{
	if(event.isLeft()){

	}
}

void HW02App::update()
{

}

void HW02App::draw()
{
	

}

CINDER_APP_BASIC( HW02App, RendererGl )
