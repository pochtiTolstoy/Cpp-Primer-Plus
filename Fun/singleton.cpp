#include <iostream>

class C {
private:
  static C* obj; 
  C() {}
public:
  static C& get_obj() {
    if (obj) return *obj;
    obj = new C();
    return *obj;
  }
  static void destroy() {
    delete obj;
  }
};

C* C::obj = nullptr;

int main() {
  C c = C::get_obj();  
  std::cout << "Hello world!\n";
  C::destroy();
  return 0;
}
