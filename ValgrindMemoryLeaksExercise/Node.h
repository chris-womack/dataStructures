//	Ian Smith
//	CSCI - 2270
//	Summer 2014
//
//	FILE: Node.h
//
//	Header file for node class

#ifndef NODE_H
#define NODE_H

class Node {
	private:
		/*************
		 * 	ATTRIBUTES
		 **************/
		int value;
		Node * next;
		Node * previous;
	public:
		/*************
		 * 	CONSTRUCTORS
		 **************/
		Node();
		Node(int new_val);
		Node(int new_val, Node * new_next, Node * new_previous); 
		/*************
		 * 	DESCTRUCTOR
		 **************/
		~Node();
		/*************
		 * 	GETTERS
		 **************/
		int getValue();
		Node * getNext();
		Node * getPrevious();
		/*************
		 * 	SETTERS
		 **************/
		void setValue(int new_val);
		void setNext(Node * new_next);
		void setPrevious(Node * new_previous);
};

#endif
