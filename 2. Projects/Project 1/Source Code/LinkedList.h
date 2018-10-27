/**
* LinkedList class
*/

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include "Queue.h"
#include <string>
#include <cstdlib>

using namespace std;
// forward declaration of LinkedList

class LinkedList;

/**
* Represents a node in a doubly-linked list.
* A node represent a category of product in the store.
* Each node stores information about the number of orders
* in that category that needs to be dispatched.
*/

class Node {
	friend class LinkedList;
private:
    string category = "";   // The category of products in this node.
public:
	Node * next = nullptr;
	int orderCount = 0; // The number of orders in this node/category of product to dispatch.
	Queue & orderQueue;  // The order queue for this category.
	
	/**
	* Parameterized Constructor
	*/
	Node(Node * next, string category, Queue &orderQueue);
	
}; // Node

/**
* A doubly-linked list data structure.
*/

class LinkedList {
private:
    	Node * tailptr = nullptr;
public:
	Node * headptr = nullptr;
	int length = 0;
	
	/**
	* Adds an item to the end of this list.
	*
	* @param category The category of the queue, the node having this queue is being appended
	* @param orderQueue The queue this node will have
	*/
	void append(string category, Queue &orderQueue);


	/**
	* Returns the queue for a given category.
	* Use this to quickly get the required queues
	* for enqueue and dequque operations.
	* @param cat the category for the required queue. 
	*/
	Queue & getQueueByCat(string cat);

	/**
	* Returns the Node for a given category.
	* Use this to quickly get the required node
	* @param cat the category for the required queue. 
	*/
	Node & getNodeByCat(string cat);

	/**
	* Sets the value of orderCount for the given category.
	*
	* @param cat the category name
	* @param count the numbe of orders to dispatch
	*/
	void setOrderCount(string cat, int count);

	/**
	* Returns the number of elements in this list.
	*/
	const int size() const;

	/**
	* Returns whether or not this linked list is empty. 
	*/
	const bool empty() const {
		return size() == 0;
	} // empty
}; // LinkedList
#endif /** LINKED_LIST_H */
