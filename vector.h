class vector
{
private:
	unsigned int sizeVec;
	unsigned int capacityVec;
	int* ptr;
public:
	vector();
	~vector();
	void resise(int);
	void print();
	void push(int);
	void pop();
	int get();
};