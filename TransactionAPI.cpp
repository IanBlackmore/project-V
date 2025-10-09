#include "TransactionAPI.h"
#include "Transaction.h"


void TransactionAPI::updateDatabase(Transaction t) {
    // do db update stuff, use db's api for this
}
void TransactionAPI::generateTransaction(double moneyGain, std::string details) {
    Transaction t(moneyGain, details);
    updateDatabase(t);
}
