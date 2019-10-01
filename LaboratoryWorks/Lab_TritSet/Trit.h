//
// Created by Alex Borzikov on 26.09.2019.
//

#ifndef TERNARYNUMERALSYSTEM_TRIT_H
#define TERNARYNUMERALSYSTEM_TRIT_H

enum class Trit {False = 1, True = 2, Unknown = 0};

Trit operator&(Trit a, Trit b);
Trit operator|(Trit a, Trit b);
Trit operator~(Trit a);

//TODO MAKE MORE FUNCTIONS

#endif //TERNARYNUMERALSYSTEM_TRIT_H