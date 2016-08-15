#ifndef __T1002_NUMBER_HPP__
#define __T1002_NUMBER_HPP__

#include "Word.hpp"

#include <string>
#include <vector>

namespace task1002 {

class Number {
public:
    Number(const std::string& number, std::size_t dictionarySize);

    void addToDictionary(const std::string& _word);
    std::string getWordByIndex(int index);

    std::vector< size_t > findSequence();

private:
    bool isMatching(const std::string& word, int position);
    std::vector< size_t > makeSequence(
            const std::vector< size_t >& wordIndex,
            const std::vector< size_t >& sequenceCost
    );

    std::string _number;
    std::vector< Word > _dictionary;
};

} //task1002

#endif // __T1002_NUMBER_HPP__
