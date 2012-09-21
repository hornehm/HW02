//#include "NodeList.h"
//#include "Circle.h"

void Node::insertAfter(Node* w, Circle circ){
	Node* tempP = new Node;
	tempP -> data = new circ;
	tempP -> next = w -> next;
	w -> next = tempP;
}

void Node::draw(){
	data* -> draw();
}