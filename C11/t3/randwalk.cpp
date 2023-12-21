#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vect.h"

struct statistics {
  double target;
  double dstep;
  int N;
  unsigned long min;
  unsigned long max;
  double avg;
};

void clear_buffer(void);
void free_io(void);
void get_dstep(double& dstep);
void get_N(int& N);
void show_stats(const statistics&);
void init_stats(statistics&);

int main() {
  using VECTOR::Vector;
  srand(time(0));

  double target;  // radius length
  double dstep;   // step length
  int N;          // Number of experiments
  
  double direction; // angle of rotation from 0 - 360 

  unsigned long steps = 0; // amount of step vectors in final vector
  
  Vector result;  // sum of step vectors
  Vector step;    // step vector for only one move

  statistics stats;

  std::cout << "Enter target distance (q to quit): ";
  while (std::cin >> target) {
    get_dstep(dstep);
    get_N(N);
    init_stats(stats);
    stats.target = target;
    stats.dstep = dstep;
    stats.N = N;
    for (int i = 0; i < N; ++i) {
      steps = 0;
      result.reset(0.0, 0.0);
      while (result.magval() < target) {
        direction = rand() % 360;
        step.reset(dstep, direction, Vector::POL);
        result = result + step;
        ++steps;
      }
      if (i == 0) { stats.min = steps; stats.max = steps; }
      stats.min = steps < stats.min ? steps : stats.min;
      stats.max = steps > stats.max ? steps : stats.max;
      stats.avg += static_cast<double>(steps); // UL to double
    }
    stats.avg /= N; // int to double
    show_stats(stats);
    std::cout << "Enter a new target distance (q to quit): ";
  }
  free_io();
  return 0;
}

void get_dstep(double& dstep) {
  std::cout << "Enter step length: ";
  while (!(std::cin >> dstep)) {
    std::cout << "Please enter a real number: "; 
    free_io();
  }
}

void get_N(int& N) {
  std::cout << "Enter number of experiments: ";
  while (!(std::cin >> N) || N <= 0) {
    std::cout << "Please enter a positive integer number: "; 
    free_io();
  }
}

void init_stats(statistics& stats) {
  stats.target = 0;
  stats.dstep = 0;
  stats.N = 0;
  stats.min = 0;
  stats.max = 0;
  stats.avg = 0;
}

void show_stats(const statistics& stats) {
  std::cout << "Target distance: "       << stats.target << ", "
            << "Step size: "             << stats.dstep << ", "
            << "Number of experiments: " << stats.N << std::endl;
  std::cout << "Minmal steps: "          << stats.min << std::endl
            << "Maximum steps: "         << stats.max << std::endl
            << "Average steps: "         << stats.avg << std::endl;
}

void clear_buffer(void) {
  while (std::cin.get() != '\n')
    continue;
}
void free_io(void) {
  if (std::cin.fail())
    std::cin.clear();
  clear_buffer();
}
