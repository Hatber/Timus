#ifndef __1003_SEQUENCE_HPP__
#define __1003_SEQUENCE_HPP__

#include "Interval.hpp"

#include <set>

namespace task1003 {

    class Sequence : public std::set < Interval > {
    public:
        bool addInterval(const Interval& newInterval);

    private:
        ParityE makeParity(ParityE f, ParityE s);
    };

} //task1003

#endif // __1003_SEQUENCE_HPP__
