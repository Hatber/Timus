#ifndef __T1002_PHONES_H__
#define __T1002_PHONES_H__

#include "../ATask.hpp"
#include "Number.hpp"

#include <vector>

namespace toj {
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

}} //toj::task
#endif // __T1002_PHONES_H__
