#include "TransactionAPI.h"
#include "Transaction.h"


void TransactionAPI::updateDatabase(Transaction t) {
    // do db update stuff, use db's api for this
}
void TransactionAPI::generateTransaction(double moneyGain, std::string details, std::string transactionInitiatingTeam) {
    Transaction t(moneyGain, details, transactionInitiatingTeam);
    updateDatabase(t);
}
