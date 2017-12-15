#include "Date.h"
#include <string>
using namespace std;
bool f(int y) {
  if ( ( y % 100 != 0 && y % 4 == 0 ) || y % 400 == 0 )
  return true;
  return false;
}

Date::Date() {
	year_ = month_ = day_ = 0;
}

Date::Date(int year, int month, int day) {
    year_ = year;
    month_ = month;
    day_ = day;
}

int Date::alive_age(Date end, Date begin){
		return end.year_-begin.year_ ;
}

int Date::getYear() const {
    return year_;
}

void Date::setYear(int year) {
    year_ = year;
}

int Date::getMonth() const {
    return month_;
}

void Date::setMonth(int month) {
    month_ = month;
}

int Date::getDay() const {
    return day_;
}

void Date::setDay(int day) {
    day_ = day;
}

bool Date::isValid(Date date) {
  if ( date.year_ < 1000 || date.year_ > 9999 ) return false;
  if ( date.month_ < 1 || date.month_ > 12 ) return false;
  if ( date.day_ < 1 ) return false;
  if ( date.month_ == 2 ) {
    if ( f(date.year_) && date.day_ > 29 )
    return false;
    if ( !f(date.year_) && date.day_ > 28 )
    return false;
  }
  if ( date.month_ == 4 || date.month_ == 6 ||
       date.month_ == 9 || date.month_ == 11 )
  if ( date.day_ > 30 )
  return false;
  if ( date.month_ == 1 || date.month_ == 3 || date.month_ == 5 ||
       date.month_ == 7 || date.month_ == 9 || date.month_ == 10 ||
       date.month_ == 12 )
  if ( date.day_ > 31 ) return false;
  return true;
}

Date Date::stringToDate(std::string dateString) {
  Date date;
  int s[4] = {0}, j = 0, sum = 0;
  unsigned int i;
  for ( i = 0; i < dateString.length(); i++ ) {
	  if ( dateString[i] < '0' || dateString[i] > '9' ) {
    i++;
    s[j++] = sum;
    sum = 0;
  }
  sum = dateString[i] - '0' + 10 * sum;
  if ( i == dateString.length() - 1 )
	  s[j++] = sum;
  }
  date.year_ = s[0];
  date.month_ = s[1];
  date.day_ = s[2];
  return date;
}

std::string Date::dateToString(Date date) {
  std::string s;
  s += date.year_ / 1000 + '0';
  s += (date.year_ % 1000) / 100 + '0';
  s += (date.year_ % 100) / 10 + '0';
  s += date.year_ % 10 + '0';
  s += '-';
  s += date.month_ / 10 + '0';
  s += date.month_ % 10 + '0';
  s += '-';
  s += date.day_ / 10 + '0';
  s += date.day_ % 10 + '0';
  return s;
}

Date& Date::operator=(const Date& date) {
  year_ = date.year_;
  month_ = date.month_;
  day_ = date.day_;
  return *this;
}

bool Date::operator==(const Date& date) const {
  if ( year_ == date.year_ && month_ == date.month_ &&
  day_ == date.day_ )
  return true;
  return false;
  }

bool Date::operator>(const Date& date) const {
  if ( year_ > date.year_ )
  return true;
  if ( year_ == date.year_ && month_ > date.month_ )
  return true;
  if ( year_ == date.year_ && month_ == date.month_ &&
  day_ > date.day_ )
  return true;
  if ( year_ == date.year_ && month_ == date.month_ &&
  day_ == date.day_ )
  return true;
  if ( year_ == date.year_ && month_ == date.month_ &&
  day_ == date.day_ )
  return true;
  return false;
}

bool Date::operator<(const Date& date) const {
  if ( year_ < date.year_ )
  return true;
  if ( year_ == date.year_ && month_ < date.month_ )
  return true;
  if ( year_ == date.year_ && month_ == date.month_ && day_ < date.day_ )
  return true;
  if ( year_ == date.year_ && month_ == date.month_ &&
  day_ == date.day_ )
  return true;
  if ( year_ == date.year_ && month_ == date.month_ &&
  day_ == date.day_ )
    return true;
  return false;
}

bool Date::operator>=(const Date& date) const {
  if ( year_ > date.year_ )
  return true;
  if ( year_ == date.year_ && month_ > date.month_ )
  return true;
  if ( year_ == date.year_ && month_ == date.month_ && day_ > date.day_ )
  return true;
  if ( year_ == date.year_ && month_ == date.month_ &&
  day_ == date.day_ )
  return true;
  if ( year_ == date.year_ && month_ == date.month_ &&
  day_ == date.day_ )
    return true;
  return false;
}

bool Date::operator<=(const Date& date) const {
  if ( year_ < date.year_ )
  return true;
  if ( year_ == date.year_ && month_ < date.month_ )
  return true;
  if ( year_ == date.year_ && month_ == date.month_ && day_ < date.day_ )
  return true;
  if ( year_ == date.year_ && month_ == date.month_ &&
  day_ == date.day_ )
  return true;
  if ( year_ == date.year_ && month_ == date.month_ &&
  day_ == date.day_ )
  return true;
  return false;
}