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
#include "cinder/gl/Texture.h"
#include "cinder/gl/TextureFont.h"
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

	Circle(int x1, int y1, float r, Color8u c);
	void draw(uint8_t* pixels, int boldness);

private:
	int x, y;
	float radius;
	Color8u color;

	static const int appWidth = 800;
	static const int appHeight = 600;
	static const int textureSize = 1024;
};

Circle::Circle(int x1, int y1, float r, Color8u c){
	x = x1;
	y = y1;
	radius = r;
	color = c;
}

void Circle::draw(uint8_t* pixels, int boldness){
	float tmpRadius;
	for(int cy = 0; cy < appHeight-1; cy++){
		for(int cx = 0; cx < appWidth-1; cx++){
			//See if points are on circle
			tmpRadius = sqrt(((float)(cx-x)*(cx-x))+((float)(cy-y)*(cy-y)));
			//If the radius is within a certain range, change 9 surrounding pixels
			if((tmpRadius >= radius-boldness)&&(tmpRadius <= radius + boldness)){
				for(int i = cy; i < cy+2; i++){
					for(int j = cx; j < cx+2; j++){
						pixels[3*(cx+cy*textureSize)] = color.r;
						pixels[3*(cx+cy*textureSize) +1] = color.g;
						pixels[3*(cx+cy*textureSize) +2] = color.b;
					}
				}
		}
	}
}
}

/**
Node Class
**/
class Node{
public:
	Node* prev;
	Node* next;
	Circle* data;
	Node(Circle* new_data);

};

Node::Node(Circle* new_data){
	next = NULL;
	prev = NULL;
	data = new_data;
}

class DoubleLinkedList{
public:
	DoubleLinkedList();
	Node* sentinel;
	void addToList(Node* tmp, Circle* data);
	void reverseList();
	void drawAll(uint8_t* dataArr);
};

DoubleLinkedList::DoubleLinkedList(){
	sentinel = new Node(NULL);
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
}


void DoubleLinkedList::addToList(Node* tmp, Circle* c){
	//Add each new node after sentinel
	Node* n = new Node(c);
	n -> next = tmp->next;
	n -> prev = tmp;
	tmp->next->prev = n;
	tmp->next = n;		
}

/*
*Syntax and logic from CSE 274
*/
void DoubleLinkedList::reverseList(){
	Node* cur= sentinel;
	do{
		Node* tmp = cur->next;
		cur->next=cur->prev;
		cur->prev = tmp;
		cur = cur->prev;
	}while(cur!=sentinel);
}

void DoubleLinkedList::drawAll(uint8_t* dataArr){
	Node* current = sentinel->next;
	while(current != sentinel){
		current->data->draw(dataArr, 20);
		current = current->next;
	}
}



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
	static const int textureSize = 1024;
	//void findClickedCircle(int x, int y);
	//void moveToFront(Node* n);
	DoubleLinkedList* list;
	bool question;
	Surface* mySurface;
	uint8_t* dataArray;
};


void HW02App::prepareSettings(Settings* settings){
	settings->setWindowSize(appWidth, appHeight);
	settings->setResizable(false);
}
void HW02App::setup()
{
	mySurface = new Surface(textureSize, textureSize, false);

	//Make Circles!

	question = false;
	
	
}


/*
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
*/

void HW02App::mouseDown( MouseEvent event )
{
	int x1 = 0,  y1 = 0;
	if(event.isLeftDown()){
		Circle* c = new Circle(event.getX(), event.getY(), 50, Color8u(100, 0, 100));
		list->addToList(list->sentinel, c);
		/**
		x1 = event.getX();
		y1 = event.getY();
		findClickedCircle(x1, y1);
		**/
	}

}

void HW02App::keyDown( KeyEvent event){
	Font f = Font( "Arial", 24 );
	gl::TextureFontRef textFont;
	if(event.getChar() == '1'){
		list->reverseList();
	}
	if(event.getChar()== '?'){
		//Lucy's code from CSE 274
		// Move elsewhere
		question = !question;
		if(question == true){
			
			textFont = gl::TextureFont::create(f);
			std::string str("Press '1' to reverse the circles");
			gl::color(Color8u(255, 0, 0));
			gl::enableAlphaBlending();
			Rectf boundsRect( 40, textFont->getAscent() + 40, getWindowWidth() - 40, getWindowHeight() - 40 );
			textFont ->drawStringWrapped(str, boundsRect);
			
		}
		else{
			
			textFont = gl::TextureFont::create(f);
			std::string str("Press '1' to reverse the circles");
			gl::color(Color8u(0, 0, 0));
			gl::enableAlphaBlending();
			Rectf boundsRect( 40, textFont->getAscent() + 40, getWindowWidth() - 40, getWindowHeight() - 40 );
			textFont ->drawStringWrapped(str, boundsRect);
			
		}
	}
}



void HW02App::update()
{
	uint8_t* dataArray = (*mySurface).getData();

	Circle* c1 = new Circle(200, 300, 50.0, Color8u(0, 0, 255));
	Circle* c2 = new Circle(250, 300, 50.0, Color8u(255, 0, 0));
	Circle* c3 = new Circle(300, 300, 50.0, Color8u(0, 255, 0));

	//Doubly Circular Node list
	list = new DoubleLinkedList();
	list->addToList(list->sentinel, c1);
	list->addToList(list->sentinel->next, c2);
	list->addToList(list->sentinel->next->next, c3);

	list->drawAll(dataArray);

}

void HW02App::draw()
{
	//Used logic from Professor Brinkman's CSE 274 class
	//Draws each item in the linked list

	gl::draw(*mySurface);
}



CINDER_APP_BASIC( HW02App, RendererGl )


