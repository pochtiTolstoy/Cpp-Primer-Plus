#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

class Customer {
private:
  long arrive;
  int processtime;
public:
  Customer() { arrive = processtime = 0; }
  void set(long when);
  long when() const { return arrive; }
  int ptime() const { return processtime; }
};

void Customer::set(long when) {
  processtime = std::rand() % 3 + 1;
  arrive = when;
}

typedef Customer Item;
const int MIN_PER_HR = 60;
bool newcustomer(double x);

int main() {
  std::srand(std::time(0));
  std::cout << "Case Study: Bank of Heather Automatic Teller\n";
  std::cout << "Enter maximum size of queue: ";
  int qs;
  std::cin >> qs;
  std::queue<Item> line;
  std::cout << "Enter the number os simulation hours: ";
  int hours;
  std::cin >> hours;
  long cyclelimit = MIN_PER_HR * hours;
  std::cout << "Enter the  average number of customers per hour: ";
  double perhour;
  std::cin >> perhour;
  double min_per_cust;
  min_per_cust = MIN_PER_HR / perhour;
  Item temp;
  long turnaways = 0;
  long customers = 0;
  long served = 0;
  long sum_line = 0;
  int wait_time = 0;
  long line_wait = 0;
  for (int cycle = 0; cycle < cyclelimit; ++cycle) {
    if (newcustomer(min_per_cust)) {
      if (line.size() > qs) {
        ++turnaways;
      } else {
        ++customers;
        temp.set(cycle);
        line.push(temp);
      }
    }
    if (wait_time <= 0 && !line.empty()) {
      temp = line.front();
      line.pop();
      wait_time = temp.ptime();
      line_wait += cycle - temp.when();
      ++served;
    }
    if (wait_time > 0)
      --wait_time;
    sum_line += line.size();
  }
  if (customers > 0) {
    std::cout << "customers accepted: " << customers << '\n';
    std::cout << " customers served: " << served << '\n';
    std::cout << " turnaways: " << turnaways << '\n';
    std::cout << "average queue size: ";
    std::cout.precision(2);
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout.setf(std::ios_base::showpoint);
    std::cout << (double) sum_line / cyclelimit << '\n';
    std::cout << " average wait time: "
      << (double) line_wait / served << " minutes\n";
  } else {
    std::cout << "No customers!\n";
  }
  std::cout << "Done!\n";
  return 0;
}

bool newcustomer(double x) {
  return (std::rand() * x / RAND_MAX < 1);
}
