#include "Word.hpp"

#include <algorithm>

using namespace task1002;


Word::Word(const std::string &word) : _word(word), _digit(wordToDigit(word)) { }

const std::string& Word::getDigit() const { return _digit; }
const std::string& Word::getWord()  const { return _word; }

bool Word::lexicographicalCompare(const Word& lhs, const Word& rhs) {
    return std::lexicographical_compare(
                lhs.getDigit().begin(), lhs.getDigit().end(),
                rhs.getDigit().begin(), rhs.getDigit().end()
           );
}

std::string Word::wordToDigit(const std::string& word) {
    size_t wordSize = word.size();

    std::string digit;
    digit.resize(wordSize);

    for(size_t i = 0; i<wordSize; i++) {
        digit[i] = letterToNumber(tolower(word[i]));
    }

    return digit;
}

char Word::letterToNumber(char letter) {
    switch (letter) {
        case 'i' : case 'j' :            return '1';
        case 'a' : case 'b' : case 'c' : return '2';
        case 'd' : case 'e' : case 'f' : return '3';
        case 'g' : case 'h' :            return '4';
        case 'k' : case 'l' :            return '5';
        case 'm' : case 'n' :            return '6';
        case 'p' : case 'r' : case 's' : return '7';
        case 't' : case 'u' : case 'v' : return '8';
        case 'w' : case 'x' : case 'y' : return '9';
        case 'o' : case 'q' : case 'z' : return '0';

        default: return '?';
    }
}
