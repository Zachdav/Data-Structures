#include <cstdlib>
#include <cstring>
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedList.h"
#include "Queue.h"
#include "Order.h"
#include "Stack.h"
#include "SuperMarket.h"

using namespace std;

/**
 * Driver of p1. this checks arguments and makes the Structure of the Store
 * it reads from the file and inserts it into our stroe structure.
 * it then Dispatches orders and prints their labels.
 */
int main(int argc, char * argv[]){

  //checks if output text is removed, removes it.
  if(remove("shippingLabels.txt") != -1){
    cout << "The existing shippingLabels.txt file has been removed before "
	 << "continuing." 
	 << endl;
  }//if

  //checks if only 1 argument is passed threw, that being the input text.
  if(argc != 2){
    cout << "This program will only accept one argument and that should "
	 << "represent the file you wish to input." 
	 << endl;
    return EXIT_FAILURE;
  }//if

  //instance variables used throughout p1
  LinkedList myList; //List structure for outline of store
  string temp = "";  //temp variable to hold the line/part of the input file

  //instance variables used for creating categories
  string categories = "CATEGORIES"; //check for if line says CATEGORIES
  string orders = "ORDERS";         //check for if line says ORDERS
  string dispatch = "DISPATCH";     //check for if line says DISPATCH

  //open input file
  ifstream input(argv[1]);

  //get first line
  getline(input, temp);
  temp = temp.substr(0, temp.length() - 1); //rids of extra return carraige
  
  //checks if CATEGORIES is the first thing in the file. if not the syntax error.
  if(strcmp(categories.c_str(), temp.c_str()) == 0){

    //go threw each category
    for(;;){
      if(getline(input, temp)){
      }else {
	cout << "Input file is of the wrong syntax." << endl;
	return EXIT_FAILURE;
      }//if else
      
      temp = temp.substr(0, temp.length() - 1);
      
      //break if next line is ORDERS
      if (strcmp(temp.c_str(), orders.c_str()) == 0){
      	break;
      }else{
	//make a new node with name temp and append to the linked list the queue 
	//is a new queue specific to the node, and has category temp
	myList.append(temp, * new Queue(temp));
      }//if else
    }//for loop of stupidness
    
    //instance variables for getting order from input txt
    int ordernum = 1;   //for which ordernumber the order is
    string comma = ","; //string for comma comparison
    int index = 0;      //index place holder for index of string
    string name = "";   //for name of order
    string item = "";   //for item of order
    string cat = "";    //for cateogry of order
    string loc = "";    //for ship area of order

    //go threw each order
    for(;;){
      if(getline(input, temp)){
      }else {
	cout << "Input file is of the wrong syntax." << endl;
	return EXIT_FAILURE;
      }//if else

      temp = temp.substr(0, temp.length() - 1);

      //break if line is DISPATCH
      if (strcmp(temp.c_str(), dispatch.c_str()) == 0){
	break;
      }else{

      //add order
      index = temp.find(comma);
      name = temp.substr(0, index);
      temp.erase(0, index + 2);
      index = temp.find(comma);
      item = temp.substr(0, index);
      temp.erase(0, index + 2);
      index = temp.find(comma);
      cat = temp.substr(0, index);
      temp.erase(0, index + 2);
      loc = temp;
      myList.getNodeByCat(cat).orderQueue.enqueue( * new Order(ordernum, name, item, cat, loc));

      //increase order number
      ordernum++;
      }//if else

    }//for loop #2 of supiderness

    //instance variables for Dispatch orders
    int count = 0;      //number of dispatch order categories
    string space = " "; //comparison to the sapce symbol
    int i = 0;          //index of array
    index = 0;          //index place holder for index of string

    //find out number of dispatch order categories
    while(getline(input, temp)){
      count ++;
    }//while
    //category array for categories of dispatch array
    string * category = new string[count];
    
    //close and reopen file and go to the line with dispatch
    input.close();
    input.open(argv[1]);
    for(;;){
      getline(input, temp);
      temp = temp.substr(0, temp.length() - 1);
      if (strcmp(temp.c_str(), dispatch.c_str()) == 0){
	break;
      }//if      
    }//for
    
    //go threw each dispatch order
    while(getline(input, temp)){
      
      //set category array index be category name in order of dispatch
      index = temp.find(space);
      category[i] = temp.substr(0, index);

      //get number of orders in category to be dispatched
      temp.erase(0, index + 1);
      myList.getNodeByCat(category[i]).orderCount = atoi(temp.c_str());

      //increase array index
      i++;
    }//normal while

    // dispatchOrder(myList, &category, count);
    //call to dispatchOrder moved to main:

    //new stack
    Stack stack;
  
    //push every dispatched order onto the stack
    for(int i = 0; i < count; i++){
      for(int j = 0; j < myList.getNodeByCat(category[i]).orderCount; j++){
	stack.push(myList.getQueueByCat(category[i]).dequeue());
      }//for
    }//for

    //print Labels
    printLabel(stack);
    
    //TODO delete allocated memory

    Node * tempptr;
    for(int i = 0; i < myList.length; i++){
      tempptr = myList.headptr;
      delete & myList.headptr->orderQueue;
       myList.headptr = tempptr->next;
       delete tempptr;
    }//for

    delete[] category;
    
  }else{
    cout << "Input file is of the wrong syntax." << endl;
  }//if

  return EXIT_SUCCESS;

}//main
