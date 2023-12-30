#ifndef DMA_H_
#define DMA_H_

#include <iostream>

class abcDMA {
private:
  char* label;
  int rating;
public:
  abcDMA(const char* l = "null", int r = 0);
  abcDMA(const abcDMA& rs);
  virtual ~abcDMA();
  virtual void View() const = 0;
  abcDMA& operator=(const abcDMA& rs);
  friend std::ostream& operator<<(std::ostream& os, const abcDMA& rs);
};

class baseDMA : public abcDMA {
public:
  baseDMA(const char* l = "null", int r = 0);
  baseDMA(const baseDMA& rs); // конструктор копирования
  ~baseDMA() override; // виртуальный деструктор
  void View() const override;
  baseDMA& operator=(const baseDMA& rs); // операция присваивания
  friend std::ostream& operator<<(std::ostream& os, const baseDMA& rs);
  // дружественная функция
};

// implicit destructor
// implicit copy constructor
// implicit assignment operator
class lacksDMA : public abcDMA {
private:
  enum { COL_LEN = 40 };
  char color[COL_LEN];
public:
  lacksDMA(const char* c = "blank", const char* l = "null", int r = 0);
  lacksDMA(const char* c, const abcDMA& rs);
  void View() const override;
  friend std::ostream& operator<<(std::ostream& os, const lacksDMA& rs);
};

class hasDMA : public abcDMA {
private:
  char* style;
public:
  hasDMA(const char* s = "none", const char* l = "null", int r = 0);
  hasDMA(const char* s, const abcDMA& rs);
  hasDMA(const hasDMA& hs);
  ~hasDMA() override;
  void View() const override;
  hasDMA& operator=(const hasDMA& rs);
  friend std::ostream& operator<<(std::ostream& os, const hasDMA& rs);
};

#endif /* DMA_H_ */
