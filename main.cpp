// main.cpp

#include <iostream>
#include <cassert>
#include "COLORCODE.h"

void testNumberToPair(int pairNumber, TelCoColorCoder::MajorColor expectedMajor, TelCoColorCoder::MinorColor expectedMinor) {
    TelCoColorCoder::ColorPair colorPair = TelCoColorCoder::GetColorFromPairNumber(pairNumber);
    std::cout << "Got pair " << colorPair.ToString() << std::endl;
    assert(colorPair.getMajor() == expectedMajor);
    assert(colorPair.getMinor() == expectedMinor);
}

void testPairToNumber(TelCoColorCoder::MajorColor major, TelCoColorCoder::MinorColor minor, int expectedPairNumber) {
    int pairNumber = TelCoColorCoder::GetPairNumberFromColor(major, minor);
    std::cout << "Got pair number " << pairNumber << std::endl;
    assert(pairNumber == expectedPairNumber);
}

int main() {
    // Testing number to color pair
    testNumberToPair(4, TelCoColorCoder::BLACK, TelCoColorCoder::BROWN);
    testNumberToPair(5, TelCoColorCoder::WHITE, TelCoColorCoder::SLATE);

    // Testing color pair to number
    testPairToNumber(TelCoColorCoder::BLACK, TelCoColorCoder::ORANGE, 12);
    testPairToNumber(TelCoColorCoder::VIOLET, TelCoColorCoder::SLATE, 25);

    // Print the color coding reference table
    TelCoColorCoder::printColorCodingReference();

    // Print color descriptions
    TelCoColorCoder::printColorDescriptions();

    // Print all color pairs
    TelCoColorCoder::printAllColorPairs();

    // Check if a color pair is valid
    std::cout << "Is (RED, BLUE) a valid color pair? " 
              << (TelCoColorCoder::isValidColorPair(TelCoColorCoder::RED, TelCoColorCoder::BLUE) ? "Yes" : "No") 
              << std::endl;

    // Find a color pair from description
    try {
        TelCoColorCoder::ColorPair pair = TelCoColorCoder::findColorPairFromDescription("Red Blue");
        std::cout << "Found color pair: " << pair.ToString() << std::endl;
    } catch (const std::invalid_argument& e) {
       
