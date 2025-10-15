#pragma once
#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <thread>





class Transaction {
	std::string details;
	double moneyGain;
	std::string timestamp;
	// ideally, this will be handled by an auto increment in the db
	unsigned long id;
	// contains the team that initiated the transaction
	std::string transactionInitiatingTeam;
public:
	Transaction();
	Transaction(double moneyGain, std::string details);
	Transaction(double moneyGain, std::string details, std::string timestamp, unsigned long id);
	double getMoneyGain();
	std::string getDetails();
	std::string getTimestamp();
	unsigned long getID();
};


