#pragma once
#include <iostream>
#include "Transaction.h"
/// @brief an API for other teams to interface with the Transaction team modules
class TransactionAPI {
	/// @brief sends a transaction record to the database
	/// @param t the transaction to be sent to the database
	void updateDatabase(Transaction t);
public:
	/// @brief API for other teams to use. Generates a transaction and uploads it to the database
	/// @param moneyGain money gained or lsot
	/// @param details details of the transaction
	/// @param transactionInitiatingTeam team that initiated the transaction
	void generateTransaction(double moneyGain, std::string details, std::string transactionInitiatingTeam);
};
