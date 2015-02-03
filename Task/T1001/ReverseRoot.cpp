#include "ReverseRoot.hpp"

#include <iomanip>
#include <cmath>

using namespace toj::task1001;

ReverseRoot::ReverseRoot(std::istream& input, std::ostream& output) :
    ATask(input, output) { }


void ReverseRoot::Input() {
    unsigned long long input = 0;

    while(_input >> input) {
        sqrtNumbers.push_back(input);
    }
}

void ReverseRoot::Output() {
    std::size_t inCount = sqrtNumbers.size();
    for(int i = inCount-1; i>=0; i--) {
        _output.setf(std::ios::fixed, std::ios::floatfield);
        _output << std::fixed << std::setprecision(4) << sqrtNumbers[i] << std::endl;
    }
}


void ReverseRoot::Logic() {
    int inCount = sqrtNumbers.size();
    for(int i = 0; i<inCount; i++) {
        sqrtNumbers[i] = std::sqrt(sqrtNumbers[i]);
    }
}
