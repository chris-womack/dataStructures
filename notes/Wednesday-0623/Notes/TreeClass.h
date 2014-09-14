#ifndef LINKEDLISTEX_H_INCLUDED
#define LINKEDLISTEX_H_INCLUDED

#include <string>

using namespace std;

class City{
	private:
	string name;
	City *leftChild;
	City *rightChild;
	City *parent;

	public:
	City(string);
	~City();
	City *getLeftChild();
	void setLeftChild(City *n);
	City *getRightChild();
	void setRightChild(City *p);
	City *getParent();
	void setParent(City *p);
    //void setX(int);
    string getName();
};

class Tree{
private:
    City *root;
public:
    Tree();
    ~Tree();
    void addCity(string na);
};


#endif // LINKEDLISTEX_H_INCLUDED
