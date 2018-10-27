#include "Queue.h"
#include <iostream>

using namespace std;

/**
 * Queue constructor
 */
Queue::Queue(string category){

  //set categories equal
  this->category = category;

}//Queue
/*
 *   Cleans up the Queue trash at the end of the program.
 */
Queue::~Queue() {

	Order * tempptr = nullptr;

	for (int i = 0; i < queueSize(); i++) {
		tempptr = & this->dequeue();
		delete tempptr;
	}//for

}//~Queue

/**
 * enqueue a order onto the queue
 */
void Queue::enqueue(Order & order){

  //checks if empty
  if(isEmpty()){
    headptr = tailptr = & order;
  }else{
    //sets up to be on queue
    tailptr->next = & order;
    tailptr = & order;
  }//if else
  
}//enqueue

/**
 * dequeue an order from the front of the queue
 */
Order & Queue::dequeue(){

  //checks if empty
  if(headptr == nullptr){
    cout << "order is empty" << endl;
  }//if 

  //order to return
  Order * tempptr = headptr;

  //make head the next one
  headptr = headptr->next;

  //return the dequeued item
  return * tempptr;

}//dequeue

/**
 * gets size of queue
 */
int Queue::queueSize(){
  
  //count
  int count = 0;
  //pointer to change
  Order * tempptr = headptr;
  
  //traverse threw queue
  while(tempptr != nullptr){
    count ++;
    tempptr = tempptr->next;
  }//while

  //return count
  return count;

}//queueSize
