#pragma once
#include <iostream>
#include "Transaction.h"
/// @brief an API for other teams to interface with the Transaction team modules
class TransactionAPI {
	/// @brief sends a transaction record to the database
	/// @param t the transaction to be sent to the database
	void addDBTransaction(Transaction t);
	static void updateDBBudget(double moneyGain);

	//TEST VAR
	/// @brief test variable
	static inline double budget = 0;

	/// @brief Validates a transaction to be performed
	/// @param moneyGain Money in or out
	/// @return True if money out is within budget, false if not
	bool validateTransaction(double moneyGain);
public:
	/// @brief Gets the current budget
	/// @return Returns a double of the budget
	static double getBudget();
	/// @brief API for other teams to use. Generates a transaction and uploads it to the database
	/// @param moneyGain money gained or lsot
	/// @param details details of the transaction
	/// @param transactionInitiatingTeam team that initiated the transaction
	std::string generateTransaction(double moneyGain, std::string details, std::string transactionInitiatingTeam);

};
