#include "Sequence.hpp"

using namespace task1003;

bool Sequence::addInterval(const Interval& newInterval) {
    iterator it = find(newInterval);

    if(it == end()) {
        insert(newInterval);
        return true;
    }

    if(it->_start == newInterval._start) {
        return it->_parity == newInterval._parity;
    }

    if(it->_start < newInterval._start) {
        return addInterval(Interval(it->_start, newInterval._start-1, makeParity(it->_parity, newInterval._parity)));
    }

    return addInterval(Interval(newInterval._start, it->_start-1, makeParity(it->_parity, newInterval._parity)));
}

ParityE Sequence::makeParity(ParityE f, ParityE s) {
    if(f == s) { return EVEN; }
    return ODD;
}
