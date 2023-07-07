#include "customer.h"

#ifndef node_h
#define  node_h

class NODE{
	Customer data;
	NODE *nextPtr;
public:
	NODE(Customer);
	~NODE();
  Customer get_value();
	void set_next(NODE *);
	NODE* get_next();
};
typedef NODE* NodePtr;

NODE::NODE(Customer x){
	data=x;
	nextPtr= nullptr;

}
Customer NODE::get_value(){
	return data;

}

NODE* NODE::get_next(){
	return nextPtr;

}

void NODE::set_next(NODE *t){
	 nextPtr=t;

}

NODE::~NODE(){
	 cout<<"Customer # " << data.get_queue() << "has checked out" << endl;

}


#endif