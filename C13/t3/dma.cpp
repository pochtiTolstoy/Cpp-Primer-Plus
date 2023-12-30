#include "dma.h"
#include <cstring>

// Abstract class abcDMA
abcDMA::abcDMA(const char* l, int r) {
  label = new char[std::strlen(l) + 1];
  std::strcpy(label, l);
  rating = r;
}

abcDMA::abcDMA(const abcDMA& rs) {
  label = new char[std::strlen(rs.label) + 1];
  std::strcpy(label, rs.label);
  rating = rs.rating;
}

abcDMA::~abcDMA() {
  delete[] label;
}

void abcDMA::View() const {
  std::cout << "View method:\n";
  std::cout << "Label: " << label << '\n';
  std::cout << "Rating: " << rating << '\n';
}

abcDMA& abcDMA::operator=(const abcDMA& rs) {
  if (this == &rs)
    return *this;
  delete[] label;
  label = new char[std::strlen(rs.label) + 1];
  std::strcpy(label, rs.label);
  rating = rs.rating;
  return *this;
}

std::ostream& operator<<(std::ostream& os, const abcDMA& rs) {
  os << "Label: " << rs.label << '\n';
  os << "Rating: " << rs.rating << '\n';
  return os;
}

// Class baseDMA
baseDMA::baseDMA(const char* l, int r) : abcDMA(l, r) {}

baseDMA::baseDMA(const baseDMA& rs) : abcDMA(rs) {}

baseDMA::~baseDMA() {} // Automaticliy calls ~abcDMA()

// pure virtual function in abcDMA override
void baseDMA::View() const {
  abcDMA::View(); 
}

baseDMA& baseDMA::operator=(const baseDMA& rs) {
  abcDMA::operator=(rs);
  return *this;
}

std::ostream& operator<<(std::ostream& os, const baseDMA& rs) {
  os << dynamic_cast<const abcDMA&>(rs); 
  return os;
}

// Class lacksDMA
lacksDMA::lacksDMA(const char* c, const char* l, int r) 
  : abcDMA(l, r) {
  std::strncpy(color, c, COL_LEN - 1);
  color[COL_LEN - 1] = '\0';
}

lacksDMA::lacksDMA(const char* c, const abcDMA& rs)
  : abcDMA(rs) {
  std::strncpy(color, c, COL_LEN - 1);
  color[COL_LEN - 1] = '\0';
}

void lacksDMA::View() const {
  abcDMA::View();
  std::cout << "Color: " << color << '\n';
}

std::ostream& operator<<(std::ostream& os, const lacksDMA& ls) {
  os << dynamic_cast<const abcDMA&>(ls); 
  os << "Color: " << ls.color << '\n';
  return os;
}

// Class hasDMA
hasDMA::hasDMA(const char* s, const char* l, int r) 
  : abcDMA(l, r) {
  style = new char[std::strlen(s) + 1];
  std::strcpy(style, s);
}

hasDMA::hasDMA(const char* s, const abcDMA& rs) 
  : abcDMA(rs) {
  style = new char[std::strlen(s) + 1];
  std::strcpy(style, s);
}

hasDMA::hasDMA(const hasDMA& hs) : abcDMA(hs) {
  style = new char[std::strlen(hs.style) + 1];
  std::strcpy(style, hs.style);
}

hasDMA::~hasDMA() {
  delete[] style;
}

void hasDMA::View() const {
  abdDMA::View(); 
  std::cout << "Style: " << style << '\n';
}

hasDMA& hasDMA::operator=(const hasDMA& hs) {
  if (this == &hs)
    return *this;
  abcDMA::operator=(hs);
  delete[] style;
  style = new char[std::strlen(hs.style) + 1];
  std::strcpy(style, hs.style);
  return *this;
}

std::ostream& operator<<(std::ostream& os, const hasDMA& hs) {
  os << dynamic_cast<const abcDMA&>(hs);
  os << "Style: " << hs.style << '\n';
  return os;
}
