#include "TransactionAPI.h"
#include "Transaction.h"
#include <iostream>
#include <string>

void TransactionAPI::addDBTransaction(Transaction t) {
    // do db insert stuff, use db's api for this
    //pseudocode
    // unparameterized
    //std::string dbString = "INSERT INTO budget_table (Timestamp, MoneyGain, Details, Team_Initiating_Transaction) " 
    //+ "VALUES (" + t.getTimestamp() + ", " + std::to_string(t.getMoneyGain()) + ", " + t.getDetails() 
    //+ ", " + t.getTransactionInitiatingTeam() +  ")";
    
}

void TransactionAPI::updateDBBudget(double moneyGain) {
    // do db update stuff, use db's api for this
    //pseudocode
    // unparameterized
    //std::string dbString = "UPDATE budget_table SET money = " + std::to_string(moneyGain);
    // perform query
    // add where statement if necessary

    // for local testing:
    budget += moneyGain;
}



double TransactionAPI::getBudget()
{
    // return budget from db query
    //pseudocode
    //std::string dbString = "SELECT money FROM budget_table";
    // get query return information
    // return money
    
    // for local testing:
    return budget;
}

bool TransactionAPI::validateTransaction(double moneyGain) {
    if (moneyGain >= 0) {
        updateDBBudget(moneyGain);
        return true;
    }
    
    // moneyGain is negative, so add to subtract from budget
    if ((getBudget() + moneyGain) < 0) {
        return false;
    }
    updateDBBudget(moneyGain);
    return true;
}

std::string TransactionAPI::generateTransaction(double moneyGain, std::string details, std::string transactionInitiatingTeam) {
    Transaction t(moneyGain, details, transactionInitiatingTeam);
    // validate transaction with budget
    if (validateTransaction(moneyGain) == false) {
        return "Invalid";
    }
    addDBTransaction(t);
    std::string response;
    response = "Transaction created:\nAmount: " + std::to_string(moneyGain) 
        + "\nDetails: " + details 
        + "\nTeam: " + transactionInitiatingTeam + "\n";
    return response;
}
