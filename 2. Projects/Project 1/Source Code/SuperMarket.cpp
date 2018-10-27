#include "SuperMarket.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Order.h"

using namespace std;

/**
 * not used
 */
void dispatchOrder(LinkedList & myList, string * cats, int size){

  Stack stack;
  int ordersdp;

  for(int i = 0; i < size; i++){
    ordersdp = myList.getNodeByCat(cats[i]).orderCount;
    for(int j = 0; j < ordersdp; j++){
      stack.push(myList.getQueueByCat(cats[i]).dequeue());
    }//for
  }//for

  printLabel(stack);

}//dispatch


/**
 * printLabel
 */
void printLabel(Stack & myStack){

  //instance variables
  Order * tempOrder;
  ofstream orderform;

  //open new file
  orderform.open("shippingLabels.txt");

  //1st line
  orderform << "------------------------------\n";

  //while loop to go threw stack
  while(!myStack.isEmpty()){

    //pop
    tempOrder = & myStack.pop();

    //print out info about order
    orderform << "Order Number: " << tempOrder->orderNumber << "\n"
	      << "Name: " << tempOrder->name << "\n"
	      << "Item: " << tempOrder->item << "\n"
	      << "Shipped to: " << tempOrder->shipArea << "\n"
	      << "------------------------------\n";

    //deletes order
    delete tempOrder;

  }//while

  //closes file
  orderform.close();

}//print Label
