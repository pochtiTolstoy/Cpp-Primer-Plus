#ifndef EMP_H_
#define EMP_H_
#include <iostream>
#include <string>

class abstr_emp {
private:
  std::string fname;
  std::string lname;
  std::string job;
public:
  abstr_emp();
  abstr_emp(
    const std::string&, 
    const std::string&, 
    const std::string&
  );
  virtual void ShowAll() const;
  virtual void SetAll();
  friend std::ostream& operator<<(std::ostream&, const abstr_emp&);
  virtual ~abstr_emp() = 0;
};

class employee: public abstr_emp {
public:
  employee();
  employee(
    const std::string&, 
    const std::string&, 
    const std::string&
  );
  virtual void ShowAll() const;
  virtual void SetAll();
};

class manager: virtual public abstr_emp {
private:
  int inchargeof;
protected:
  int InChargeOf() const { return inchargeof; }
  int& InChargeOf() { return inchargeof; }
public:
  manager();
  manager(
    const std::string&, 
    const std::string&, 
    const std::string&, 
    int ico = 0
  );
  manager(const abstr_emp&, int);
  manager(const manager&);
  virtual void ShowAll() const;
  virtual void SetAll();
};

class fink: virtual public abstr_emp {
private:
  std::string reportsto;
protected:
  const std::string ReportsTo() const { return reportsto; }
  std::string& ReportsTo() { return reportsto; }
public:
  fink();
  fink(
    const std::string&,
    const std::string&,
    const std::string&,
    const std::string&
  );
  fink(const abstr_emp&, const std::string&);
  fink(const fink&);
  virtual void ShowAll() const;
  virtual void SetAll();
};

class highfink: public manager, public fink {
public:
  highfink();
  highfink(
    const std::string&,
    const std::string&,
    const std::string&,
    const std::string&,
    int ico
  );
  highfink(
    const abstr_emp&,
    const std::string&,
    int ico
  );
  highfink(const fink&, int ico);
  highfink(const manager&, const std::string&);
  highfink(const highfink&);
  virtual void ShowAll() const;
  virtual void SetAll();
};

#endif /* EMP_H_ */
