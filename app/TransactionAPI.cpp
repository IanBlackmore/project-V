#include "TransactionAPI.h"
#include "Transaction.h"
#include <iostream>
#include <string>

void TransactionAPI::updateDatabase(Transaction t) {
    // do db update stuff, use db's api for this
}
std::string TransactionAPI::generateTransaction(double moneyGain, std::string details, std::string transactionInitiatingTeam) {
    Transaction t(moneyGain, details, transactionInitiatingTeam);
    updateDatabase(t);
    std::string response;
    response = "Transaction created:\nAmount: " + std::to_string(moneyGain) 
        + "\nDetails: " + details 
        + "\nTeam: " + transactionInitiatingTeam + "\n";
    return response;
}
