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
  *I would eventually like to use my shapes from homework 1, but I 
  * want to make sure I am getting the feel for this project 
  * before I do that.
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
	void draw(Color8u c);

private:
	int x, y;
	int radius;

};

Circle::Circle(int x1, int y1, int r){
	x = x1;
	y = y1;
	radius = r;
}

void Circle::draw(Color8u c){
	gl::drawSolidCircle(Vec2f(x, y), radius);
	gl::color(c);
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
	Node* current;
	void addToList(Node* sent, Circle* c);
};


void HW02App::prepareSettings(Settings* settings){
	settings->setWindowSize(appWidth, appHeight);
	settings->setResizable(false);
}
void HW02App::setup()
{
	//Make Circles!
	Circle* c1 = new Circle(100, 100, 50);
	Circle* c2 = new Circle(50, 50, 50);

	//Doubly Circular Node list
	sentinel = new Node();
	current = new Node();
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
	n -> prev = sent;
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
	//Used logic from Professor Brinkman's CSE 274 class
	current = sentinel->next;
	while(current != sentinel){
		current->data->draw(Color8u(255, 0, 0));
		current = current->next;
	}
}



CINDER_APP_BASIC( HW02App, RendererGl )


