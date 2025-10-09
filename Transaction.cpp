#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <ctime>
#include "Transaction.h"

Transaction::Transaction() {
    details = "";
    moneyGain = 0;
    timestamp = "";
    id = 0;
}
Transaction::Transaction(double moneyGain, std::string details) {
    this->details = details;
    this->moneyGain = moneyGain;
    std::time_t result = std::time(nullptr);
    timestamp = std::ctime(&result);
    id = 0;
}
Transaction::Transaction(double moneyGain, std::string details, std::string timestamp, unsigned long id) {
    this->details = details;
    this->moneyGain = moneyGain;
    this->timestamp = timestamp;
    this->id = id;
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
unsigned long Transaction::getID() {
    return id;
}

