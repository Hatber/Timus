#include "Interval.hpp"

using namespace task1003;

Interval::Interval(int start, int end, ParityE parity) :
        _start(start), _end(end), _parity(parity)
{ }

bool operator < (const Interval& lhs, const Interval& rhs) {
    return lhs._end < rhs._end;
}

ParityE makeParityFromString(const std::string& p) {
    if(p.compare("odd") == 0) { return ODD; }
    return EVEN;
}