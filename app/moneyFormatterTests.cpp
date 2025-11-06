#define BOOST_TEST_MODULE MoneyFormatter Test 
#include <boost/test/included/unit_test.hpp> 
#include <iostream>
#include "MoneyFormatter.h"


BOOST_AUTO_TEST_CASE(format_money) 
{
    std::string expected = "$2.20";
    double moneyGain = 2.20;
    std::string result = MoneyFormatter::formatMoney(moneyGain); 
    BOOST_TEST(expected == result); 
}

BOOST_AUTO_TEST_CASE(format_negative_money) 
{
    std::string expected = "-$4.23";
    double moneyGain = -4.23;
    std::string result = MoneyFormatter::formatMoney(moneyGain); 
    BOOST_TEST(expected == result); 
}