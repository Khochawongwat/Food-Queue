class Customer {
private:
  int queue_number;

public:
  Customer(); 
  ~Customer();
  int get_queue();
  void set_queue(int);
};

Customer::Customer() {
  queue_number = 0;
}

Customer::~Customer() {
  // Destructor implementation, if needed
}


void Customer::set_queue(int x) {
  queue_number = x;
}

int Customer::get_queue() {
  return queue_number;
}
