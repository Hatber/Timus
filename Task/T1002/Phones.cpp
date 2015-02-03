#include "Phones.h"

#include <string>

using namespace toj::task1002;


Phones::Phones(std::istream& input, std::ostream& output) :
    ATask(input, output) { }


void Phones::Input() {
    std::string number;
    std::string word;
    int dictionarySize;

    while(true) {
        _input >> number;
        if(number.compare("-1") == 0) {
            return;
        }

        _input >> dictionarySize;

        Number n(number, dictionarySize);
        for(int i = 0; i < dictionarySize; i++) {
            _input >> word;
            n.addToDictionary(word);
        }

        _numbers.push_back(n);
    }
}

void Phones::Output() {
    size_t answerCount = _answer.size();

    for(size_t i = 0; i < answerCount; i++) {
        _output << _answer[i] << std::endl;
    }
}



void Phones::Logic() {
    size_t numberCount = _numbers.size();
    _answer.resize(numberCount);

    for(size_t i = 0; i <numberCount; i++) {
        std::vector< size_t > seq = _numbers[i].findSequence();
        if(seq.size() == 0) {
            _answer[i] = "No solution.";
        } else {
            for(std::vector< size_t >::iterator it = seq.begin(); it != seq.end(); it++) {
                _answer[i] += _numbers[i].getWordByIndex(*it) + ' ';
            }
        }
    }

}
