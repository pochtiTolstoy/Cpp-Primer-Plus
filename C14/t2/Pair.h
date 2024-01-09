#ifndef PAIR_H_
#define PAIR_H_

template <typename T1, typename T2>
class Pair {
private:
  T1 arr1_;
  T2 arr2_;
public:
  Pair();
  Pair(const T1&, const T2&);
  T1& first();
  T2& second();
  T1 first() const { return arr1_; }
  T2 second() const { return arr2_; }
};

template <typename T1, typename T2>
Pair<T1, T2>::Pair(): arr1_(0), arr2_(0) {}

template <typename T1, typename T2>
Pair<T1, T2>::Pair(const T1& a, const T2& b): arr1_(a), arr2_(b) {}

template <typename T1, typename T2>
T1& Pair<T1, T2>::first() { return arr1_; }

template <typename T1, typename T2>
T2& Pair<T1, T2>::second() { return arr2_; }

#endif /* PAIR_H_ */
