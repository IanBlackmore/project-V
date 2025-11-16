#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <ctime>
#include "Transaction.h"

Transaction::Transaction() {
    details = "";
    moneyGain = 0;
    timestamp = "";
    transactionInitiatingTeam = "";
    id = 0;
}
Transaction::Transaction(double moneyGain, std::string details, std::string transactionInitiatingTeam) {
    this->details = details;
    this->moneyGain = moneyGain;
    std::time_t result = std::time(nullptr);
    timestamp = std::ctime(&result);
    this->transactionInitiatingTeam = transactionInitiatingTeam;
    id = counter;
}
Transaction::Transaction(double moneyGain, std::string details, std::string transactionInitiatingTeam, std::string timestamp, unsigned long id) {
    this->details = details;
    this->moneyGain = moneyGain;
    this->timestamp = timestamp;
    this->id = id;
    this->transactionInitiatingTeam = transactionInitiatingTeam;
}
double Transaction::getMoneyGain() {
    return moneyGain;
}
std::string Transaction::getDetails() {
    return details;
}
std::string Transaction::getTimestamp() {
    return timestamp;
}

std::string Transaction::getTransactionInitiatingTeam() {
    return transactionInitiatingTeam;
}

unsigned long Transaction::getID() {
    return id;
}

