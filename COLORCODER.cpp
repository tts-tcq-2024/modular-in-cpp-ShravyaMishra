// TelCoColorCoder.cpp

#include "TelCoColorCoder.h"
#include <iostream>
#include <cassert>

namespace TelCoColorCoder 
{
    const char* ColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet",
        "Blue", "Orange", "Green", "Brown", "Slate"
    };

    const char* ColorDescriptions[] = {
        "A neutral color, often associated with purity.",
        "A warm color, often associated with passion.",
        "A dark color, often associated with power.",
        "A bright color, often associated with sunshine.",
        "A color often associated with royalty.",
        "A cool color, often associated with the sky.",
        "A vibrant color, often associated with enthusiasm.",
        "A color representing nature and growth.",
        "A warm, earthy color.",
        "A dark color, often associated with stones."
    };

    int numberOfColors = sizeof(ColorNames) / sizeof(ColorNames[0]);

    ColorPair::ColorPair(Color color)
        : color(color) {}

    Color ColorPair::getColor() {
        return color;
    }

    std::string ColorPair::ToString() {
        return ColorNames[color];
    }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        if (zeroBasedPairNumber >= 0 && zeroBasedPairNumber < numberOfColors) {
            return ColorPair((Color)zeroBasedPairNumber);
        }
        throw std::out_of_range("Invalid pair number");
    }

    int GetPairNumberFromColor(Color color) {
        if (color >= 0 && color < numberOfColors) {
            return color + 1;
        }
        throw std::out_of_range("Invalid color");
    }

    void printColorCodingReference() {
        std::cout << "Color Coding Reference Table:\n";
        for (int i = 0; i < numberOfColors; ++i) {
            std::cout << GetPairNumberFromColor((Color)i) << ": " << ColorNames[i] << "\n";
        }
    }

    void printColorDescriptions() {
        std::cout << "Color Descriptions:\n";
        for (int i = 0; i < numberOfColors; ++i) {
            std::cout << ColorNames[i] << ": " << ColorDescriptions[i] << "\n";
        }
    }

    void testNumberToPair(int pairNumber, Color expectedColor) {
        ColorPair colorPair = GetColorFromPairNumber(pairNumber);
        std::cout << "Got pair " << colorPair.ToString() << std::endl;
        assert(colorPair.getColor() == expectedColor);
    }

    void testPairToNumber(Color color, int expectedPairNumber) {
        int pairNumber = GetPairNumberFromColor(color);
        std::cout << "Got pair number " << pairNumber << std::endl;
        assert(pairNumber == expectedPairNumber);
    }
}
