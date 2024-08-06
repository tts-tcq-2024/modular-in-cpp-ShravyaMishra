#include "COLORCODER.h"
namespace COLORCODER {
    const char* MajorColorNames[] = { "White", "Red", "Black", "Yellow", "Violet" };
    const char* MinorColorNames[] = { "Blue", "Orange", "Green", "Brown", "Slate" };
    const int numberOfMajorColors = sizeof(MajorColorNames) / sizeof(MajorColorNames[0]);
    const int numberOfMinorColors = sizeof(MinorColorNames) / sizeof(MinorColorNames[0]);
   ColorPair::ColorPair(MajorColor major, MinorColor minor)
        : majorColor(major), minorColor(minor) {}

    MajorColor ColorPair::getMajor() const { return majorColor; }

    MinorColor ColorPair::getMinor() const { return minorColor; }

    std::string ColorPair::ToString() const {
        return std::string(MajorColorNames[majorColor]) + " " + MinorColorNames[minorColor];
    }
    ColorPair GetColorFromPairNumber(int pairNumber) {
        int zeroBasedPairNumber = pairNumber - 1;
        return ColorPair(static_cast<MajorColor>(zeroBasedPairNumber / numberOfMinorColors),
                         static_cast<MinorColor>(zeroBasedPairNumber % numberOfMinorColors));
    }
    int GetPairNumberFromColor(MajorColor major, MinorColor minor) {
        return major * numberOfMinorColors + minor + 1;
    }
    std::string ColorPairToString(int pairNumber) {
        return GetColorFromPairNumber(pairNumber).ToString();
    }
    void testNumberToPair(int pairNumber, MajorColor expectedMajor, MinorColor expectedMinor) {
        ColorPair colorPair = GetColorFromPairNumber(pairNumber);
        std::cout << "Got pair " << colorPair.ToString() << std::endl;
        assert(colorPair.getMajor() == expectedMajor);
        assert(colorPair.getMinor() == expectedMinor);
    }
    void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber) {
        int pairNumber = GetPairNumberFromColor(major, minor);
        std::cout << "Got pair number " << pairNumber << std::endl;
        assert(pairNumber == expectedPairNumber);
    }
    void printColorCodingReference() {
        std::cout << "Color Coding Reference Manual:" << std::endl;
        for (int i = 1; i <= numberOfMajorColors * numberOfMinorColors; ++i) {
            std::cout << i << ": " << ColorPairToString(i) << std::endl;
        }
    }
}
