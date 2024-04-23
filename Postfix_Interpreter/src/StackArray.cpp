#include "StackArray.h"
#include <iostream>

using namespace std;

StackArray::StackArray()
{
    top = -1;
}

bool StackArray::isEmpty()
{

    return top == -1;
}

bool StackArray::isFull()
{
    return top == MAX_SIZE - 1;

}

void StackArray::push(ElementType x)
{
    if (isFull())
        cout << "Stack is full. Cannot push." << endl;
    else
    {
        elements[++top] = x;
    }
}

void  StackArray::pop()
{

    if (isEmpty())
    {

        cout << "Stack is empty. Cannot pop." << endl;
        exit(0);
    }
    else
    {
        top--;
    }
}

ElementType StackArray::Top()
{

    if (isEmpty())
    {
        cout << "Error : The Stack Is Empty" << endl;
        exit(0);
        return -1;
    }
    else
        return elements[top];


}

int StackArray::Size()
{
    return top+1;
}


void StackArray::printStack()
{

    cout << "------------------------" << endl;
    cout<<"Stack is ==>"<<endl;
    for (int i = top ; i >= 0 ; i-- )
    {

        if(elements[i] >= 65 && elements[i] <=97)
            cout<<'|'<<(char)elements[i]<<'|'<<endl;
        else
            cout<<'|'<<elements[i]<<'|'<<endl;

    }
    cout << "------------------------" << endl;

}

void StackArray::assignVariable(char variable, int value)
{
    symbolTable.insertValue(variable, value);
    symbolTable.printSymbolTable();
}

int StackArray::getVariableValue(char variable) const
{
    return symbolTable.searchValue(variable);
}






