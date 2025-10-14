#pragma once
#include <vector>
#include <iostream>
#include "Transaction.h"

class TransactionReporter {
	std::vector<Transaction> transactionList;
	std::vector<Transaction> dbDriver();
public:
	void addTransaction(Transaction t);
	std::string generateReport(bool HTMLFriendly=false);
	
};