#include <vector>
#include <cstdlib>
#include <set>
#include <ctime>
#include <algorithm>

#include "element.h"

std::vector<Elem> create(int size) {
    std::srand(std::time(NULL));
    std::vector<Elem> vect;
    std::set<int> used;
    int index = 0;
    while (vect.size() != size) {
        int val = std::rand() % size;
        if (!used.count(val)) {
            used.insert(val);
            vect.emplace_back(val, index);
            index++;
        }
    }
    Visualizer::getInstance().setContainer(vect.begin(), vect.end());
    Visualizer::getInstance().clear();
    return vect;
}

int main(int argc, char ** argv) {
    std::vector<Elem> vect{create(100)};  
    Visualizer::getInstance().clear();

    std::sort(vect.begin(), vect.end());

    Visualizer::getInstance().draw();
    return 0;
}