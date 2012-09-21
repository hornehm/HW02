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

	Circle(int x1, int y1, int r, Color8u c);
	void draw();
	int getX();
	int getY();
	int getRadius();
	void setX(int x1);
	void setY(int y2);
	void setRadius(int r);

private:
	int x, y;
	int radius;
	Color8u color;
};

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
	void keyDown( KeyEvent event);
	void update();
	void draw();
	void prepareSettings(Settings* settings);
	
private:
	static const int appWidth = 800;
	static const int appHeight = 600;
	Node* sentinel;
	Node* current;
	void addToList(Circle* c);
	void findClickedCircle(int x, int y);
	void moveToFront(Node* n);
	void reverseList();
};


void HW02App::prepareSettings(Settings* settings){
	settings->setWindowSize(appWidth, appHeight);
	settings->setResizable(false);
}
void HW02App::setup()
{
	//Make Circles!
	Circle* c1 = new Circle(200, 300, 50, Color8u(0, 0, 255));
	Circle* c2 = new Circle(250, 300, 50, Color8u(255, 0, 0));
	Circle* c3 = new Circle(300, 300, 50, Color8u(0, 255, 0));

	//Doubly Circular Node list
	sentinel = new Node();
	current = new Node();
	sentinel -> next = sentinel;
	sentinel -> prev = sentinel;
	addToList(c1); 
	addToList(c2);
	addToList(c3);
	
	
}

void HW02App::addToList(Circle* c){
	//Add each new node after sentinel
	Node* n = new Node();
	n -> data = c;
	n -> next = sentinel->next;
	n -> prev = sentinel;
	sentinel->next->prev = n;
	sentinel->next = n;	
	if(sentinel->prev == sentinel){
		sentinel->prev = n;
	}
		
}

void HW02App::moveToFront(Node* n){
	n->next->prev = n->prev;
	n->prev->next = n->next;
	
	n->next = sentinel->next;
	n->prev = sentinel;
	sentinel->next->prev = n;
	sentinel->next = n;
}

void HW02App::findClickedCircle(int x1, int y1){
	
	int distance;
	int radius;
	int x, y;
	current = sentinel->prev;
	
	while(current != sentinel){

		radius = current->data->getRadius();
		x = current->data->getX();
		y = current->data->getY();

		distance = (int)sqrt((float)(((x-x1)*(x-x1)) - ((y-y1)*(y-y1))));
		
		if(distance < radius){
			moveToFront(current);
			current = sentinel;
		}
		current = current->prev;
	}
}

/*
*Syntax and logic from CSE 274
*/
void HW02App::reverseList(){
	Node* cur= sentinel;
	do{
		Node* tmp = cur->next;
		cur->next=cur->prev;
		cur->prev = tmp;
		cur = cur->prev;
	}while(cur!=sentinel);
}

void HW02App::mouseDown( MouseEvent event )
{
	int x1 = 0,  y1 = 0;
	if(event.isLeftDown()){
		/**
		x1 = event.getX();
		y1 = event.getY();
		findClickedCircle(x1, y1);
		**/
	}

}

void HW02App::keyDown( KeyEvent event){
	if(event.KEY_1){
		reverseList();
	}
}



void HW02App::update()
{
	
}

void HW02App::draw()
{
	//Used logic from Professor Brinkman's CSE 274 class
	//Draws each item in the linked list
	current = sentinel->next;
	while(current != sentinel){
		current->data->draw();
		current = current->next;
	}
}



CINDER_APP_BASIC( HW02App, RendererGl )


