#include "Hash.h"

int Hash::generateHash(std::string word) {
    unsigned long long int hash = 0;
    for(int i = 0; i < word.size(); i++)
        hash += word[i] * pow(p, i);
    hash %= m;
    return hash;
}

Node<Record*>* Hash::getRecord(int id, std::string key) {
    Node<Record*>* current = hashtable[id].getNext(nullptr);
    while(current != nullptr) {
        if(current->value->key == key)
            return current;
        current = hashtable[id].getNext(current);
    }
    return nullptr;
}

void Hash::addWord(std::string word, int amount) {
    int id = generateHash(word);
    Node<Record*>* node = getRecord(id, word);
    if(node == nullptr) hashtable[id].addAfter(new Record(word, amount));
    else node->value->useAmount += amount;
}

void Hash::deleteRecord(std::string word) {
    int id = generateHash(word);
    Node<Record*>* node = getRecord(id, word);
    if(node != nullptr) hashtable[id].remove(node);
}

void Hash::getOccurNumber(std::string word) {
    int id = generateHash(word);
    Node<Record*>* node = getRecord(id, word);
    if(node == nullptr) std::cout << "0" << std::endl;
    else std::cout << node->value->useAmount << std::endl;
}