#ifndef __T1002_NUMBER_HPP__
#define __T1002_NUMBER_HPP__

#include "Word.hpp"

#include <string>
#include <vector>

namespace toj {
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
            const std::vector< int >& wordIndex,
            const std::vector< int >& sequenceCost
    );

    std::string _number;
    std::vector< Word > _dictionary;
};

}} //toj::task
#endif // __T1002_NUMBER_HPP__
