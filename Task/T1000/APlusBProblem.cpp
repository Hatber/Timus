#include "APlusBProblem.hpp"

using namespace task1000;

APlusBProblem::APlusBProblem(std::istream& input, std::ostream& output) :
    ATask(input, output) { }


void APlusBProblem::Input() {
    _input >> a >> b;
}

void APlusBProblem::Output() {
    _output << result;
}


void APlusBProblem::Logic() {
    result = a + b;
}
