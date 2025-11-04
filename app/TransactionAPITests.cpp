#define BOOST_TEST_MODULE Transaction Test 
#include <boost/test/included/unit_test.hpp> 
#include <iostream>
#include <string>
#include "TransactionAPI.h"


BOOST_AUTO_TEST_CASE(test_name) 
{
    TransactionAPI api;
    std::string result;
    double moneyGain = 4.1;
    std::string details = "Added money";
    std::string teamName = "the team";
    result = api.generateTransaction(moneyGain, details, teamName);
    std::string expected = "Transaction created:\nAmount: " + std::to_string(moneyGain) 
        + "\nDetails: " + details 
        + "\nTeam: " + teamName + "\n";
    BOOST_TEST(expected == result); 
}