#ifndef _DOUBLELINKEDLIST_H_
#define _DOUBLELINKEDLIST_H_

#include "cinder/app/AppBasic.h"
#include "Node.h"

using namespace ci;
using namespace ci::app;
using namespace std;

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

	//Move node to front of list. Used for selecting the circle to draw with
	void moveToFront(Node* n);

	//Find clicked circle. This did not work for me either. I did not
	// have enough time to find the bug that was causing it to freeze.
	void findClickedCircle(int x1, int y1);

	//Update the data for each node
	void updateAll();

	//Update according to what will be updated on the sentinel->next node
	void update(int which);
};

#endif