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
  /*
  void show_lbs() const;
  void show_stn() const;
  */
  Stonewt& operator=(const Stonewt& st);
  Stonewt operator*(double n) const;
  Stonewt operator+(const Stonewt& st) const;
  Stonewt operator+(double pnd) const;
  Stonewt operator-(const Stonewt& st) const;
  Stonewt operator-(double pnd) const;

  friend std::ostream& operator<<(std::ostream& os, const Stonewt& st);
  friend Stonewt operator*(double n, const Stonewt& st);
  friend Stonewt operator+(double pnd, const Stonewt& st);
  friend Stonewt operator-(double pnd, const Stonewt& st);
};

#endif
