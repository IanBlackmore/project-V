#pragma once
#include <vector>
#include <iostream>
#include "Transaction.h"
/// @brief class for generating transaction reports
class TransactionReporter {
	/// @brief a list of transactions
	std::vector<Transaction> transactionList;
	/// @brief stub for getting db information. will likely be changed later to "getTransactionData" or something like that
	/// @return returns a vector of transactions
	std::vector<Transaction> dbDriver();
	std::vector<Transaction> getDBTransactions();
public:
	/// @brief adds a transaction to the internal list
	/// @param t the transaction to be added
	void addTransaction(Transaction t);
	/// @brief generates the report in a string to be used in the report.html file
	/// @return returns a string
	std::string generateReport();
	
};