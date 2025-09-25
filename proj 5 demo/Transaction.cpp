#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>
#include <string>
#include <thread>


class MoneyFormatter {
	static const int twoDecimalCorrection = 100;
public:
	static std::string formatMoney(double value) {
		// money formatting
		char buffer[50];
		double roundedDouble = std::round(value * twoDecimalCorrection) / twoDecimalCorrection;
		sprintf(buffer, "%.2f", value);
		return std::string(buffer);

	}
};


class Transaction {
	std::string details;
	double moneyGain;
	std::string timestamp;
	// ideally, this will be handled by an auto increment in the db
	unsigned long id;
public:
	Transaction() {
		details = "";
		moneyGain = 0;
		timestamp = "";
		id = 0;
	}
	Transaction(double moneyGain, std::string details) {
		this->details = details;
		this->moneyGain = moneyGain;
		std::time_t result = std::time(nullptr);
		timestamp = std::ctime(&result);
		id = 0;
	}
	Transaction(double moneyGain, std::string details, std::string timestamp, unsigned long id) {
		this->details = details;
		this->moneyGain = moneyGain;
		this->timestamp = timestamp;
		this->id = id;
	}
	double getMoneyGain() {
		return moneyGain;
	}
	std::string getDetails() {
		return details;
	}
	std::string getTimestamp() {
		return timestamp;
	}
	unsigned long getID() {
		return id;
	}
};

class TransactionAPI {
	// now that i think about it, likely unnecessary if we get a good api from db team
	std::string dbString;
	void updateDatabase(Transaction t) {
		// do db update stuff, use db's api for this
	}
public:
	void generateTransaction(double moneyGain, std::string details) {
		Transaction t(moneyGain, details);
		updateDatabase(t);
	}
};

class TransactionReporter {
	std::vector<Transaction> transactionList;
public:
	void addTransaction(Transaction t) {
		transactionList.push_back(t);
	}
	std::string generateReport() {
		std::string s = "";
		// pull information from database, simulated by dbDriver. Maybe add dbHandler?
		transactionList = dbDriver();
		s += "---------------------------------------------------\n";
		std::vector<Transaction> revenueList;
		std::vector<Transaction> costList;
		double totalCost = 0;
		double totalRevenue = 0;
		for (int i = 0; i < transactionList.size(); i++) {
			if (transactionList[i].getMoneyGain() < 0) {
				costList.push_back(transactionList[i]);
				totalCost += transactionList[i].getMoneyGain();
			}
			else {
				// 0 cost transaction will be considered a positive transaction
				revenueList.push_back(transactionList[i]);
				totalRevenue += transactionList[i].getMoneyGain();
			}
		}

		s += "                    REVENUE                        \n";
		s += "---------------------------------------------------\n";
		for (int i = 0; i < revenueList.size(); i++) {
			s += revenueList[i].getDetails() + "\n";
			// const keeps dollar value at 2 decimals. rename later
			

			s += "Profit: $" + MoneyFormatter::formatMoney(revenueList[i].getMoneyGain()) + "\n";
			s += "At " + revenueList[i].getTimestamp();
			s += "Transaction ID: " + std::to_string(revenueList[i].getID()) + "\n";
			s += "\n";
		}
		s += "\n";
		s += "---------------------------------------------------\n";
		s += "                      COST                         \n";
		s += "---------------------------------------------------\n";
		for (int i = 0; i < costList.size(); i++) {
			s += costList[i].getDetails() + "\n";
			// const keeps dollar value at 2 decimals. rename later
			s += "Cost: $" + MoneyFormatter::formatMoney(-1 * costList[i].getMoneyGain()) + "\n";
			s += "At " + costList[i].getTimestamp();
			s += "Transaction ID: " + std::to_string(costList[i].getID()) + "\n";
			s += "\n";
		}
		s += "---------------------------------------------------\n";
		s += "                     TOTAL                         \n";
		s += "---------------------------------------------------\n";
		s += "$" + MoneyFormatter::formatMoney(totalRevenue + totalCost) + "\n";
		return s;
	}
	std::vector<Transaction> dbDriver() {
		std::vector<Transaction> temp;
		temp.push_back(Transaction(2.33, "+2.33 dollars"));
		std::this_thread::sleep_for(std::chrono::seconds(1));
		temp.push_back(Transaction(3, "+3 dollars"));
		temp.push_back(Transaction(1, "+1 dollars")); 
		std::this_thread::sleep_for(std::chrono::seconds(1));
		temp.push_back(Transaction(-2.33, "-2.33 dollars"));
		temp.push_back(Transaction(-4, "-4 dollars"));
		std::this_thread::sleep_for(std::chrono::seconds(1));
		temp.push_back(Transaction(-3, "-3 dollars"));
		std::this_thread::sleep_for(std::chrono::seconds(3));
		temp.push_back(Transaction(17.5, "+17.5 dollars"));
		return temp;
	}
};


int main(void) {
	TransactionReporter t;
	std::cout << t.generateReport();
	return 0;
}