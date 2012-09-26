#include "Node.h"
#include "Circle.h"

Node::Node(Circle* new_data){
	next = NULL;
	prev = NULL;
	data = new_data;
}
