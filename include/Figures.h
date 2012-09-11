class Figures{
public:
	Figures(int x, int y, int size);

	Figures* next;
	Figures* previous;

	int xLocation;
	int yLocation;
	int figSize;

	void moveToFront(Figures* item);
	void draw();

};

void moveToFront(Figures* item){

}
