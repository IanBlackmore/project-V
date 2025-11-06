#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <chrono>
#include <thread>
#include "Transaction.h"
#include "TransactionReporter.h"
#include "MoneyFormatter.h"

void TransactionReporter::addTransaction(Transaction t)
{
    transactionList.push_back(t);
}

std::vector<Transaction> TransactionReporter::dbDriver()
{
    std::vector<Transaction> temp;
    temp.push_back(Transaction(2.33, "+2.33 dollars", "team 1"));
    std::this_thread::sleep_for(std::chrono::seconds(1));
    temp.push_back(Transaction(3, "+3 dollars", "team 3"));
    temp.push_back(Transaction(1, "+1 dollars", "team 6"));
    std::this_thread::sleep_for(std::chrono::seconds(1));
    temp.push_back(Transaction(-2.33, "-2.33 dollars", "team 1"));
    temp.push_back(Transaction(-4, "-4 dollars", "team 5"));
    std::this_thread::sleep_for(std::chrono::seconds(1));
    temp.push_back(Transaction(-3, "-3 dollars", "team 2"));
    std::this_thread::sleep_for(std::chrono::seconds(3));
    temp.push_back(Transaction(17.5, "+17.5 dollars", "team 3"));
    return temp;
}

std::string TransactionReporter::generateReport()
{
    if (transactionList.size() == 0) {
        return "No transactions recorded";
    }
    std::string s = "";
    // pull information from database, simulated by dbDriver. Maybe add dbHandler?
    transactionList = this->dbDriver();
    std::vector<Transaction> revenueList;
    std::vector<Transaction> costList;
    double totalCost = 0;
    double totalRevenue = 0;
    for (int i = 0; i < transactionList.size(); i++)
    {
        if (transactionList[i].getMoneyGain() < 0)
        {
            costList.push_back(transactionList[i]);
            totalCost += transactionList[i].getMoneyGain();
        }
        else
        {
            // 0 cost transaction will be considered a positive transaction
            revenueList.push_back(transactionList[i]);
            totalRevenue += transactionList[i].getMoneyGain();
        }
    }
    s += "---------------------------------------------------\n";
    s += "                    REVENUE                        \n";
    s += "---------------------------------------------------\n";
    for (int i = 0; i < revenueList.size(); i++)
    {
        s += revenueList[i].getDetails() + "\n";
        // const keeps dollar value at 2 decimals. rename later

        s += "Profit: " + MoneyFormatter::formatMoney(revenueList[i].getMoneyGain()) + "\n";
        s += "At " + revenueList[i].getTimestamp();
        s += "From team: " + revenueList[i].getTransactionInitiatingTeam() + "\n";
        s += "Transaction ID: " + std::to_string(revenueList[i].getID()) + "\n";
        s += "\n";
    }
    if (revenueList.size() == 0)
    {
        s += "No revenue in this report";
    }
    s += "\n";
    s += "---------------------------------------------------\n";
    s += "                      COST                         \n";
    s += "---------------------------------------------------\n";
    for (int i = 0; i < costList.size(); i++)
    {
        s += costList[i].getDetails() + "\n";
        // const keeps dollar value at 2 decimals. rename later
        s += "Cost: " + MoneyFormatter::formatMoney(costList[i].getMoneyGain()) + "\n";
        s += "At " + costList[i].getTimestamp();
        s += "From team: " + costList[i].getTransactionInitiatingTeam() + "\n";
        s += "Transaction ID: " + std::to_string(costList[i].getID()) + "\n";
        s += "\n";
    }
    if (costList.size() == 0)
    {
        s += "No costs in this report";
    }
    s += "---------------------------------------------------\n";
    s += "                     TOTAL                         \n";
    s += "---------------------------------------------------\n";
    s += MoneyFormatter::formatMoney(totalRevenue + totalCost) + "\n";

    return s;
}
