#ifndef COLORCODER_H_
#define COLORCODER_H_

#include <iostream>
#include <cassert>

namespace COLORCODER {

    enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
    enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

    extern const char* MajorColorNames[];
    extern const char* MinorColorNames[];

    class ColorPair {
    public:
        ColorPair(MajorColor major, MinorColor minor);
        MajorColor getMajor() const;
        MinorColor getMinor() const;
        std::string ToString() const;
    private:
        MajorColor majorColor;
        MinorColor minorColor;
    };

    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    std::string ColorPairToString(int pairNumber);
    void testNumberToPair(int pairNumber, MajorColor expectedMajor, MinorColor expectedMinor);
    void testPairToNumber(MajorColor major, MinorColor minor, int expectedPairNumber);
    void printColorCodingReference();

}

#endif /* COLORCODER_H_ */
