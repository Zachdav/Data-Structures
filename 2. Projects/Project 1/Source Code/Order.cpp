#include "Order.h"

/**
 * Order Constructors
 */
Order::Order(const int orderNumber, const string & name, const string & item, const string & category, const string &shipArea){

  this->orderNumber = orderNumber;
  this->name = name;
  this->item = item;
  this->category = category;
  this->shipArea = shipArea;

}//Order

Order::Order(const Order & order2){

  this->orderNumber = order2.orderNumber;
  this->name = order2.name;
  this->item = order2.item;
  this->category = order2.category;
  this->shipArea = order2.shipArea;

}//Order

void Order::operator = (const Order & order2){

  this->orderNumber = order2.orderNumber;
  this->name = order2.name;
  this->item = order2.item;
  this->category = order2.category;
  this->shipArea = order2.shipArea;

}//=

