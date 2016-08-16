#include "Parity.hpp"

#include "Sequence.hpp"

using namespace task1003;

Parity::Parity(std::istream& input, std::ostream& output) :
    ATask(input, output) { }

void Parity::Input() {
    int sequenceSize;
    int questionSize;

    int start;
    int end;
    std::string parity;

    while(true) {
        std::vector< Interval > intervals;

        _input >> sequenceSize;
        if(sequenceSize == -1) {
            return;
        }

        _input >> questionSize;

        for(int i = 0; i<questionSize; i++) {
            _input >> start >> end >> parity;
            intervals.push_back(Interval(start, end, makeParityFromString(parity)));
        }

        testsData.push_back(intervals);
    }
}

void Parity::Output() {
    std::size_t answerCount = answers.size();
    for(int i = 0; i < answerCount; i++) {
        _output << answers[i] << std::endl;
    }
}

void Parity::Logic() {
    std::size_t testCount = testsData.size();
    for(std::size_t i = 0; i < testCount; i++) {
        std::size_t intervalCount = testsData[i].size();
        Sequence seq;
        for(std::size_t j = 0; j < intervalCount; j++) {
            if(!seq.addInterval(testsData[i][j])) {
                answers.push_back((int)j);
                break;
            } else if(j == intervalCount-1) {
                answers.push_back((int)intervalCount);
            }
        }
    }
}

ParityE Parity::makeParityFromString(const std::string& p) {
    if(p.compare("odd") == 0) { return ODD; }
    return EVEN;
}
