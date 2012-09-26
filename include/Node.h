#ifndef _NODE_H_
#define _NODE_H_

#include "Circle.h"
#include "cinder/app/AppBasic.h"

using namespace ci;
using namespace ci::app;
using namespace std;

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

#endif