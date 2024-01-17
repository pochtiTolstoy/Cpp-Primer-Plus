#include <iostream>
#include <iterator>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

class Person {
private:
  std::vector<std::string> names_;
public:
  Person(): names_(0) {}
  virtual ~Person() {};
  virtual void get_names() = 0;
  virtual void show_names() const = 0;
  virtual const std::vector<std::string>& 
  get_data() const { return names_; }
  void sort() { std::sort(names_.begin(), names_.end()); }
  friend std::set<std::string> 
  concatenate_lists(const Person&, const Person&);
};

void Person::get_names() {
  std::cout << "Please enter person name (or empty string to quit): ";
  std::string temp;
  while (std::getline(std::cin, temp) && temp != "") {
    names_.push_back(temp);
    std::cout << "Enter next name: ";
  }
  if (std::cin.fail())
    std::cin.clear();
}

void Person::show_names() const {
  std::copy(
    names_.begin(), names_.end(), 
    std::ostream_iterator<std::string, char>(std::cout, " ")
  );
  std::cout << '\n';
}

class M: public Person {
public:
  M(): Person() {}
  void get_names() override;
  void show_names() const override;
  const std::vector<std::string>& get_data() const override {
    return Person::get_data();
  }
};

void M::get_names() {
  std::cout << "Creating Matt list:\n";
  Person::get_names();
  Person::sort();
}

void M::show_names() const {
  std::cout << "Showing Matt list:\n";
  Person::show_names();
}

class P: public Person {
public:
  P(): Person() {}
  void get_names() override;
  void show_names() const override;
  const std::vector<std::string>& get_data() const override {
    return Person::get_data();
  }
};

void P::get_names() {
  std::cout << "Creating Patt list:\n";
  Person::get_names();
  Person::sort();
}

void P::show_names() const {
  std::cout << "Showing Patt list:\n";
  Person::show_names();
}

std::set<std::string>
concatenate_lists(const Person& p1, const Person& p2) {
  std::set<std::string> res(p1.get_data().begin(), p1.get_data().end());
  for (auto x: p2.get_data()) res.insert(x);
  return res;
}

int main() {
  M m;
  P p;
  m.get_names();
  p.get_names();
  m.show_names();
  p.show_names();
  std::set<std::string> res = concatenate_lists(p, m);
  std::cout << "Data from set:\n";
  std::copy(
    res.begin(), res.end(),
    std::ostream_iterator<std::string, char>(std::cout, " ")
  );
  return 0;
}
