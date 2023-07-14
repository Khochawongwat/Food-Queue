#include <iostream>
#include <vector>
#include "queue.h"
using namespace std;

struct Dish {
  string name;
  double price;
};

vector<Dish> dishes = {{"Ramen", 100}, {"Som Tum", 20}, {"Fried Chicken", 5}};

int main(int argc, char* argv[]) {
  Queue q;
  int currDish = -1;
  int con = false;
  for (int i = 1; i < argc; i++) {
    if (argv[i][0] == 'x') {
      con = false;
      if (q.getHead() == 0) {
        cout << "There is no such item." << endl;
      } else {
        int total = q.dequeue();
        int cash = 0;

        cout << dishes[currDish].name << endl;  // Moved inside the if block

        cout << "You have to pay " << total << endl;

        while (cash < total) {
          cout << ":Cash: ";
          cin >> cash;
        }

        cout << "Thank you" << endl;

        if (cash - total > 0) {
          cout << "Change is " << cash - total << endl;
        }
      }
    } else {
      if(!con){
        int order = atoi(argv[i]);
        int amount = atoi(argv[i + 1]);
        currDish = order - 1;
        q.enqueue(dishes[currDish].price * amount);
        con = true;
      }
      i++;
    }
  }

  cout << "=====================================================" << endl;

  if (q.getSize() > 0) {
    cout << "There are " << q.getSize() << " people left in the queue" << endl;
  }

  return 0;
}
