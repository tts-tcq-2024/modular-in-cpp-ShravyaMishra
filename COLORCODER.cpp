// COLORCODE.cpp

#include "COLORCODE.h"
#include <iostream>
#include <cassert>
#include <sstream>
#include <stdexcept>

namespace TelCoColorCoder 
{
    const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
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

    const int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    const int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);

    ColorPair::ColorPair(MajorColor major, MinorColor minor)
        : majorColor(major), minorColor(minor) {}

    MajorColor ColorPair::getMajor() const {
        return majorColor;
    }

    MinorColor ColorPair::getMinor() const {
        return minorColor;
    }

    std::string ColorPair::ToString() const {
        return std::string(MajorColorNames[majorColor]) + " " + MinorColorNames[minorColor];
    }

    ColorPair GetColorFromPairNumber(int pairNumber) {
        if (pairNumber < 1 || pairNumber > numberOfMajorColors * numberOfMinorColors) {
            throw std::out_of_range("Pair number out of range");
        }
        int zeroBasedPairNumber = pairNumber - 1;
        MajorColor majorColor = static_cast<MajorColor>(zeroBasedPairNumber / numberOfMinorColors);
        MinorColor minorColor = static_cast<MinorColor>(zeroBasedPairNumber % numberOfMinorColors);
        return ColorPair(majorColor, minorColor);
    }

    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        if (major < 0 || major >= numberOfMajorColors || minor < 0 || minor >= numberOfMinorColors) {
            throw std::out_of_range("Invalid color");
        }
        return major * numberOfMinorColors + minor + 1;
    }

    void printColorCodingReference() {
        std::cout << "Color Coding Reference Table:\n";
        for (int i = 0; i < numberOfMajorColors; ++i) {
            for (int j = 0; j < numberOfMinorColors; ++j) {
                ColorPair colorPair(static_cast<MajorColor>(i), static_cast<MinorColor>(j));
                std::cout << GetPairNumberFromColor(colorPair.getMajor(), colorPair.getMinor()) 
                          << ": " << colorPair.ToString() << "\n";
            }
        }
    }

    void printColorDescriptions() {
        std::cout << "Color Descriptions:\n";
        for (int i = 0; i < numberOfMajorColors; ++i) {
            std::cout << MajorColorNames[i] << ": " << ColorDescriptions[i] << "\n";
        }
        for (int i = 0; i < numberOfMinorColors; ++i) {
            std::cout << MinorColorNames[i] << ": " << ColorDescriptions[numberOfMajorColors + i] << "\n";
        }
    }

    void printAllColorPairs() {
        std::cout << "All Color Pairs:\n";
        for (int i = 0; i < numberOfMajorColors; ++i) {
            for (int j = 0; j < numberOfMinorColors; ++j) {
                ColorPair colorPair(static_cast<MajorColor>(i), static_cast<MinorColor>(j));
                std::cout << GetPairNumberFromColor(colorPair.getMajor(), colorPair.getMinor()) 
                          << ": " << colorPair.ToString() << "\n";
            }
        }
    }

    bool isValidColorPair(MajorColor major, MinorColor minor) {
        return major >= 0 && major < numberOfMajorColors && minor >= 0 && minor < numberOfMinorColors;
    }

    ColorPair findColorPairFromDescription(const std::string& description) {
        for (int i = 0; i < numberOfMajorColors; ++i) {
            if (description.find(MajorColorNames[i]) != std::string::npos) {
                for (int j = 0; j < numberOfMinorColors; ++j) {
                    if (description.find(MinorColorNames[j]) != std::string::npos) {
                        return ColorPair(static_cast<MajorColor>(i), static_cast<MinorColor>(j));
                    }
                }
            }
        }
        throw std::invalid_argument("Description does not match any color pair.");
    }
}
