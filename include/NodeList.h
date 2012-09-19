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
