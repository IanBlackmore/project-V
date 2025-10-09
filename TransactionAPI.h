#pragma once
#include <iostream>
#include "Transaction.h"
class TransactionAPI {
	// now that i think about it, likely unnecessary if we get a good api from db team
	std::string dbString;
	void updateDatabase(Transaction t);
public:
	void generateTransaction(double moneyGain, std::string details);
};
