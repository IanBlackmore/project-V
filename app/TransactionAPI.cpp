#include "TransactionAPI.h"
#include "Transaction.h"
#include <iostream>


void TransactionAPI::updateDatabase(Transaction t) {
    // do db update stuff, use db's api for this
}
std::ostringstream TransactionAPI::generateTransaction(double moneyGain, std::string details, std::string transactionInitiatingTeam) {
    Transaction t(moneyGain, details, transactionInitiatingTeam);
    updateDatabase(t);
    std::ostringstream response;
    response << "Transaction created:\n"
        << "Amount: " << moneyGain << "\n"
        << "Details: " << details << "\n"
        << "Team: " << transactionInitiatingTeam << "\n";
    return response;
}
