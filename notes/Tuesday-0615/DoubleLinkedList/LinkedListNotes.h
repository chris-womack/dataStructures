#ifndef LINKEDLISTNOTES_H_INCLUDED
#define LINKEDLISTNOTES_H_INCLUDED


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
    void setPrevious(CNode *n);
    void setX(int);
    int getX();
};


#endif // LINKEDLISTNOTES_H_INCLUDED
