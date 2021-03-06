#ifndef __1003_PARITY_HPP__
#define __1003_PARITY_HPP__

#include "../ATask.hpp"

#include <vector>
#include "Interval.hpp"

namespace task1003 {

class Parity : public task::ATask
{
public:
    Parity(std::istream& input, std::ostream& output);

    void Input();
    void Output();
    void Logic();

private:
    ParityE makeParityFromString(const std::string& p);

    std::vector< std::vector< Interval > > testsData;
    std::vector< int > answers;
};

} //task1003

#endif // __1003_PARITY_HPP__
