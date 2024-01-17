#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <memory>

struct Review {
  std::string title;
  int rating;
  double price;
};

typedef std::vector<std::shared_ptr<Review>> VEC;

void free_io();
void free_buffer();
bool FillReview(Review& rr);
void ShowReview(const Review& rr);
void output_menu(char choice, const VEC& vec);
void show_vec(const VEC& v);
void show_alph_vec(const VEC& v);
bool alph_comp(
  const std::shared_ptr<Review>& p1,
  const std::shared_ptr<Review>& p2
);
void show_by_rating(const VEC& v);
bool rating_comp(
  const std::shared_ptr<Review>& p1,
  const std::shared_ptr<Review>& p2
);
void show_by_price_up(const VEC& v);
bool price_comp(
  const std::shared_ptr<Review>& p1,
  const std::shared_ptr<Review>& p2
);
void show_by_price_down(const VEC& v);
bool price_comp_reverse(
  const std::shared_ptr<Review>& p1,
  const std::shared_ptr<Review>& p2
);
bool operator<(const Review& r1, const Review& r2);
bool worseThan(const Review& r1, const Review& r2);

int main() {
  std::vector<Review> books;
  Review temp;
  VEC books_heap;
  while (FillReview(temp)) {
    books.push_back(temp);
    books_heap.push_back(std::shared_ptr<Review>(new Review(temp)));
  }
  if (books.size() > 0) {
    std::cout 
      << "a) Исходный порядок\n"
      << "b) Алфавитный порядок\n"
      << "c) По возрастанию рейтинга\n"
      << "d) По возрастанию цены\n"
      << "e) В порядке убывания цены\n"
      << "q) Выход\n";
    char choice;
    std::cout << "-- Ввод: ";
    while (std::cin >> choice && choice != 'q') {
      free_io(); 
      output_menu(choice, books_heap); 
      std::cout << "-- Ввод: ";
    }
    free_io();
  } else {
    std::cout << "No entries.\n";
  }
  std::cout << "Bye.\n";
  return 0;
}


bool FillReview(Review& rr) {
  std::cout << "Enter book title (quit to quit): ";
  std::getline(std::cin, rr.title);
  if (rr.title == "quit") return false;
  std::cout << "Enter book rating: ";
  std::cin >> rr.rating;
  if (!std::cin) {
    free_io();
    return false;
  }
  std::cout << "Enter price of the book: ";
  std::cin >> rr.price;
  if (!std::cin) {
    free_io();
    return false;
  }
  while (std::cin.get() != '\n')
    continue;
  return true;
}

void show_vec(const VEC& v) {
  for (auto const& ptr: v)
    ShowReview(*ptr);
}

bool alph_comp(
  const std::shared_ptr<Review>& p1,
  const std::shared_ptr<Review>& p2
) {
  return *p1 < *p2;
}

void show_alph_vec(const VEC& v) {
  VEC temp = v;
  std::sort(temp.begin(), temp.end(), alph_comp);
  show_vec(temp);
}

void show_by_rating(const VEC& v) {
  VEC temp = v;
  std::sort(temp.begin(), temp.end(), rating_comp);
  show_vec(temp);
}

bool rating_comp(
  const std::shared_ptr<Review>& p1,
  const std::shared_ptr<Review>& p2
) {
  return worseThan(*p1, *p2); 
}

void show_by_price_up(const VEC& v) {
  VEC temp = v;
  std::sort(temp.begin(), temp.end(), price_comp);
  show_vec(temp); 
}

bool price_comp(
  const std::shared_ptr<Review>& p1,
  const std::shared_ptr<Review>& p2
) {
  return p1->price < p2->price;
}

void show_by_price_down(const VEC& v) {
  VEC temp = v;
  std::sort(temp.begin(), temp.end(), price_comp_reverse);
  show_vec(temp);
}

bool price_comp_reverse(
  const std::shared_ptr<Review>& p1,
  const std::shared_ptr<Review>& p2
) {
  return p1->price >= p2->price;
}

void ShowReview(const Review& rr) {
  std::cout << rr.rating << "\t" << rr.title 
    << "\t\t$" << rr.price << std::endl;
}

void output_menu(char choice, const VEC& vec) {
  switch (choice) {
    case 'A':
    case 'a': show_vec(vec); break;
    case 'B':
    case 'b': show_alph_vec(vec); break;
    case 'C':
    case 'c': show_by_rating(vec); break;
    case 'D':
    case 'd': show_by_price_up(vec); break;
    case 'E':
    case 'e': show_by_price_down(vec); break;
    default: 
      std::cout << "There is no such option: " << choice << '\n';
  }
}

bool operator<(const Review& r1, const Review& r2) {
  return r1.title < r2.title;
}

bool worseThan(const Review& r1, const Review& r2) {
  return r1.rating < r2.rating;
}

void free_io() {
  if (std::cin.fail())
    std::cin.clear();
  free_buffer();
}

void free_buffer() {
  while (std::cin.get() != '\n')
    continue;
}
