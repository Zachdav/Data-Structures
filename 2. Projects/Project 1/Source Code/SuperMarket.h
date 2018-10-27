/**
* This file provides the function prototypes
* for dispatchOrder and printLabel
*/
#ifndef _SUPERMARKET_H
#define _SUPERMARKET_H

#include "LinkedList.h"
#include "Stack.h"

/**
* function dispatchOrder
* This function will access the data part of the linked list
* for the number of orders to be dequeued and pushed onto
* the stack, it will also reset this data part to zero
* after dequeuing for that node is complete.
*/
void dispatchOrder(LinkedList &myList, string * cats, int size);

/**
* function printLabel
* This function will pop all the elements from the stack
* one-by-one and prints a label in the given format to a file.
*/
void printLabel(Stack &myStack);
#endif // _SUPERMARKET_H
