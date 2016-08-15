#ifndef __T1001_REVERSE_ROOT_HPP__
#define __T1001_REVERSE_ROOT_HPP__

#include "../ATask.hpp"
#include <vector>

namespace task1001 {

class ReverseRoot : public task::ATask {
public:
    ReverseRoot(std::istream& input, std::ostream& output);

    void Input();
    void Output();

    void Logic();

protected:
    std::vector<long double> sqrtNumbers;
};

} //task1001
#endif // __T1001_REVERSE_ROOT_HPP__
