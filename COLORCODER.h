// TelCoColorCoder.h

#ifndef TELCOCOLORCODER_H
#define TELCOCOLORCODER_H

#include <string>

namespace TelCoColorCoder 
{
    enum Color { WHITE, RED, BLACK, YELLOW, VIOLET, BLUE, ORANGE, GREEN, BROWN, SLATE };

    extern const char* ColorNames[];
    extern const char* ColorDescriptions[];
    extern int numberOfColors;

    class ColorPair {
    private:
        Color color;
    public:
        ColorPair(Color color);
        Color getColor();
        std::string ToString();
    };

    ColorPair GetColorFromPairNumber(int pairNumber);
    int GetPairNumberFromColor(Color color);
    void printColorCodingReference();
    void printColorDescriptions();
    void testNumberToPair(int pairNumber, Color expectedColor);
    void testPairToNumber(Color color, int expectedPairNumber);
}

#endif // TELCOCOLORCODER_H
