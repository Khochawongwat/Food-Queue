#include <vector>
#include <utility>

class Customer {
private:
  int queue_number;
  std::pair<int, int> order_number;

public:
  Customer();
  ~Customer();
  int get_queue();
  void set_queue(int);
  std::pair<int, int> get_order();
  void add_order(std::pair<int, int>);
};

Customer::Customer() {
}

Customer::~Customer() {
}

int Customer::get_queue() {
  return queue_number;
}

void Customer::set_queue(int queue) {
  queue_number = queue;
}

std::pair<int, int> Customer::get_order() {
  return order_number;
}

void Customer::add_order(std::pair<int, int> order) {
  order_number = order;
}
