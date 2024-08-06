// TelCoColorCoder.h

#ifndef TELCOCOLORCODER_H
#define TELCOCOLORCODER_H

#include <string>

namespace TelCoColorCoder 
{
    enum Color { WHITE, RED, BLACK, YELLOW, VIOLET, BLUE, ORANGE, GREEN, BROWN, SLATE };

    extern const char* ColorNames[];
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
}

#endif // TELCOCOLORCODER_H
