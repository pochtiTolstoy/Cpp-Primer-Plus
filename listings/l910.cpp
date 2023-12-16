#include <iostream>
#include <new>
const int BUF = 512;
const int N = 5;
char buffer[BUF]; // this is static memory
int main() {
  double* pd1;
  double* pd2;
  int i;
  std::cout << "Calling new and placement new:\n";
  pd1 = new double[N]; // array in heap
  pd2 = new (buffer) double[N]; // array in buffer
  for (i = 0; i < N; ++i)
    pd2[i] = pd1[i] = 1000 + 20.0 * i;
  std::cout << "Memory addresses:\n" << " head: " << pd1
            << " static: " << (void*) buffer << std::endl;
  std::cout << "Memory contents:\n";
  for (i = 0; i < N; ++i) {
    std::cout << pd1[i] << " at " << pd1 + i << "; ";
    std::cout << pd2[i] << " at " << pd2 + i << std::endl; 
  }
  std::cout << "\nCalling new and placement new a second time:\n";
  double* pd3;
  double* pd4;
  pd3 = new double[N];
  pd4 = new (buffer) double[N];
  for (i = 0; i < N; ++i)
    pd4[i] = pd3[i] = 1000 + 40.0 * i;
  
  std::cout << "Memory contents:\n";
  for (i = 0; i < N; ++i) {
    std::cout << pd3[i] << " at " << pd3 + i << "; ";
    std::cout << pd4[i] << " at " << pd4 + i << std::endl; 
  }

  std::cout << "\nCalling new and placement new a third time:\n";
  delete[] pd1; // delete on heap
  pd1 = new double[N];
  pd2 = new (buffer + N * sizeof(double)) double[N];
  for (i = 0; i < N; ++i)
    pd2[i] = pd1[i] = 1000 + 60.0 * i;
  std::cout << "Memory contents:\n";
  for (i = 0; i < N; ++i) {
    std::cout << pd1[i] << " at " << pd1 + i << "; ";
    std::cout << pd2[i] << " at " << pd2 + i << std::endl;
  }

  delete[] pd1; //delete on heap
  delete[] pd3; //delete on heap

  return 0;
}
