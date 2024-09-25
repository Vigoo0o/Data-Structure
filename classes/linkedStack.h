#pragma once
using namespace std;
template <class T>

class linkedStack
{
private:
    struct node
    {
        T value;
        node *next;

        node(T data)
        {
            this->value = data;
            this->next = nullptr;
        }
    };
    node *StackTop;

public:
    linkedStack() : StackTop(NULL) {}

    void push(T value)
    {
        node *newNode = new node(value);
        newNode->next = StackTop;
        StackTop = newNode;
    }

    bool isEmpty()
    {
        return StackTop == NULL;
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty on pop\n";
            return;
        }

        node *nodeToPop = StackTop;
        StackTop = StackTop->next;
        delete nodeToPop;
    }

    T top()
    {
        if (isEmpty())
        {
            cout << "Stack is empty on pop\n";
            return T();
        }
        return StackTop->value;
    }

    void display()
    {
        node *temp = StackTop;
        while (temp != NULL)
        {
            cout << temp->value << endl;
            temp = temp->next;
        }
    }
};
