#ifndef TV_H_
#define TV_H_

class Remote; // For Tv public method

class Tv {
public:
  friend class Remote;
  enum { Off, On };
  enum { MinVal, MaxVal = 20 };
  enum { Antenna, Cable };
  enum { TV, DVD };
  Tv(int s = Off, int mc = 125)
    : state(s), volume(5), maxchannel(mc), channel(2), mode(Cable), input(TV) {}
  void onoff() { state ^= 1; }
  bool ison() const { return state == On; }
  bool volup();
  bool voldown();
  void chanup();
  void chandown();
  void set_mode() { mode ^= 1; }
  void set_input() { input ^= 1; }
  void settings() const;
  void change_remote_mode(Remote&) const;
private:
  int state;
  int volume;
  int maxchannel;
  int channel;
  int mode;
  int input;
};

class Remote {
private:
  int mode;
  int mode_remote;
public:
  friend class Tv;
  enum { Normal, Interactive };
  Remote(int m = Tv::TV, int mr = Normal): mode(m), mode_remote(mr) {}
  bool volup(Tv& t) { return t.volup(); }
  bool voldown(Tv& t) { return t.voldown(); }
  void onoff(Tv& t) { t.onoff(); }
  void chanup(Tv& t) { t.chanup(); }
  void chandown(Tv& t) { t.chandown(); }
  void set_chan(Tv& t, int c) { t.channel = c; }
  void set_mode(Tv& t) { t.set_mode(); }
  void set_input(Tv& t) { t.set_input(); }
  void show_remote_mode() const;
  void set_remote_mode() { mode_remote ^= 1; }
};

#endif /* TV_H_ */
