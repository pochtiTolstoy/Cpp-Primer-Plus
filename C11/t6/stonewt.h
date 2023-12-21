#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt {
public:
  enum Mode { STN, LBS };
private:
  static const int Lbs_per_stn = 14;
  int stone;
  double pds_left;
  double pounds;
  Mode mode;
public:
  Stonewt(double lbs, Mode form = LBS);
  Stonewt(int stn, double lbs, Mode form = STN);
  Stonewt();
  ~Stonewt();
  void lbs_mode(void);
  void stn_mode(void);

// Operators
  Stonewt& operator=(const Stonewt& st);
  Stonewt operator*(double n) const;
  Stonewt operator+(const Stonewt& st) const;
  Stonewt operator+(double pnd) const;
  Stonewt operator-(const Stonewt& st) const;
  Stonewt operator-(double pnd) const;

// Comparison operators
  // Class-Class operators 
  bool operator<(const Stonewt& st) const;
  bool operator<=(const Stonewt& st) const;
  bool operator>(const Stonewt& st) const;
  bool operator>=(const Stonewt& st) const;
  bool operator==(const Stonewt& st) const;
  bool operator!=(const Stonewt& st) const;
  
  // Class-Obj operators
  bool operator<(double n) const;
  bool operator<=(double n) const;
  bool operator>(double n) const;
  bool operator>=(double n) const;
  bool operator==(double n) const;
  bool operator!=(double n) const;
  
  //Obj-Class operators
  friend bool operator<(double n, const Stonewt& st);
  friend bool operator<=(double n, const Stonewt& st);
  friend bool operator>(double n, const Stonewt& st);
  friend bool operator>=(double n, const Stonewt& st);
  friend bool operator==(double n, const Stonewt& st);
  friend bool operator!=(double n, const Stonewt& st);

  friend std::ostream& operator<<(std::ostream& os, const Stonewt& st);
  friend Stonewt operator*(double n, const Stonewt& st);
  friend Stonewt operator+(double pnd, const Stonewt& st);
  friend Stonewt operator-(double pnd, const Stonewt& st);
};

#endif
