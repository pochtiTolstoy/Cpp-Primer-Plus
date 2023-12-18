#ifndef SALES_H_
#define SALES_H_
/*
namespace SALES {
  const int QUARTERS = 4;
  struct Sales {
    double sales[QUARTERS];
    double average;
    double max;
    double min;
  };
  void setSales(Sales&, const double [], int);
  void setSales(Sales&);
  void showSales(const Sales&);
}
*/
namespace SALES {
  class Sales {
  private:
    static const int QUARTERS = 4;
    double sales[QUARTERS];
    double average;
    double max;
    double min;
  public:
    Sales();
    Sales(const double ar[], int n);
    void setSales(void);
    void showSales(void) const;
  };
}

#endif
