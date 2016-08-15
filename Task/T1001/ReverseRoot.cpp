#include "ReverseRoot.hpp"

#include <iomanip>
#include <cmath>

using namespace task1001;

ReverseRoot::ReverseRoot(std::istream& input, std::ostream& output) :
    ATask(input, output) { }


void ReverseRoot::Input() {
    unsigned long long input = 0;

    while(_input >> input) {
        sqrtNumbers.push_back(input);
    }
}

void ReverseRoot::Output() {
    size_t inCount = sqrtNumbers.size();
    for(size_t i = 0; i < inCount; i++) {
        _output.setf(std::ios::fixed, std::ios::floatfield);
        _output << std::fixed << std::setprecision(4) << sqrtNumbers[inCount - 1 - i] << std::endl;
    }
}


void ReverseRoot::Logic() {
    size_t inCount = sqrtNumbers.size();
    for(size_t i = 0; i < inCount; i++) {
        sqrtNumbers[i] = std::sqrt(sqrtNumbers[i]);
    }
}
