// main.cpp

#include <iostream>
#include <cassert>
#include "TelCoColorCoder.h"

void testNumberToPair(int pairNumber, TelCoColorCoder::Color expectedColor) {
    TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getColor() == expectedColor);
}

void testPairToNumber(TelCoColorCoder::Color color, int expectedPairNumber) {
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(color);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

int main() {
    testNumberToPair(4, TelCoColorCoder::BLACK);
    testNumberToPair(5, TelCoColorCoder::BLUE);

    testPairToNumber(TelCoColorCoder::ORANGE, 7);
    testPairToNumber(TelCoColorCoder::SLATE, 10);

    TelCoColorCoder::printColorCodingReference();

    return 0;
}
