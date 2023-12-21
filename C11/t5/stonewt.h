#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt {
private:
  enum Mode { STN, LBS };
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
  Stonewt operator*(double n) const;

  friend std::ostream& operator<<(std::ostream& os, const Stonewt& st);
  friend Stonewt operator*(double n, const Stonewt& st);
};

#endif
