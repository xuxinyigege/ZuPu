#ifndef Date_H
#define Date_H

#include <string>
#include<iostream>
using namespace std;
class Date {
 public:
  Date();
  Date(int, int, int);
  int alive_age(Date end, Date begin); 
  void print_date();
  int getYear() const;
  void setYear(int year);
  int getMonth() const;
  void setMonth(int month);
  int getDay() const;
  void setDay(int day);
  bool isValid(Date date);
  Date stringToDate(std::string dateString);
  std::string dateToString(Date date);
  Date &operator=(const Date& date);
  bool operator==(const Date& date) const;
  bool operator>(const Date& date) const;
  bool operator<(const Date& date) const;
  bool operator>=(const Date& date) const;
  bool operator<=(const Date& date) const;

 private:
  int year_;
  int month_;
  int day_;
};
#endif

