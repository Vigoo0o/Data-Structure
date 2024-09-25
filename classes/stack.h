#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 100;
template <class T>

class stack
{
    int Top;
    T Items[MAX_SIZE];

public:
    stack() : Top(-1) {}

    void push(T value)
    {
        if (Top >= MAX_SIZE - 1)
        {
            cout << "Stack is full on push\n";
            return;
        }

        Top++;
        Items[Top] = value;
    }

    bool isEmpty()
    {
        return Top < 0;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty on pop\n";
            return;
        }

        Top--;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return T();
        }
        else
        {
            return Items[Top];
        }
    }

    void print()
    {
        for (int i = Top; i >= 0; i--)
        {
            cout << Items[i] << endl;
        }
    }
};