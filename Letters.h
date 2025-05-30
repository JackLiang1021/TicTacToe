#ifndef LETTERS_H
#define LETTERS_H

#include <array>
#include <string>
#include <vector>

class Letters {
public:
    std::vector<std::string> getLetter(char letter);
private:
    std::array<std::string, 4> letterX = {
        "   \\  /   ",
        "    \\/    ",
        "    /\\    ",
        "   /  \\   "
    };

    std::array<std::string, 4> letterO = {
        "   /--\\   ",
        "  |    |  ",
        "  |    |  ",
        "   \\__/   "
    };
    std::array<std::string, 4> letterEmpty = {
        "          ",
        "          ",
        "          ",
        "          "
    };
};

#endif // LETTERS_H
