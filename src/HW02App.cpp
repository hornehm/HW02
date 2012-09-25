/**
  *
  *CSE 274 B
  *@author Heather Horne
  *
  *This assignment satisfies A, B, D, and E for Homework #2. I realize this
  *is all in one .cpp file, but I had a hard time putting each class in their 
  *separate .cpp and .h files.
  *
  *I've used code from Dr. Brinkman's CSE 274 Class.
  *
  **/

#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/TextureFont.h"
#include "DoubleLinkedList.h"
#include "Node.h"
#include "Circle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

/**
*HW02App
*
*I tried first using open gl, but turned to using a surface instead.
* Unfortunately, it ended up working really well. I just wish I would have 
* done it sooner.
**/
class HW02App:public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void keyDown( KeyEvent event);
	void update();
	void draw();
	void prepareSettings(Settings* settings);
	void mouseScroll(MouseEvent event);	

private:

	static const int appWidth = 800;
	static const int appHeight = 600;
	static const int textureSize = 1024;


	DoubleLinkedList* list;
	bool controls;

	//Surface
	Surface* mySurface;
	uint8_t* dataArray;

	//Font for message
	Font f;
	gl::TextureFontRef textFont;
};


void HW02App::prepareSettings(Settings* settings){
	settings->setWindowSize(appWidth, appHeight);
	settings->setResizable(false);
}
void HW02App::setup()
{
	mySurface = new Surface(textureSize, textureSize, false);

	//Make Circles!
	Circle* c1 = new Circle(200, 300, 50.0, Color8u(0, 0, 255));
	Circle* c2 = new Circle(100, 300, 50.0, Color8u(255, 0, 0));
	Circle* c3 = new Circle(300, 300, 50.0, Color8u(0, 255, 0));
	Circle* c4 = new Circle(400, 300, 50.0, Color8u(255, 255, 255));
	
	//Doubly Circular Node list
	list = new DoubleLinkedList();
	list->addToList(c1);
	list->addToList(c2);
	list->addToList(c3);
	list->addToList(c4);

	//Set controls to true to show them
	controls = true;

	//set up font
	f = Font( "Arial", 24 );
	textFont = gl::TextureFont::create(f);
}


void HW02App::mouseScroll(MouseEvent event){
	float wheel;
	wheel = event.getWheelIncrement();
	list->update(5);
}


void HW02App::mouseDown( MouseEvent event )
{
	int x1 = 0,  y1 = 0;
	if(event.isLeftDown()){
		x1 = event.getX();
		y1 = event.getY();
		Circle* c = new Circle(x1, y1, 50.0, Color8u(100, 0, 100));
		list->addToList(c);
	}
}

void HW02App::keyDown( KeyEvent event){
	//if 1, reverse the list
	if(event.getChar() == '1'){
		list->reverseList();
	}
	//if ?, display controls
	if(event.getChar()== '?'){
		controls = !controls;
		}	
	//if s, move down
	if(event.getChar() == 's'){
		list->update(1);
	}
	//if w, move up
	if(event.getChar() == 'w'){
		list->update(2);
	}
	//if d, move left
	if(event.getChar() == 'd'){
		list->update(3);
	}
	//if a, move right
	if(event.getChar() == 'a'){
		list->update(4);
	}
	if(event.getChar() == '2'){
		list->moveToFront(list->sentinel->prev);
	}
	}

void HW02App::update()
{
	uint8_t* dataArray = (*mySurface).getData();
	list->drawAll(dataArray);

}

void HW02App::draw()
{
	if(controls){
		std::string str("Welcome! This app allows you to use circles to draw colorful backgrounds.\n\n\n\n"
			"Press '?' to enter and exit control description.\nPress '1' to reverse the circles.\nPress '2' to select a circle"
			" to draw with.\nPress 'w' to move a circle up."
			 "\nPress 's' to move a circle down.\nPress 'a' to move a circle left.\nPress 'd' to move a circle right."
			 "\nPress w, a, s, or d while scrolling to make the circle move further."
			 "\nLeft-Click to add a purple circle!");
		gl::color(Color8u(0, 0, 0));
		gl::enableAlphaBlending();
		gl::color(Color(255, 50, 50));
		Rectf boundsRect( 40, textFont->getAscent() + 40, getWindowWidth() - 40, 
				getWindowHeight() - 40 );
		textFont ->drawStringWrapped(str, boundsRect);
		gl::color(Color8u(255, 255, 255));
	}
	else{
	gl::clear(Color(0, 0, 0));
	gl::draw(*mySurface);
	}
}



CINDER_APP_BASIC( HW02App, RendererGl )


