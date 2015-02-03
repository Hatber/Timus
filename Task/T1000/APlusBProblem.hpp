#ifndef __T1000_APLUSBPROBLEM_HPP__
#define __T1000_APLUSBPROBLEM_HPP__

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
#endif // __T1000_APLUSBPROBLEM_HPP__
