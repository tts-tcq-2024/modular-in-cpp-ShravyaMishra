// TelCoColorCoder.h

#ifndef TELCOCOLORCODER_H
#define TELCOCOLORCODER_H

#include <string>
#include <stdexcept>

namespace TelCoColorCoder 
{
    enum MajorColor { WHITE, RED, BLACK, YELLOW, VIOLET };
    enum MinorColor { BLUE, ORANGE, GREEN, BROWN, SLATE };

    extern const char* MajorColorNames[];
    extern const char* MinorColorNames[];
    extern const char* ColorDescriptions[];
    extern const int numberOfMajorColors;
    extern const int numberOfMinorColors;

    class ColorPair {
    private:
        MajorColor majorColor;
        MinorColor minorColor;
    public:
        ColorPair(MajorColor major, MinorColor minor);
        MajorColor getMajor() const;
        MinorColor getMinor() const;
        std::string ToString() const;
    };

    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(MajorColor major, MinorColor minor);
    void printColorCodingReference();
    void printColorDescriptions();
    void printAllColorPairs();
    bool isValidColorPair(MajorColor major, MinorColor minor);
    ColorPair findColorPairFromDescription(const std::string& description);
}

#endif // TELCOCOLORCODER_H
