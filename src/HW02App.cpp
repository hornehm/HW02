#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Circle.h"
#include "NodeList.h"

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
	static const int appWidth = 800;
	static const int appHeight = 600;
};

void HW02App::prepareSettings(Settings* settings){
	settings->setWindowSize(appWidth, appHeight);
	settings->setResizable(false);
}
void HW02App::setup()
{
	
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
