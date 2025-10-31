#include <iostream>
#include "MoneyFormatter.h"
#include <cmath>
#include <string>
std::string MoneyFormatter::formatMoney(double value) {
    // money formatting
    char buffer[50];
    double roundedDouble = 0;
    if(value < 0) {
        roundedDouble = std::round(-1 * value * twoDecimalCorrection) / twoDecimalCorrection;
    }
    else {
        roundedDouble = std::round(value * twoDecimalCorrection) / twoDecimalCorrection;
    }
    sprintf(buffer, "%.2f", roundedDouble);
    std::string result(buffer);
    result = "$" + result;
    if(value < 0) {
        result = "-" + result;
    }
    return result;	
}