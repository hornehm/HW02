#include "NodeList.h"

Node::Node(Node* n, Circle c){
	next = n;
	circ = c;
}


void Node::insertAfter(Node* w, Circle circ){
	Node* tempP = new Node;
	tempP -> data = new circ;
	tempP -> next = w -> next;
	w -> next = tempP;
}

void Node::draw(){
	data* -> draw();
}