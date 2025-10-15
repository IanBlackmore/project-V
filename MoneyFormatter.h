#pragma once
#include <iostream>
/// @brief for formatting any variables storing money
class MoneyFormatter {
	/// @brief constant for rounding to the nearest hundredth (0.01)
	static const int twoDecimalCorrection = 100;
public:
	/// @brief formats decimals into a money format (like 123.467 to $123.47)
	/// @param value the value to be formatted
	/// @return a string containing a negative if needed, a dollar sign, and value rounded to the nearest hundredth
	static std::string formatMoney(double value);
};