#ifndef PAIR_H_
#define PAIR_H_

template <typename T1, typename T2>
class Pair {
private:
  T1 arr1_;
  T2 arr2_;
public:
  explicit Pair(int size = 0);
  template <typename U1, typename U2>
  Pair(const U1&, const U2&, int size);
  template <typename U> U& get1(int);
  template <typename U> U& get2(int);
  template <typename U> U get1(int) const;
  template <typename U> U get2(int) const;
  template <typename U> U sum1() const;
  template <typename U> U sum2() const;
};

template <typename T1, typename T2>
Pair<T1, T2>::Pair(int size): arr1_(size), arr2_(size) {}

template <typename T1, typename T2>
  template <typename U1, typename U2>
  Pair<T1, T2>::Pair(const U1& arr1, const U2& arr2, int size)
    : arr1_(arr1, size), arr2_(arr2, size) {}

template <typename T1, typename T2>
  template <typename U>
  U& Pair<T1, T2>::get1(int i) { return arr1_[i]; }

template <typename T1, typename T2>
  template <typename U>
  U& Pair<T1, T2>::get2(int i) { return arr2_[i]; }

template <typename T1, typename T2>
  template <typename U>
  U Pair<T1, T2>::get1(int i) const { return arr1_[i]; }

template <typename T1, typename T2>
  template <typename U>
  U Pair<T1, T2>::get2(int i) const { return arr2_[i]; }

template <typename T1, typename T2>
  template <typename U>
  U Pair<T1, T2>::sum1() const {
    return arr1_.sum();
  }

template <typename T1, typename T2>
  template <typename U>
  U Pair<T1, T2>::sum2() const {
    return arr2_.sum();
  }

#endif /* PAIR_H_ */
