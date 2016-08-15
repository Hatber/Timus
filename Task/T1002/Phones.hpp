#ifndef __T1002_PHONES_HPP__
#define __T1002_PHONES_HPP__

#include "../ATask.hpp"
#include "Number.hpp"

#include <vector>

namespace task1002 {

class Phones : public task::ATask {
public:
    Phones(std::istream& input, std::ostream& output);

    void Input();
    void Output();
    void Logic();

private:
    std::vector< Number > _numbers;
    std::vector< std::string > _answer;
};

} //task1002

#endif // __T1002_PHONES_HPP__
