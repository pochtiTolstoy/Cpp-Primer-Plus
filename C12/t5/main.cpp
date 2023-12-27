#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue.h"

const int MIN_PER_HR = 60;

struct statistics {
  long turnaways = 0;
  long customers = 0;
  long served = 0;
  long sum_line = 0;
  int wait_time = 0;
  long line_wait = 0;
  double avg_wait_time = 0;
  double avg_queue_size = 0;
  long cyclelimit = 0;
};

bool newcustomer(double x);
void init_stats(statistics& stats);
void process_cycle(double, long, Queue&, Item&, statistics&);
void calculate_avg_time(statistics&);
void print_stats(const statistics&);
void calculate_queue_size(statistics&);

int main() {
  std::srand(std::time(0));
  std::cout << "Case study: Bank of Heather Autmatic Teller\n";
  int qs;
  std::cout << "Enter maximum size of queue: ";
  std::cin >> qs;
  Queue line(qs);
  Item temp; // customer object
  int hours = 100;
  long cyclelimit = MIN_PER_HR * hours;
  double perhour = 0; // average customers per hour
  double min_per_cust = 0; // average minutes between two customers
  statistics stats_new;
  statistics stats_old;
  stats_old.cyclelimit = stats_new.cyclelimit = cyclelimit;
  
  while (stats_new.avg_wait_time <= 1) {
    ++perhour;
    while (line.dequeue(temp))      //empty queue
      continue;
    stats_old = stats_new;          // load in previous stats
    init_stats(stats_new);
    min_per_cust = MIN_PER_HR / perhour;
    // process cycle
    process_cycle(min_per_cust, cyclelimit, line, temp, stats_new);
    calculate_avg_time(stats_new);
    calculate_queue_size(stats_new);
    std::cout << "Customers: " << perhour
              << "\t-->\t" << stats_new.avg_wait_time << std::endl;
  }
  std::cout << "\nResult number of customers: " << perhour - 1 << std::endl;
  statistics result_stats = stats_old;
  print_stats(result_stats);
  std::cout << "Done!\n";
  return 0;
}

bool newcustomer(double x) {
  return (std::rand() * x / RAND_MAX < 1);
}

void init_stats(statistics& stats) {
  stats.turnaways = 0;
  stats.customers = 0;
  stats.served = 0;
  stats.sum_line = 0;
  stats.wait_time = 0;
  stats.line_wait = 0;
  stats.avg_wait_time = 0;
  stats.avg_queue_size = 0;
}

void process_cycle(
  double min_per_cust, 
  long cyclelimit, 
  Queue& line, 
  Item& temp, 
  statistics& stats
) {
  for (int cycle = 0; cycle < cyclelimit; ++cycle) {
    if (newcustomer(min_per_cust)) {
      if (line.isfull())
        ++stats.turnaways;
      else {
        ++stats.customers;
        temp.set(cycle);
        line.enqueue(temp);
      }
    }
    if (stats.wait_time <= 0 && !line.isempty()) {
      line.dequeue(temp);
      stats.wait_time = temp.ptime();
      stats.line_wait += cycle - temp.when();
      ++stats.served;
    }
    if (stats.wait_time > 0)
      --stats.wait_time;
    stats.sum_line += line.queuecount();
  }
}

void calculate_avg_time(statistics& stats) {
  stats.avg_wait_time = 
    static_cast<double>(stats.line_wait) / stats.served;
}

void calculate_queue_size(statistics& stats) {
    stats.avg_queue_size = 
      static_cast<double>(stats.sum_line) / stats.cyclelimit;
}

void print_stats(const statistics& stats) {
  if (stats.customers > 0) {
    std::cout << "customers accepted: " << stats.customers << std::endl;
    std::cout << " customers served: " << stats.served << std::endl;
    std::cout << " turnaway: " << stats.turnaways << std::endl;
    std::cout << " average queue size: ";
    std::cout.precision(2);
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    std::cout << stats.avg_queue_size << std::endl;
    std::cout << " average wait time: "
              << stats.avg_wait_time << " minutes\n";
  } else
    std::cout << "No customers!\n";
}
