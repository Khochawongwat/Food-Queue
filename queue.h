#include "node.h"
#include <stdexcept>

using namespace std;

class Queue {
  NodePtr headPtr, tailPtr;
  int size;

public:
  void enqueue(Customer);
  int getSize();
  int isEmpty();
  int getCurrentQueue();
  Customer dequeue();
  Queue();
  ~Queue(); // dequeue all
};

int Queue::getCurrentQueue(){
  return headPtr->get_value().get_queue();
}
int Queue::getSize(){
  return size;
}
int Queue::isEmpty(){
  if(size == 0){
    return 1;
  }
  return -1;
}

Queue::Queue() {
  size = 0;
  headPtr = nullptr;
  tailPtr = nullptr;
}

Queue::~Queue() {
  while (size > 0) {
    dequeue();
  }
}

void Queue::enqueue(Customer x) {
  // 1. Create a new node
  NodePtr new_node = new NODE(x);

  if (new_node) {
    if (size == 0) {
      // 2.1 Set new node as both head and tail
      headPtr = new_node;
      tailPtr = new_node;
    } else {
      // 2.2 Connect new node to the tail
      tailPtr->set_next(new_node);
      tailPtr = new_node;
    }
    
    // 3. Increase size
    size++;
  } else {
    cout << "Not enough memory" << endl;
  }
}

Customer Queue::dequeue() {
  if (size > 0) {
    // 1. Save the value of the node to be deleted
    Customer value = headPtr->get_value();

    // 2. Move head to the next node
    NodePtr temp = headPtr;
    headPtr = headPtr->get_next();

    // 3. Delete the old head
    delete temp;

    // 4. Decrease size
    size--;

    // 5. If the queue becomes empty, update tailPtr
    if (size == 0) {
      tailPtr = nullptr;
    }

    return value;
  } else {
    throw runtime_error("Queue is empty");
  }
}


