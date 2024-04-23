#include "SymbolTable.h"
#include <iostream>
#include <string>
using namespace std;


SymbolTable::SymbolTable()
{
    for (int i = 0; i < TABLE_SIZE; ++i)
    {
        table[i] = Entry('\0', 0);
    }
}

/*
Input: key - a character
Output: an integer representing the hash value

FUNCTION hashValue(key):
    return ASCII value of key - ASCII value of 'A'
*/

int SymbolTable::hashValue(char key) const
{
    return key - 'A';
}

/*
Input: key - a character, value - an integer
Action: Inserts a new entry into the SymbolTable

FUNCTION insertValue(key, value):
    index <- hashValue(key)
    // respresents hash value of a key
    table[index] <- Entry(key, value)

*/

void SymbolTable::insertValue(char key, int value)
{
    int index = hashValue(key);
    table[index] = Entry(key, value);
}

/*
Input: key - a character
Output: the value associated with the given key

FUNCTION searchValue(key):
    index <- hashValue(key)
    RETURN table[index].value
*/

int SymbolTable::searchValue(char key) const
{
    int index = hashValue(key);
    return table[index].value;
}

/*
Output: true if the SymbolTable is empty, false otherwise
FUNCTION isEmpty():
    for i <- 0 to 25:
        if table[i].key ≠ Nil:
            RETURN false
    RETURN true

*/

bool SymbolTable::isEmpty()
{

    for (int i = 0; i < 26; ++i)
    {
        if(table[i].key != '\0')
            return 0;
    }
    return 1;
}

void SymbolTable::printSymbolTable()
{
    cout<<"---------------------"<<endl;
    cout<<'|'<<"Symbol"<<'\t'<<'|'<<'\t'<<"Value"<<'|'<<endl;
    cout<<"---------------------"<<endl;
    for (int i = 0; i < 26; ++i)
    {
        if(table[i].key == '\0')
            continue;

        cout<<'|' << table[i].key<<'\t' <<'|'<< '\t' << table[i].value<<'|' <<endl;
    }
    cout<<"---------------------"<<endl;
}




