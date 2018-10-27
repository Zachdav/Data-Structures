/**
 * Order class
 */
#ifndef _ORDER_H
#define _ORDER_H

#include <string>
using namespace std;

class Order {
 public:
  int orderNumber = -1;
  string name = "";
  string item = "";
  string category = "";
  string shipArea = "";
  Order * next = nullptr;
  Order * prev = nullptr; //never worry about prev in Queue, only stack
	
  /**
    * Default Constructor
    */
    Order() = default;

	
    /**
     * Constructor
     */
    Order(const int orderNumber, const string &name, const string &item,const string &category, const string &shipArea);
	
    /**
     * copy constructor
     */
    Order(const Order &);
    
    /**
     * copy operator
     */
    void operator = (const Order &);
      
    /**
     * Destructor
     */
    ~Order(void) {}
};

#endif //_ORDER_H
