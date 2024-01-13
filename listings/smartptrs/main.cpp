#include <iostream>
#include <string>
#include <memory>

class Report {
private:
  std::string str;
public:
  Report(const std::string s): str(s) {
    std::cout << "Report: Object created!\n";
  }
  virtual ~Report() {
    std::cout << "Report: Object deleted!\n";
  }
  virtual void comment() const {
    std::cout << str << '\n';
  }
};

class A: public Report {
public:
  A(const std::string& s): Report(s) { std::cout << "A: object created\n"; }
  ~A() {
    std::cout << "A: destructor()\n";
  }
  void comment() const override {
    std::cout << "A: ";
    Report::comment();
  }
};

class B: public Report {
public:
  B(const std::string& s): Report(s) { std::cout << "B: object created\n"; }
  ~B() {
    std::cout << "B: destructor()\n";
  }
  void comment() const override {
    std::cout << "B: ";
    Report::comment();
  }
};

int main() {
  {
    // template <class X> -> ctrs(X* p) -> X = Report
    std::unique_ptr<Report> ps(new Report("using auto_ptr"));
    ps->comment();
  }
  {
    std::unique_ptr<Report> ps(new A("using unique_ptr"));
    ps->comment(); // A: ...
  }
  {
    std::shared_ptr<Report> ps(new B("using shared_ptr"));
    ps->comment(); // B: ...
  }
  // create, comment, delete
  // create, A create, A comment, A dstr, dstr 
  // create, b create, b comment, b dstr, dstr 
  /* output:
  Report: Object created!
  using auto_ptr
  Report: Object deleted!
  Report: Object created!
  A: object created
  A: using unique_ptr
  A: destructor()
  Report: Object deleted!
  Report: Object created!
  B: object created
  B: using shared_ptr
  B: destructor()
  Report: Object deleted!
  */
  return 0;
}
