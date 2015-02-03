#include "Word.hpp"

#include <algorithm>

using namespace toj::task1002;


Word::Word(const std::string &word) : _word(word), _diget(wordToDiget(word)) { }

const std::string& Word::getDigit() const { return _diget; }
const std::string& Word::getWord()  const { return _word; }

bool Word::lexicographicalCompare(const Word& lhs, const Word& rhs) {
    return std::lexicographical_compare(
                lhs.getDigit().begin(), lhs.getDigit().end(),
                rhs.getDigit().begin(), rhs.getDigit().end()
           );
}

std::string Word::wordToDiget(const std::string& word) {
    size_t wordSize = word.size();

    std::string diget;
    diget.resize(wordSize);

    for(size_t i = 0; i<wordSize; i++) {
        diget[i] = letterToNumber(tolower(word[i]));
    }

    return diget;
}

char Word::letterToNumber(char letter) {
    switch (letter) {
        case 'i' : case 'j' :            return '1'; break;
        case 'a' : case 'b' : case 'c' : return '2'; break;
        case 'd' : case 'e' : case 'f' : return '3'; break;
        case 'g' : case 'h' :            return '4'; break;
        case 'k' : case 'l' :            return '5'; break;
        case 'm' : case 'n' :            return '6'; break;
        case 'p' : case 'r' : case 's' : return '7'; break;
        case 't' : case 'u' : case 'v' : return '8'; break;
        case 'w' : case 'x' : case 'y' : return '9'; break;
        case 'o' : case 'q' : case 'z' : return '0'; break;

        default: return '?'; break;
    }
}
