#include <iostream>
#include <string>

#include "Hash.h"

int main() {
    Hash* hash = new Hash();
    std::string command, from, to, key;
    int amount;
    while(std::cin >> command) {
        std::cin >> from >> to;
        key = from + " " + to;
        if (command[0] == '?')
            hash->getOccurNumber(key);
        else if (command[0] == '+') {
            std::cin >> amount;
            hash->addWord(key, amount);
        }
    }
    return 0;
}