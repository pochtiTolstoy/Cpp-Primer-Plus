#ifndef EMP_H_
#define EMP_H_
#include <iostream>
#include <fstream>
#include <string>

enum classkind { Employee, Manager, Fink, Highfink };

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
  virtual void WriteAll(std::ofstream&) const = 0;
  virtual void SetAll();
  virtual void GetAll(std::ifstream&);
  virtual classkind Type() const = 0;
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
  void ShowAll() const override;
  void WriteAll(std::ofstream&) const override;
  void SetAll() override;
  classkind Type() const override;
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
  void ShowAll() const override;
  void WriteAll(std::ofstream&) const override;
  void SetAll() override;
  void GetAll(std::ifstream&) override;
  classkind Type() const override;
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
  void ShowAll() const override;
  void WriteAll(std::ofstream&) const override;
  void SetAll() override;
  void GetAll(std::ifstream&) override;
  classkind Type() const override;
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
  void ShowAll() const override;
  void WriteAll(std::ofstream&) const override;
  void SetAll() override;
  void GetAll(std::ifstream&) override;
  classkind Type() const override;
};

#endif /* EMP_H_ */
