// main.cpp

#include <iostream>
#include <cassert>
#include "TelCoColorCoder.h"

int main() {
    // Testing number to color pair
    TelCoColorCoder::testNumberToPair(4, TelCoColorCoder::BLACK);
    TelCoColorCoder::testNumberToPair(5, TelCoColorCoder::BLUE);

    // Testing color pair to number
    TelCoColorCoder::testPairToNumber(TelCoColorCoder::ORANGE, 7);
    TelCoColorCoder::testPairToNumber(TelCoColorCoder::SLATE, 10);

    // Print the color coding reference table
    TelCoColorCoder::printColorCodingReference();

    // Print color descriptions
    TelCoColorCoder::printColorDescriptions();

    return 0;
}
