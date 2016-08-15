#include "Number.hpp"

#include <algorithm>

using namespace task1002;


Number::Number(const std::string& number, std::size_t dictionarySize) : _number(number) {
    _dictionary.reserve(dictionarySize);
}

void Number::addToDictionary(const std::string& _word) {
    _dictionary.push_back(Word(_word));
}

std::string Number::getWordByIndex(int index) {
    return _dictionary[index].getWord();
}

std::vector< size_t > Number::findSequence() {
    size_t numberSize = _number.size();

    std::vector< size_t > wordIndex(numberSize, (size_t)-1);
    std::vector< size_t > sequenceCost(numberSize, (size_t)-1);

    size_t dictionarySize = _dictionary.size();

    for(size_t i = 0; i< dictionarySize; i++) {
        if(isMatching(_dictionary[i].getDigit(), 0)) {
            wordIndex[_dictionary[i].getDigit().size()-1] = i;
            sequenceCost[_dictionary[i].getDigit().size()-1] = 1;
        }
    }

    if(sequenceCost.back() != -1 || std::find(sequenceCost.begin(), sequenceCost.end(), 1) == sequenceCost.end()) {
        return makeSequence(wordIndex, sequenceCost);
    }

    size_t currentNumberIndex = 1;
    bool isSolution = false;
    while (!isSolution) {
        isSolution = true;

        for(size_t sequenceCostIt = 0; sequenceCostIt < numberSize; sequenceCostIt++) {
            if(sequenceCost[sequenceCostIt] == currentNumberIndex) {
                isSolution = false;

                for(size_t i = 0; i< dictionarySize; i++) {

                    if(isMatching(_dictionary[i].getDigit(), sequenceCostIt + 1) &&
                       sequenceCost[_dictionary[i].getDigit().size()-1 + sequenceCostIt + 1] == -1
                      ) {
                        wordIndex[_dictionary[i].getDigit().size()-1 + sequenceCostIt + 1] = i;
                        sequenceCost[_dictionary[i].getDigit().size()-1 + sequenceCostIt + 1] = currentNumberIndex + 1;
                    }

                }
            }

            if(sequenceCost.back() != -1) {
                return makeSequence(wordIndex, sequenceCost);
            }
        }

        currentNumberIndex++;
    }

    return std::vector< size_t >();
}

bool Number::isMatching(const std::string& word, int position) {
    size_t wordSize = word.size();

    if(wordSize > _number.size() - position) {
        return false;
    }

    for(size_t i = 0; i < wordSize; i++) {
        if(word[i] != _number[position + i]) {
            return false;
        }
    }

    return true;
}

std::vector< size_t > Number::makeSequence(
        const std::vector< size_t >& wordIndex,
        const std::vector< size_t >& sequenceCost
) {
    std::vector< size_t > wordIndexSequence;
    size_t wordIndexPosition = wordIndex.size() - 1;

    for(int seqSize = sequenceCost.back(); seqSize > 0; seqSize--) {
        wordIndexSequence.push_back(wordIndex[wordIndexPosition]);
        wordIndexPosition -= _dictionary[wordIndex[wordIndexPosition]].getDigit().size();
    }

    reverse(wordIndexSequence.begin(), wordIndexSequence.end());
    return wordIndexSequence;
}
