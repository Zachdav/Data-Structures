#include "LinkedList.h"
#include <string>
#include <cstring>

/**
 * Node Class is for the Each Node (Category) in the Super Market
 */
Node::Node(Node * next, string category, Queue & orderQueue) : orderQueue(orderQueue){

  this->next = next;         //next pointer to next category 
  this->category = category; //name of category
	
}// Node

/**
 * append appends a new node into the list
 */
void LinkedList::append(string category, Queue &orderQueue){

  //checks if it is the first category
  if(empty()){
    headptr = tailptr = new Node(nullptr, category, orderQueue);
  }else{
    tailptr->next = new Node(nullptr, category, orderQueue);
    tailptr = tailptr->next;
  }//if
  length++;

}//append

/**
 * get QueueByCat gets the queue associated with the category
 */
Queue & LinkedList::getQueueByCat(string cat){

  //pointer to change
  Node * tempptr = headptr;

  //cycle threw the linked list till find category
  while(tempptr != nullptr){
    //retrun if categories match
    if(strcmp(tempptr->category.c_str(), cat.c_str()) == 0) return tempptr->orderQueue;
    tempptr = tempptr->next;
  }//while

  //if not in return head
  return headptr->orderQueue;

}//getQueueByCat

/**
 * getNodeByCat retruns the node of a category
 */
Node & LinkedList::getNodeByCat(string cat){

  //pointer to change
  Node * tempptr = headptr;

  //cycle threw the linked list till find category
  while(tempptr != nullptr){
    //retrun if categories match
    if(strcmp(tempptr->category.c_str(), cat.c_str()) == 0) return * tempptr;
    tempptr = tempptr->next;
  }//while
  
  //if not there retrun head
  return * headptr;

}//getNodeByCat

/**
 * setOrderCount sets the order count for a particular category
 */
void LinkedList::setOrderCount(string cat, int count){

  //pointer to change
  Node * tempptr = headptr;

  //cycle threw the linked list till ind category
  while(tempptr != nullptr){
    //set orderCount if categories match
    if(strcmp(tempptr->category.c_str(), cat.c_str()) == 0) tempptr->orderCount = count;
    tempptr = tempptr->next;
  }//while
 
}//setOrder

/**
 * size returns the size of linked list
 */
const int LinkedList::size() const{

  //number of nodes in LL
  int count = 0;
  //pointert to change
  Node * tempptr = headptr;

  //traverse threw nodes
  while(tempptr != nullptr){
    count ++;
    tempptr = tempptr->next;
  }//while

  return count;

}//size
