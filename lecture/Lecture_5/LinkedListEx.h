#ifndef LINKEDLISTEX_H_INCLUDED
#define LINKEDLISTEX_H_INCLUDED


/*The header file just includes the definitions of the
class and methods, there is no actual code here. We know
that there is a getNext method that returns a CNode pointer,
but we don't know anything about what happens in getNext, that code
will be in a .cpp file with the name linkedListEx.cpp.*/
class CNode{
	private:
	int x;
	CNode *next;
	CNode *previous;

	public:
	CNode(int);
	~CNode();
	CNode *getNext();
	void setNext(CNode *n);
	CNode *getPrevious();
	void setPrevious(CNode *p);
    void setX(int);
    int getX();
};




#endif // LINKEDLISTEX_H_INCLUDED
