
#define BOOST_TEST_MODULE TransactionReporterTests
#include <boost/test/included/unit_test.hpp>
#include <string>
#include "TransactionReporter.h"
#include "TransactionAPI.h"
#include "MoneyFormatter.h"

// Helper: reset budget to zero using only public API
static void resetBudgetToZero()
{
    TransactionAPI api;
    double current = TransactionAPI::getBudget();
    if (current != 0.0)
    {
        api.generateTransaction(-current, "reset-budget", "test-team");
    }
}


// When there are no transactions, a clear message should be returned

BOOST_AUTO_TEST_CASE(report_with_no_transactions)
{
    resetBudgetToZero();
    TransactionReporter reporter;

    std::string report = reporter.generateReport();

    BOOST_TEST(report == "No transactions recorded");
}


// Report with both revenue and cost, and correct totals & budget

BOOST_AUTO_TEST_CASE(report_with_revenue_and_cost)
{
    resetBudgetToZero();

    // Set an initial budget via the API so Remaining Budget section is meaningful
    TransactionAPI api;
    api.generateTransaction(100.0, "initial budget", "budget-team"); // budget = 100

    TransactionReporter reporter;

    // Create two known transactions (we control timestamp + id)
    Transaction revenueTx(
        10.0,
        "Sold snacks",
        "kitchen-team",
        "2025-11-26 12:00:00\n",
        1
    );

    Transaction costTx(
        -5.0,
        "Bought drinks",
        "kitchen-team",
        "2025-11-26 12:05:00\n",
        2
    );

    reporter.addTransaction(revenueTx);
    reporter.addTransaction(costTx);

    std::string report = reporter.generateReport();

    // Check revenue section content
    BOOST_TEST(report.find("REVENUE") != std::string::npos);
    BOOST_TEST(report.find("Sold snacks") != std::string::npos);
    BOOST_TEST(report.find("Profit: $10.00") != std::string::npos);

    // Check cost section content
    BOOST_TEST(report.find("COST") != std::string::npos);
    BOOST_TEST(report.find("Bought drinks") != std::string::npos);
    BOOST_TEST(report.find("Cost: -$5.00") != std::string::npos);

    // Total (10 - 5 = 5)
    BOOST_TEST(report.find(MoneyFormatter::formatMoney(5.0)) != std::string::npos);

    // Remaining budget (we set it to 100 via API)
    BOOST_TEST(report.find(MoneyFormatter::formatMoney(100.0)) != std::string::npos);
}


//Report with only revenue should say "No costs in this report"

BOOST_AUTO_TEST_CASE(report_with_only_revenue)
{
    resetBudgetToZero();

    TransactionReporter reporter;

    Transaction revenueTx(
        20.0,
        "Ticket sales only",
        "events-team",
        "2025-11-26 14:00:00\n",
        10
    );
    reporter.addTransaction(revenueTx);

    std::string report = reporter.generateReport();

    BOOST_TEST(report.find("Ticket sales only") != std::string::npos);
    BOOST_TEST(report.find("Profit: $20.00") != std::string::npos);
    BOOST_TEST(report.find("No costs in this report") != std::string::npos);
}
