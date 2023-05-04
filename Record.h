#ifndef TRANSACTIONS_RECORD_H
#define TRANSACTIONS_RECORD_H

#include <iostream>

class Record {
public:
    Record() = default;
    Record(std::string key, int useAmount) {
        this->key = key;
        this->useAmount = useAmount;
    }
    std::string key;
    int useAmount;
    ~Record() = default;
};

#endif //TRANSACTIONS_RECORD_H
