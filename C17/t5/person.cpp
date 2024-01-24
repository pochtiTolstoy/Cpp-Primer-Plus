#include "person.h"

// Person methods:
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

void Person::get_names_file(std::ifstream& fin) {
  std::string temp;  
  while (std::getline(fin, temp) && temp != "") {
    names_.push_back(temp);
  }
  if (!fin.eof()) {
    std::cout << "File error via reading.\n";
  } else {
    std::cout << "Reached end of file.\n";
  }
}

void Person::show_names() const {
  std::copy(
    names_.begin(), names_.end(), 
    std::ostream_iterator<std::string, char>(std::cout, " ")
  );
  std::cout << '\n';
}

void Person::save_names_file(std::ofstream& fout) const {
  std::copy(
    names_.begin(), names_.end(),
    std::ostream_iterator<std::string, char>(fout, "\n")
  );
  fout << '\n';
}

// M methods:
void M::get_names() {
  std::cout << "Creating Matt list:\n";
  Person::get_names();
  Person::sort();
}

void M::get_names_file(std::ifstream& fin) {
  std::cout << "Reading Mat friends from file...\n";
  Person::get_names_file(fin);
  Person::sort();
}

void M::show_names() const {
  std::cout << "Showing Matt list:\n";
  Person::show_names();
}

void M::save_names_file(std::ofstream& fout) const {
  std::cout << "Saving Mat data to file...\n";
  Person::save_names_file(fout);
}

// P methods:
void P::get_names() {
  std::cout << "Creating Patt list:\n";
  Person::get_names();
  Person::sort();
}

void P::get_names_file(std::ifstream& fin) {
  std::cout << "Reading Patt friends from file...\n";
  Person::get_names_file(fin);
  Person::sort();
}

void P::show_names() const {
  std::cout << "Showing Patt list:\n";
  Person::show_names();
}

void P::save_names_file(std::ofstream& fout) const {
  std::cout << "Saving Patt data to file...\n";
  Person::save_names_file(fout);
}

// friend methods:
std::set<std::string>
concatenate_lists(const Person& p1, const Person& p2) {
  std::set<std::string> res;
  std::set_union(
    p1.get_data().begin(), p1.get_data().end(),
    p2.get_data().begin(), p2.get_data().end(),
    std::insert_iterator<std::set<std::string>>(res, res.begin())
  );
  return res;
}

