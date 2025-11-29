#define BOOST_TEST_MODULE TransactionValueTest
#include <boost/test/included/unit_test.hpp>
#include "Transaction.h"

BOOST_AUTO_TEST_CASE(default_ctor_initializes_fields)
{
    Transaction t;
    BOOST_TEST(t.getMoneyGain() == 0.0);
    BOOST_TEST(t.getDetails() == "");
    BOOST_TEST(t.getTimestamp() == "");
    BOOST_TEST(t.getTransactionInitiatingTeam() == "");
    BOOST_TEST(t.getID() == 0UL);
}

BOOST_AUTO_TEST_CASE(ctor_sets_fields_with_timestamp_id)
{
    double amount = -4.5;
    std::string details = "burger";
    std::string team = "Menu-Team";
    std::string ts = "2024-01-01 00:00:00";
    unsigned long id = 42;

    Transaction t(amount, details, team, ts, id);

    BOOST_TEST(t.getMoneyGain() == amount);
    BOOST_TEST(t.getDetails() == details);
    BOOST_TEST(t.getTimestamp() == ts);
    BOOST_TEST(t.getTransactionInitiatingTeam() == team);
    BOOST_TEST(t.getID() == id);
}

BOOST_AUTO_TEST_CASE(ctor_sets_fields_without_timestamp_id)
{
    double amount = 10.0;
    std::string details = "Added money";
    std::string team = "The Team";

    Transaction t(amount, details, team);

    BOOST_TEST(t.getMoneyGain() == amount);
    BOOST_TEST(t.getDetails() == details);
    BOOST_TEST(t.getTransactionInitiatingTeam() == team);
    // timestamp and id are implementation‑defined here, so we only check not-empty timestamp
    BOOST_TEST(!t.getTimestamp().empty());
}
