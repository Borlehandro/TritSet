#include <iostream>
#include <vector>
#include <cassert>

#include "TritSet.h"

using namespace std;

int main()
{
    //резерв памяти для хранения 1000 тритов
    TritSet set(1000);

    // length of internal array
    size_t allocLength = set.capacity();
    assert(allocLength >= 1000*2 / 8 / sizeof(unsigned int) );
    cout << allocLength << "\n";

    // 1000*2 - min bits count
    // 1000*2 / 8 - min bytes count
    // 1000*2 / 8 / sizeof
    // (uint) - min uint[] proxyIndex

    /// IT WORK GREAT !!!
    /*cout << "test\n";
    set[1] = Trit::True;
    set[0] = Trit::Unknown;
    set[15] = Trit::True;
    set[16] = Trit::Unknown;
    //cout << set[16] << "\n";
    //cout << (set[16] == Trit::Unknown) << "\n";
    cout << (int)(set[0]&set[1]) << "\n" ;
    cout << (int)(set[0]|set[1]) << "\n" ;
    cout << (int)(~set[1]) << "\n" ;
    cout << (int)(~set[16]) << "\n" ;
    //cout << set[1].getArrayValue() << "\n";
    cout << "test\n";*/

    //не выделяет никакой памяти

    set[1000000000] = Trit::Unknown;
    assert(allocLength == set.capacity());

    // false, but no exception or memory allocation

    if(Trit::True == set[2000000000]){}
    assert(allocLength == set.capacity());

    //выделение памяти

    set[1000000000] = Trit::True;
    assert(allocLength < set.capacity());
    cout << (set[1000000000] == Trit::True) << "\n";

    //no memory operations

    allocLength = set.capacity();
    set[1000000000] = Trit::Unknown;
    set[1000000] = Trit::False;
    assert(allocLength == set.capacity());

    ///IT WORK GREAT !
    TritSet setA(1000);
    setA[0] = Trit::Unknown;
    setA[1] = Trit::Unknown;
    setA[2] = Trit::Unknown;
    setA[3] = Trit::False;
    TritSet setB(2000);
    setB[0] = Trit::True;
    setB[1] = Trit::True;
    setB[2] = Trit::Unknown;
    setB[16] = Trit::Unknown;
    cout << setA[0].getArrayValue() << " " << setA[1].getArrayValue() << "\n";
    cout << setB[0].getArrayValue() << " " << setB[1].getArrayValue() << "\n";
    TritSet setC = setA | setB;
    for (unsigned int i = 0; i < setC.capacity(); ++i) {
        cout << " " << (int)(Trit)setC[i] << " ";
    }
    assert(setC.capacity() == setB.capacity());

    //освобождение памяти до начального значения или
    //до значения необходимого для хранения последнего установленного трита
    //в данном случае для трита 1000’000

    set.shrink();
    assert(allocLength > set.capacity());
    cout << set.capacity() << "\n";
    TritSet test(20);
    //test[0] = Trit::Unknown;
    test[1] = Trit::True;
    test[2] = Trit::True;
    test[3] = Trit::True;

    //cout << test.cardinality(Trit::False) << " " << test.cardinality(Trit::True) << " " << test.cardinality(Trit::Unknown) << "\n";
    cout << test[0].getArrayValue() << "\n";
    auto d = test.cardinality();
    cout << test.length() << "\n";
    test.trim(2);
    cout << test[0].getArrayValue() << "\n";
    return 0;
}