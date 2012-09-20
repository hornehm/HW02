using namespace ci;
using namespace ci::app;
using namespace std;

class Node{
public:
	Node(Node* n, Circle c);

	void insertAfter(Node* w, Circle circ);
	void draw();

	Node* next;
	Circle circ;
};


Node::Node(Node* n, Circle c){
	next = n;
	circ = c;
}
