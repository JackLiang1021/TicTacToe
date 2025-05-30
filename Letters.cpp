#include "Letters.h"

std::vector<std::string> Letters::getLetter(char letter) {
    if (letter == 'x') {
        return {letterX.begin(), letterX.end()};
    }
    if (letter == 'e') {
        return {letterEmpty.begin(), letterEmpty.end()};
    }
    return {letterO.begin(), letterO.end()};
}
