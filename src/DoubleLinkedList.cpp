#include "DoubleLinkedList.h"
#include "Circle.h"


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

//The first one added is the end of the list.
// Each new node added becomes the head of the list.
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
	Node* current = sentinel->next;
	while(current != sentinel){
		current->data->draw(dataArr, 20);
		current = current->next;
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