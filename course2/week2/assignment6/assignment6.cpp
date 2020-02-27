#include "phone_number.h"
#include <stdexcept>


PhoneNumber::PhoneNumber(const string &international_number){
  if (international_number.size() == 0 || international_number.at(0) != '+') {
    throw invalid_argument("");
  }
  string curNum;
  char curLet;
  for (int i = 1; i < international_number.size(); ++i) {
    curLet = international_number.at(i);
    if (international_number.at(i) == '-') {
      if (curNum.size() == 0) {
        throw invalid_argument("");
      } else {
        if (country_code_.size() == 0) {
          country_code_ = curNum;
        } else if (city_code_.size() == 0) {
          city_code_ = curNum;
        } else {
          local_number_ += curNum + curLet;
        }
        curNum = "";
      }
    } else {
      curNum += curLet;
    }
  }
  if (city_code_.size() == 0) {
    throw invalid_argument("");
  }
  local_number_ += curNum;
}

string PhoneNumber::GetCountryCode() const {
  return country_code_;
}
string PhoneNumber::GetCityCode() const{
  return city_code_;
}
string PhoneNumber::GetLocalNumber() const{
  return local_number_;
}
string PhoneNumber::GetInternationalNumber() const{
  return '+' + country_code_ + '-' + city_code_ + '-' + local_number_;
}

// int main() {
//   return 0;
// }