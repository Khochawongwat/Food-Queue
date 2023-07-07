#include <iostream>
using namespace std;
#include "queue.h"
#include <vector>

struct Dish {
  string name;
  double price;
};

int main(int argc, char *argv[]) {
  vector<Dish> dishes = {{"Ramen", 100}, {"Som Tum", 20}, {"Fried Chicken", 50}};

  if (argc != 2) {
    cout << "There is no queue." << endl;
    return 1;
  }

  Queue q;
  int n = stoi(argv[1]);
  int N = n;
  
  for (int i = 1; i <= n; i++) {
    Customer x;
    x.set_queue(i);
    q.enqueue(x);
  }

  while (q.isEmpty() != 1) {
    int order = 0, temp, refQueue;
    temp = 0;

    while (temp != dishes.size()) {
      cout << "My order is ";
      cin >> temp;
      if(order && temp == 3) {
        break;
      }else if((temp < 1 || temp > dishes.size())){
        cout << "Invalid order. Please try again." << endl;
      }else {
        order = temp;
      }
    }
    
    while (refQueue != q.getCurrentQueue()){
      cout << "Customer Queue#: ";
      cin >> refQueue;
      if (refQueue > N) {
        cout << "Queue not found. Please try again." << endl;
      } else if (refQueue > q.getCurrentQueue()) {
        cout << "You're skipping lines! Current queue is " << q.getCurrentQueue() << endl;
      } else if (refQueue < 1) {
        cout << "Invalid queue number. Please try again." << endl;
      } else if (refQueue < q.getCurrentQueue()) {
        cout << "Customer #" << refQueue << " has already been served." << endl;
      }
    }


    int amountToPay = 0;
    int priceOfDish = 0;

    if (order >= 1 && order <= dishes.size()) {
      priceOfDish = dishes[order - 1].price;
      cout << dishes[order - 1].name << endl;
      cout << "You have to pay " << priceOfDish << endl;
    }

    while (amountToPay < priceOfDish || !amountToPay) {
      cout << ":Cash: ";
      cin >> amountToPay;
      if (amountToPay < priceOfDish) {
        cout << "Insufficient amount of money. Please try again." << endl;
      } else {
        cout << "Thank you" << endl;
        if (amountToPay > priceOfDish) {
          cout << "Change is: " << amountToPay - priceOfDish << endl;
        }
        Customer customer = q.dequeue();
        n--;
        break;
      }
    }

    cout << "..." << endl;
  }
}
