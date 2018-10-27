#include "Stack.h"
#include <iostream>

using namespace std;

/**
 * push pushes an order onto the stack
 */
void Stack::push(Order & order){

  //correct the doubly linked list
  order.prev = top;
  top = & order;
  order.next = nullptr;

  //increase size
  size ++;

}//push

/**
 * pop an order from the stack
 */
Order & Stack::pop(){

  //temp pointer to be changed
  Order * temp = top;

  //check the size
  if(size == 1){
    top = nullptr;
  }else{
    //make top the one before the top
    top = temp->prev;
    top->next = nullptr;
  }//if else

  //decrease size
  size --;

  //return what was poped.
  return * temp;

}//pop
