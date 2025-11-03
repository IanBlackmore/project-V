#define BOOST_TEST_MODULE Transaction Test 
#include <boost/test/included/unit_test.hpp> 

// TESTING FORMAT
/*BOOST_AUTO_TEST_CASE(test_name) 
{
    // do test stuff
    // test format
    //BOOST_TEST(1==1)); 
}*/


BOOST_AUTO_TEST_CASE(test_name) 
{
    TransactionAPI api;
    api.generateTransaction(moneyGain, details, teamName);
    //BOOST_TEST(1==1)); 
}