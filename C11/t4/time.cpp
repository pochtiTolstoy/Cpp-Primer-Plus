#include "time.h"

Time::Time() {
  hours = minutes = 0;
}

Time::Time(int h, int m) {
  hours = h;
  minutes = m;
}
void Time::AddMin(int m) {
  minutes += m;
  hours += minutes / 60;
  minutes %= 60;
}

void Time::AddHr(int h) {
  hours += h;
}

void Time::Reset(int h, int m) {
  hours = h;
  minutes = m;
}

Time operator+(const Time& n1, const Time& n2) {
  Time sum;
  sum.minutes = n1.minutes + n2.minutes;
  sum.hours = n1.hours + n2.hours + sum.minutes / 60;
  sum.minutes %= 60;
  return sum;
}

Time operator-(const Time& n1, const Time& n2) {
  Time diff;
  int tot1 = n1.hours * 60 + n1.minutes;
  int tot2 = n2.hours * 60 + n2.minutes;
  diff.minutes = (tot1 - tot2) % 60;
  diff.hours = (tot1 - tot2) / 60;
  return diff;
}

Time operator*(const Time& n1, double n2) {
  Time result;
  long tot = (n1.hours * 60 + n1.minutes) * n2;
  result.hours = tot / 60;
  result.minutes = tot % 60;
  return result;
}

std::ostream& operator<<(std::ostream& os, const Time& t) {
  os << t.hours << " hours, " << t.minutes << " minutes";
  return os;
}
