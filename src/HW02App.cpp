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
//#include "Node.h"
//#include "Circle.h"

using namespace ci;
using namespace ci::app;
using namespace std;

/**
 *Circle Class
 *
 *I used my circle draw method from homework number one. 
**/
class Circle{
public:
	//Constructor
	Circle(int x1, int y1, float r, Color8u c);

	//draw Circle
	void draw(uint8_t* pixels, int boldness);

	//Gets radius
	float getRadius();

	//Gets x
	int getX();
	
	//Gets y
	int getY();

	//Sets x to x1
	void setX(int x1);

	//Sets y to y1
	void setY(int y1);

	//Sets radius to r
	void setRadius(float r);

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

float Circle::getRadius(){
	return radius;
}
int Circle::getX(){
	return x;
}
int Circle::getY(){
	return y;
}

void Circle::setX(int x1){
	x = x1;
}
void Circle::setY(int y1){
	y = y1;
}

void Circle::setRadius(float r){
	radius = r;
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
 *Node Class
 *
 *I decided to do a double circular linked list as it seemed easier than 
 *the other ones.
**/
class Node{
public:
	Node* prev;
	Node* next;
	Circle* data;
	//Constructor for Node
	Node(Circle* new_data);

};

Node::Node(Circle* new_data){
	next = NULL;
	prev = NULL;
	data = new_data;
}


/*
*Double Linked List class
*
*This class helps me create my linked list and perform
*linked list functions
*/
class DoubleLinkedList{
public:
	//Default Constructor
	DoubleLinkedList();

	//Sentinel to keep track of list
	Node* sentinel;

	//Add nodes to list with Circle data
	void addToList(Circle* data);

	//Reverse the list so that the last item is first and vice versa
	void reverseList();

	//Draw all the data (circles)
	void drawAll(uint8_t* dataArr);

	//Move node to front of list. This did not work for me.
	void moveToFront(Node* n);

	//Find clicked circle. This did not work for me either. I did not
	// have enough time to find the bug that was causing it to freeze.
	void findClickedCircle(int x1, int y1);

	//Update the data for each node
	void updateAll();

	//Update according to what will be updated on the sentinel->next node
	void update(int which);
};

DoubleLinkedList::DoubleLinkedList(){
	sentinel = new Node(NULL);
	sentinel->next = sentinel;
	sentinel->prev = sentinel;
}

void DoubleLinkedList::update(int which){
	//Moves up
	if(which == 1){
		sentinel->next->data->setY((sentinel->next->data->getY())+20);
	}
	//Moves back
	if(which == 2){
		sentinel->next->data->setY((sentinel->next->data->getY())-20);
	}
	//Moves right
	if(which == 3){
		sentinel->next->data->setX((sentinel->next->data->getX())+20);
	}
	//Moves left
	if(which == 4){
		sentinel->next->data->setX((sentinel->next->data->getX())-20);
	}
	//Makes it jump?
	if(which == 5){
		sentinel->next->data->setRadius((sentinel->next->data->getRadius())+100);
	}
	}


void DoubleLinkedList::updateAll(){
	Node* current = sentinel->next;
	while(current != sentinel){
		current->data->setX((current->data->getX())+1);
		current->data->setY((current->data->getY())+1);
		current = current->next;
	}

}
void DoubleLinkedList::addToList(Circle* c){
	//Add each new node after sentinel
	Node* n = new Node(c);
	n -> next = sentinel->next;
	n -> prev = sentinel;
	sentinel->next->prev = n;
	sentinel->next = n;		
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
	Node* current = sentinel->prev;
	while(current != sentinel){
		current->data->draw(dataArr, 20);
		current = current->prev;
	}
}

void DoubleLinkedList::moveToFront(Node* n){
	n->next->prev = n->prev;
	n->prev->next = n->next;
	n->next = sentinel->next;
	n->prev = sentinel;
	sentinel->next->prev = n;
	sentinel->next = n;
}

void DoubleLinkedList::findClickedCircle(int x1, int y1){
	
	int distance;
	int rad;
	int x, y;
	Node* current = sentinel->next;
	
	while(current != sentinel){
		rad = (int)(current->data->getRadius());
		x = current->data->getX();
		y = current->data->getY();
		distance = (int)sqrt((float)(((x-x1)*(x-x1)) + ((y-y1)*(y-y1))));
		if(distance <= rad){
			moveToFront(current);
			current = sentinel;
		}
		current = current->next;
	}
}



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
	Circle* c2 = new Circle(300, 300, 50.0, Color8u(255, 0, 0));
	Circle* c3 = new Circle(400, 300, 50.0, Color8u(0, 255, 0));

	//Doubly Circular Node list
	list = new DoubleLinkedList();
	/*
	list->addToList(list->sentinel, c1);
	list->addToList(list->sentinel->next, c2);
	list->addToList(list->sentinel->next->next, c3);
	*/
	list->addToList(c1);
	list->addToList(c2);
	list->addToList(c3);

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
		//Circle* c = new Circle(event.getX(), event.getY(), 50, Color8u(100, 0, 100));
		//list->addToList(list->sentinel, c);
		//list->findClickedCircle(event.getX(), event.getY());
		x1 = (float) event.getX();
		y1 = (float) event.getY();
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
	}

void HW02App::update()
{
	uint8_t* dataArray = (*mySurface).getData();
	list->drawAll(dataArray);

}

void HW02App::draw()
{
	if(controls){
		std::string str("Welcome!\nPress '?' to enter and exit control description.\nPress '1' to reverse the circles.\nUse 'w' to move a circle up."
			 "\nUse 's' to move a circle down.\nUse 'a' to move a circle left.\nUse 'd' to move a circle right.\nUse w, a, s, or d while scrolling to make the circle move further.");
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


