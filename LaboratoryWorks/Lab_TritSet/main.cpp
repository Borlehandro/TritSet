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

    // 1000*2 - min bits count
    // 1000*2 / 8 - min bytes count
    // 1000*2 / 8 / sizeof
    // (uint) - min uint[] proxyIndex

    //не выделяет никакой памяти

    set[1000000000] = Trit::Unknown;
    assert(allocLength == set.capacity());

    // false, but no exception or memory allocation

    if(Trit::True == set[2000000000]){}
    assert(allocLength == set.capacity());

    //выделение памяти

    set[1000000000] = Trit::True;
    assert(allocLength < set.capacity());

    //no memory operations

    allocLength = set.capacity();
    set[1000000000] = Trit::Unknown;
    set[1000000] = Trit::False;
    assert(allocLength == set.capacity());

    TritSet setA(1000);
    TritSet setB(2000);

    setA[0] = Trit::Unknown;
    setA[1] = Trit::Unknown;
    setA[2] = Trit::Unknown;
    setA[3] = Trit::False;

    setB[0] = Trit::True;
    setB[1] = Trit::True;
    setB[2] = Trit::Unknown;
    setB[16] = Trit::Unknown;

    TritSet setC = setA | setB;

    assert(setC.capacity() == setB.capacity());

    //освобождение памяти до начального значения или
    //до значения необходимого для хранения последнего установленного трита
    //в данном случае для трита 1000’000

    set.shrink();
    assert(allocLength > set.capacity());

    return 0;
}