#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "Figures.h"

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
	Figures* figuresList;
	static const int appWidth = 800;
	static const int appHeight = 600;
};

void HW02App::prepareSettings(Settings* settings){
	settings->setWindowSize(appWidth, appHeight);
	settings->setResizable(false);
}
void HW02App::setup()
{
	figuresList = new Figures(appWidth/2, appHeight/2, 100);
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
	// clear out the window with black
	gl::clear( Color( 0, 0, 0 ) ); 


}

CINDER_APP_BASIC( HW02App, RendererGl )
