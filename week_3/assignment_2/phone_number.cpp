//
// Created by d.eroshenkov on 16.10.2018.
//

#include "phone_number.h"
#include <sstream>
#include <iostream>

PhoneNumber::PhoneNumber(const string &international_number)
{
    istringstream is(international_number);

    char sign = is.get();

    getline(is, country_code_, '-');
    getline(is, city_code_, '-');
    getline(is, local_number_);

    if (sign != '+' || country_code_.empty() || city_code_.empty() || local_number_.empty())
    {
        throw invalid_argument("");
    }
}

string PhoneNumber::GetCountryCode() const
{
    return country_code_;
}

string PhoneNumber::GetCityCode() const
{
    return city_code_;
}

string PhoneNumber::GetLocalNumber() const
{
    return local_number_;
}

string PhoneNumber::GetInternationalNumber() const
{
    return ('+' + country_code_ + '-' + city_code_ + '-' + local_number_);
}

//int main()
//{
//    PhoneNumber number("+7-1233");
//    cout << number.GetInternationalNumber() << endl;
//    cout << number.GetCountryCode() << "-" << number.GetCityCode() << "-" << number.GetLocalNumber() << endl;
//}