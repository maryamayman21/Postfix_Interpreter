#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H
#include <iostream>
using namespace std;

typedef int ElementType;
const int TABLE_SIZE = 26; // from 'A' to 'Z'

class SymbolTable
{
private:

    struct Entry
    {
        char key;
        int value;
        Entry() : key('\0'), value(0) {}
        Entry(char k, ElementType v) : key(k), value(v) {}
    };

    Entry table[TABLE_SIZE];

    int hashValue(char key) const;

public:
    SymbolTable();
    void insertValue(char key, ElementType value);
    ElementType searchValue(char key) const;
    void deleteValue(char key);
    void printSymbolTable();
    bool isEmpty();

};

#endif // SYMBOLTABLE_H
