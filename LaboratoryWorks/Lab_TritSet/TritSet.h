//
// Created by Alex Borzikov on 23.09.2019.
//

#include <cstdlib>
#include <functional>
#include <unordered_map>
#include "Trit.h"

#ifndef TERNARYNUMERALSYSTEM_TRITSET_H
#define TERNARYNUMERALSYSTEM_TRITSET_H

class TritSet {

public:
    // TODO CHANGE ALL INDEXES TYPES TO size_t
    class Proxy {

        public:
            Proxy(size_t index, TritSet *tritSet);
            operator Trit() const;
            Proxy &operator=(Trit newValue);

        private:
            unsigned int proxyIndex;
            Trit value;
            TritSet *setPtr;
    };

    explicit TritSet(size_t size);

    // length of internal array
    unsigned int capacity();

    //освобождение памяти до начального значения или
    //до значения необходимого для хранения последнего установленного трита
    void shrink();

    TritSet operator & (TritSet setA);

    TritSet operator | (TritSet setA) ;

    TritSet operator ~ ();

    Proxy operator[](size_t index);

    //число установленных в данное значение тритов
    //для трита Unknown - число значений Unknown до последнего установленного трита
    size_t cardinality(Trit value);

    //аналогично но сразу для всех типов тритов
    // TODO USE std::hash<int>
    std::unordered_map<Trit, int> cardinality();

    // забыть содержимое от lastIndex и дальше
    void trim(size_t lastIndex);

    // logical length - индекс последнего не Unknown трита +1
    size_t length();

private:

    unsigned int *set;
    unsigned int size;
    unsigned int lastTritIndex;
    unsigned int lastNotUnknownTritIndex;
    unsigned int trueCount;
    unsigned int falseCount;

    static void fixSizes(TritSet &a, TritSet &b);
    void resize(size_t newSize);

};

#endif //TERNARYNUMERALSYSTEM_TRITSET_H