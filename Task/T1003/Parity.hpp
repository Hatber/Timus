#ifndef __1003_PARITY_HPP__
#define __1003_PARITY_HPP__

#include "../ATask.hpp"

namespace task1003 {

class Parity : public task::ATask
{
public:
    Parity(std::istream& input, std::ostream& output);

    void Input();
    void Output();
    void Logic();

};

//    int main()
//    {
//        int sequenceSize;
//        int questionSize;
//
//        int start;
//        int end;
//        string parity;
//
//        while(true) {
//            cin >> sequenceSize;
//            if(sequenceSize == -1) {
//                return 0;
//            }
//
//            cin >> questionSize;
//
//            bool isFound = false;
//
//            Sequence seq;
//            for(int i = 0; i<questionSize; i++) {
//                cin >> start >> end >> parity;
//
//                if(!isFound && !seq.addInteval(Interval(start, end, makeParityFromString(parity)))) {
//                    cout << i << endl;
//                    isFound = true;
//                }
//            }
//
//            if(isFound == false) {
//                cout << questionSize << endl;
//            }
//        }
//
//        return 0;
//    }


} //task1003

#endif // __1003_PARITY_HPP__
