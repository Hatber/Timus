#ifndef APLUSBPROBLEM_HPP
#define APLUSBPROBLEM_HPP

#include "../ATask.hpp"

namespace toj {
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

}} //toj::task1000
#endif // APLUSBPROBLEM_HPP
