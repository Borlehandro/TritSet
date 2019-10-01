//
// Created by Alex Borzikov on 23.09.2019.
//

#include <iostream>
#include <cmath>
#include "TritSet.h"

using namespace std;

// TODO USE MASK IN ALL BITS OPERATIONS

TritSet::Proxy::operator Trit() const {
    return this->value;
}

TritSet::TritSet(const unsigned int &size) {
    this->set = (unsigned int *) calloc(roundUp(size, 16), sizeof(unsigned int));
    this->lastTritIndex = -1;
    this->lastNotUnknownTritIndex = -1;
    this->falseCount = 0;
    this->trueCount = 0;
    this->size = size;
}

unsigned int TritSet::capacity() {
    return this->size;
}

void TritSet::fixSizes(TritSet &a, TritSet &b) {

    if (a.size > b.size)
        b.resize(a.size);
    if (b.size < a.size)
        a.resize(b.size);
}


void TritSet::resize(size_t newSize) {

    this->set = (unsigned int *) realloc(set,
                                         (roundUp(newSize, 16)) * sizeof(unsigned int));
    this->size = newSize;
}

TritSet::Proxy TritSet::operator[](size_t index) {
    return {index, this};
}

TritSet TritSet::operator&(TritSet setA) {

    fixSizes(setA, *this);
    TritSet resSet(this->size);

    for (unsigned int i = 0; i < this->size; ++i) {

        Trit a = (*this)[i];
        Trit b = setA[i];

        resSet[i] = a & b;
    }
    return resSet;
}

TritSet TritSet::operator|(TritSet setA) {

    fixSizes(setA, *this);
    TritSet resSet(this->size);

    for (unsigned int i = 0; i < this->size; ++i) {

        Trit a = (*this)[i];
        Trit b = setA[i];
        resSet[i] = a | b;
    }
    return resSet;
}

TritSet TritSet::operator~() {

    TritSet resSet(this->size);
    for (unsigned int i = 0; i < this->size; ++i) {
        Trit a = (*this)[i];
        resSet[i] = ~a;
    }

    return resSet;
}

//TODO DON'T USE *tritSet IN PROXY, YOU ARE IN THE CLASS INSIDE !!!

TritSet::Proxy::Proxy(size_t index, TritSet *tritSet) {
    this->proxyIndex = index;
    this->value = index > tritSet->capacity() ?
                  Trit::Unknown : Trit(
                    (tritSet->set[roundUp(index, 16)] >> ((sizeof(unsigned int) * 4 - (index % 16 + 1)) * 2)) & 3u);
    this->setPtr = tritSet;
}

TritSet::Proxy &TritSet::Proxy::operator=(Trit newValue) {

    if (this->proxyIndex > this->setPtr->capacity() && newValue != Trit::Unknown)
        this->setPtr->resize(this->proxyIndex);

    if (this->proxyIndex <= this->setPtr->capacity() || newValue != Trit::Unknown) {

        this->setPtr->set[roundUp(proxyIndex, 16)] =
                (this->setPtr->set[roundUp(proxyIndex, 16)] &
                 (~(3u << (sizeof(unsigned int) * 4 - (proxyIndex % 16 + 1)) * 2)))
                | ((unsigned int) newValue << (sizeof(unsigned int) * 4 - (proxyIndex % 16 + 1)) * 2);
    }

    this->setPtr->lastTritIndex = this->proxyIndex;

    if (newValue != Trit::Unknown)
        this->setPtr->lastNotUnknownTritIndex = this->proxyIndex;

    if (newValue == Trit::False)
        this->setPtr->falseCount += 1;
    else if (newValue == Trit::True)
        this->setPtr->trueCount += 1;

    return *this;
}

void TritSet::shrink() {
    this->set = (unsigned int *) realloc(this->set, roundUp(this->lastTritIndex, 16) * sizeof(unsigned int));
    this->size = this->lastTritIndex;
}

/// TEST METHOD
unsigned int TritSet::Proxy::getArrayValue() {
    return this->setPtr->set[this->proxyIndex];
}

unsigned int TritSet::roundUp(unsigned int dividend, unsigned int module) {
    return dividend / module;
}

size_t TritSet::cardinality(Trit value) {
    switch (value) {
        case Trit::False:
            return this->falseCount;
        case Trit::True:
            return this->trueCount;
        case Trit::Unknown:
            return this->lastNotUnknownTritIndex + 1 - (this->trueCount + this->falseCount);
    }
    return -1;
}

std::unordered_map<Trit, int> TritSet::cardinality() {
    // TODO USE std::hash<int> AND RETURN NEW...
    std::unordered_map<Trit, int> resultMap = {
            {Trit::False,   this->falseCount},
            {Trit::True,    this->trueCount},
            {Trit::Unknown, this->cardinality(Trit::Unknown)}};

    return resultMap;
}

void TritSet::trim(size_t lastIndex) {
    // TODO REPLACE POW WITH MASK
    this->set[roundUp(lastIndex, 16)] = (this->set[roundUp(lastIndex, 16)])
            & ((unsigned int)pow(2, (sizeof(unsigned int) * 8 - lastIndex*2)) - 1);
    cout << "!!! " << ((this->set[roundUp(lastIndex, 16)]) & ((unsigned int)pow(2, (sizeof(unsigned int) * 8 - lastIndex*2)) - 1))<< "\n";
    cout << "!!! " << ((unsigned int)pow(2, (sizeof(unsigned int) * 8 - lastIndex*2)) - 1) << "\n";

    for (unsigned int i = roundUp(lastIndex, 16) + 1; i < roundUp(this->size-1,16); ++i) {
        this->set[i] = 0;
    }
}

size_t TritSet::length() {
    return lastNotUnknownTritIndex+1;
}
