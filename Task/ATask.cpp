#include "ATask.hpp"

using namespace toj::task;

ATask::ATask(std::istream &input, std::ostream &output) :
    _input(input), _output(output) { }

ATask::~ATask() { }

void ATask::Solve() {
    Input();
    Logic();
    Output();
}
