// TelCoColorCoder.cpp

#include "TelCoColorCoder.h"
#include <iostream>

namespace TelCoColorCoder 
{
    const char* ColorNames[] = {
        "White", "Red", "Black", "Yellow", "Violet",
        "Blue", "Orange", "Green", "Brown", "Slate"
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
        return ColorPair((Color)zeroBasedPairNumber);
    }

    int GetPairNumberFromColor(Color color) {
        return color + 1;
    }

    void printColorCodingReference() {
        std::cout << "Color Coding Reference Table:\n";
        for (int i = 0; i < numberOfColors; ++i) {
            std::cout << GetPairNumberFromColor((Color)i) << ": " << ColorNames[i] << "\n";
        }
    }
}
