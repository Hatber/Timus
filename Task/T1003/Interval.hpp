#ifndef __1003_INTERVAL_HPP__
#define __1003_INTERVAL_HPP__

#include <string>

namespace task1003 {

    enum ParityE{EVEN, ODD};

    struct Interval {
        Interval(int start, int end, ParityE parity);

        int _start;
        int _end;
        ParityE _parity;
    };

    bool operator < (const Interval& lhs, const Interval& rhs);
    ParityE makeParityFromString(const std::string& p);

} //task1003

#endif // __1003_INTERVAL_HPP__
