#ifndef __T1000_A_PLUS_B_PROBLEM_HPP__
#define __T1000_A_PLUS_B_PROBLEM_HPP__

#include "../ATask.hpp"

namespace task1000 {

class APlusBProblem : public task::ATask {
public:
    APlusBProblem(std::istream& input, std::ostream& output);

    void Input();
    void Output();

    void Logic();

protected:
    int a, b;
    int result;
};

} //task1000
#endif // __T1000_A_PLUS_B_PROBLEM_HPP__
