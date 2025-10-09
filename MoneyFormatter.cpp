#include <iostream>
#include "MoneyFormatter.h"
#include <cmath>
#include <string>
std::string MoneyFormatter::formatMoney(double value) {
    // money formatting
    char buffer[50];
    double roundedDouble = std::round(value * twoDecimalCorrection) / twoDecimalCorrection;
    sprintf(buffer, "%.2f", value);
    return std::string(buffer);	
}