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

// Zero value
BOOST_AUTO_TEST_CASE(format_money_zero)
{
    double moneyGain = 0.0;
    std::string expected = "$0.00";

    std::string result = MoneyFormatter::formatMoney(moneyGain);

    BOOST_TEST(result == expected);
}

// Rounding up to 2 decimals
BOOST_AUTO_TEST_CASE(format_money_rounding_up)
{
    double moneyGain = 2.206;          // should round to 2.21
    std::string expected = "$2.21";

    std::string result = MoneyFormatter::formatMoney(moneyGain);

    BOOST_TEST(result == expected);
}

// Rounding negative values
BOOST_AUTO_TEST_CASE(format_money_negative_rounding)
{
    double moneyGain = -3.756;         // should round to -3.76
    std::string expected = "-$3.76";

    std::string result = MoneyFormatter::formatMoney(moneyGain);

    BOOST_TEST(result == expected);
}