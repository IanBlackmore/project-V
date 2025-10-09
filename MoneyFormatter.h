#pragma once
#include <iostream>
class MoneyFormatter {
	static const int twoDecimalCorrection = 100;
public:
	static std::string formatMoney(double value);
};