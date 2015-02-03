#ifndef REVERSEROOT_HPP
#define REVERSEROOT_HPP

#include "../ATask.hpp"
#include <vector>

namespace toj {
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

}} //toj::task1001
#endif // REVERSEROOT_HPP
