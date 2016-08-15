#ifndef __T1002_WORD_HPP__
#define __T1002_WORD_HPP__

#include <string>

namespace task1002 {

class Word {
public:
    Word(const std::string& word);

    const std::string& getDigit() const;
    const std::string& getWord()  const;

    static bool lexicographicalCompare(const Word& lhs, const Word& rhs);

private:
    std::string wordToDigit(const std::string& word);
    char letterToNumber(char letter);

    std::string _word;
    std::string _digit;
};

} //task1002

#endif // __T1002_WORD_HPP__
