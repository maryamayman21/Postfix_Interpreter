#ifndef STACKARRAY_H
#define STACKARRAY_H
#include <iostream>
#include <SymbolTable.h>

using namespace std;
typedef int ElementType;
const int MAX_SIZE = 100;


class StackArray
{
private:
    int top;
    ElementType elements[MAX_SIZE];
    SymbolTable symbolTable;
public:
    StackArray();
    bool isEmpty();
    bool isFull();
    void push(ElementType x);
    void  pop();
    int Size();
    ElementType Top();
    void printStack();
    void assignVariable(char variable, int value);
    int getVariableValue(char variable) const;

};

#endif // STACKARRAY_H
