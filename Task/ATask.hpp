#ifndef __ATASK_HPP__
#define __ATASK_HPP__

#include <iostream>

namespace toj {
namespace task {

class ATask {
public:
    ATask(std::istream& input, std::ostream& output);
    virtual ~ATask();

    void Solve();

    virtual void Input()  = 0;
    virtual void Output() = 0;

    virtual void Logic() = 0;

protected:
    std::istream& _input;
    std::ostream& _output;
};

}} //toj::task
#endif // __ATASK_HPP__
