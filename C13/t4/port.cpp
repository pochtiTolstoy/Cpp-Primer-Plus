#include <cstring>
#include "port.h"

Port::Port(const char* br, const char* st, int b) {
  brand = new char[std::strlen(br) + 1];
  std::strcpy(brand, br);
  std::strncpy(style, st, 19);
  style[19] = '\0';
  if (b < 0) {
    std::cout << "You can't have negative amount of bottles.\n"
      << "Set bottle value to zero.\n";
    bottles = 0;
  } else
    bottles = b;
}

Port::Port(const Port& p) {
  brand = new char[std::strlen(p.brand) + 1];
  std::strcpy(brand, p.brand);
  std::strcpy(style, p.style);
  bottles = p.bottles;
}

Port& Port::operator=(const Port& p) {
  if (this == &p)
    return *this;
  delete[] brand;
  brand = new char[std::strlen(p.brand) + 1];
  std::strcpy(brand, p.brand);
  std::strcpy(style, p.style);
  bottles = p.bottles;
  return *this;
}

Port& Port::operator+=(int b) {
  bottles += b; 
  return *this;
}

Port& Port::operator-=(int b) {
  if (bottles < b) {
    std::cout << "You can't have negative amount of bottles.\n"
      << "Set bottle value to zero.\n";
    bottles = 0;
  } else
    bottles -= b; 
  return *this;
}

void Port::Show() const {
  std::cout << "Brand: " << brand << '\n'
    << "Kind: " << style << '\n'
    << "Bottles: " << bottles << '\n';
}

std::ostream& operator<<(std::ostream& os, const Port& p) {
  os << p.brand << ", " << p.style << ", " << p.bottles;
  return os;
}

// Class VintagePort
const char* VintagePort::custom_style = "vintage";
const char* VintagePort::none_str = "none";
VintagePort::VintagePort() : Port(none_str, custom_style) {
  nickname = new char[std::strlen(none_str) + 1];
  std::strcpy(nickname, none_str);
  year = -1; 
}

VintagePort::VintagePort(const char* br, int b, const char* nn, int y)
  : Port(br, custom_style, b) {
  nickname = new char[std::strlen(nn) + 1];
  std::strcpy(nickname, nn);
  year = y;
}

VintagePort::VintagePort(const VintagePort& vp) : Port(vp) {
  nickname = new char[std::strlen(vp.nickname) + 1];
  std::strcpy(nickname, vp.nickname);
  year = vp.year; 
}

VintagePort& VintagePort::operator=(const VintagePort& vp) {
  if (this == &vp)
    return *this;
  Port::operator=(vp);
  delete[] nickname;
  nickname = new char[std::strlen(vp.nickname) + 1];
  std::strcpy(nickname, vp.nickname);
  year = vp.year;
  return *this;
}

void VintagePort::Show() const {
  std::cout << "Nickname: " << nickname << '\n';
  Port::Show();
  std::cout << "Year: " << year << '\n';
}

std::ostream& operator<<(std::ostream& os, const VintagePort& vp) {
  os << vp.nickname << ", ";
  os << dynamic_cast<const Port&>(vp);
  os << ", " << vp.year;
  return os;
}
