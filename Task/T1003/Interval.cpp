#include "Interval.hpp"

using namespace task1003;

Interval::Interval(int start, int end, ParityE parity) :
        _start(start), _end(end), _parity(parity)
{ }

bool Interval::operator < (const Interval& rhs) const {
    return _end < rhs._end;
}