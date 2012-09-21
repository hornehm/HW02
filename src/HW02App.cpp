/**
  *
  *CSE 274 B
  *@author Heather Horne
  *
  *
  *Right now all the classes are in this .cpp, I will try to 
  * fix this later. It includes the node class as well as the 
  * circle class.
  *
  *
  *
  **/



#include "cinder/app/AppBasic.h"
#include "cinder/gl/gl.h"
//#include "Node.h"
//#include "Circle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

/**
Circle Class
**/
class Circle{
public:

	Circle(int x1, int y1, int r);
	void draw();

private:
	int x, y;
	int radius;

};

Circle::Circle(int x1, int y1, int r){
	x = x1;
	y =y1;
	radius = r;
}

/**
Node Class
**/
class Node{
public:
	Node* prev;
	Node* next;
	Circle* data;

};

/**
HW02App
**/
class HW02App:public AppBasic {
  public:
	void setup();
	void mouseDown( MouseEvent event );	
	void update();
	void draw();
	void prepareSettings(Settings* settings);
	
private:
	static const int appWidth = 800;
	static const int appHeight = 600;
	Node* sentinel;
	void addToList(Node* sent, Circle* c);
};


void HW02App::prepareSettings(Settings* settings){
	settings->setWindowSize(appWidth, appHeight);
	settings->setResizable(false);
}
void HW02App::setup()
{
	//Make Circles!
	Circle* c1 = new Circle(100, 100, 10);
	Circle* c2 = new Circle(50, 50, 10);

	//Doubly Circular Node list
	sentinel = new Node();
	sentinel -> next = sentinel;
	sentinel -> prev = sentinel;
	addToList(sentinel, c1); 
	addToList(sentinel, c2);
	
}

void HW02App::addToList(Node* sent, Circle* c){
	//Add each new node after sentinel
	Node* n = new Node();
	n -> data = c;
	n -> next = sent->next;
	n ->prev = sent;
	sentinel->next->prev = n;
	sentinel->next = n;	
		
}

void HW02App::mouseDown( MouseEvent event )
{
	if(event.isLeft()){
		event.getX();
		event.getY();
	}
}



void HW02App::update()
{
	
}

void HW02App::draw()
{

	
}



CINDER_APP_BASIC( HW02App, RendererGl )


