#ifndef PERSON_H_
#define PERSON_H_
#include <iostream>
#include <fstream>
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
  virtual void get_names_file(std::ifstream&) = 0;
  virtual void show_names() const = 0;
  virtual void save_names_file(std::ofstream&) const = 0;
  virtual const std::vector<std::string>& 

  get_data() const { return names_; }
  void sort() { std::sort(names_.begin(), names_.end()); }

  friend std::set<std::string> 
  concatenate_lists(const Person&, const Person&);
};

class M: public Person {
public:
  M(): Person() {}
  void get_names() override;
  void get_names_file(std::ifstream&) override;
  void show_names() const override;
  void save_names_file(std::ofstream&) const override;
  const std::vector<std::string>& get_data() const override {
    return Person::get_data();
  }
};

class P: public Person {
public:
  P(): Person() {}
  void get_names() override;
  void get_names_file(std::ifstream&) override;
  void show_names() const override;
  void save_names_file(std::ofstream&) const override;
  const std::vector<std::string>& get_data() const override {
    return Person::get_data();
  }
};

#endif /* PERSON_H_ */
