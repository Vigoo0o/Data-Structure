#pragma once
#include <iostream>
using namespace std;
template <class T>

class doublyLinkedList
{
private:
    struct node
    {
        T value;
        node *next;
        node *prev;

        node(T data)
        {
            this->value = data;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    node *head;

    node *find(node *head, int value)
    {
        while (head != NULL)
        {
            if (head->value == value)
                return head;

            head = head->next;
        }
        return NULL;
    }

public:
    void insertAtBeginning(T value)
    {
        node *newNode = new node(value);
        newNode->next = head;

        if (head != NULL)
            head->prev = newNode;

        head = newNode;
    }

    bool search(T value)
    {
        node *temp = head;
        while (temp != NULL)
        {
            if (temp->value == value)
            {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    void insertAfter(T value, T after)
    {
        node *target = find(head, after);

        if (target == NULL)
        {
            cout << "Node Not Found :(\n";
            return;
        }

        node *newNode = new node(value);
        newNode->next = target->next;
        newNode->prev = target;

        if (target->next != NULL)
        {
            target->next->prev = newNode;
        }

        target->next = newNode;
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "List is empty!\n";
            return;
        }

        node *temp = head;
        while (temp != NULL)
        {
            cout << temp->value << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    void insertAtEnd(T value)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        node *lastNode = head;
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        node *newNode = new node(value);
        lastNode->next = newNode;
        newNode->prev = lastNode;
    }

    void deleteNode(T value)
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        node *target = head;
        while (target->value != value)
        {
            target = target->next;
        }

        if (head == target)
        {
            head = target->next;
        }

        if (target->next != NULL)
        {
            target->next->prev = target->prev;
        }

        if (target->prev != NULL)
        {
            target->prev->next = target->next;
        }
        delete target;
    }

    void deleteFirstNode()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        node *firstNode = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;
        }

        delete firstNode;
    }

    void deleteLastNode()
    {
        if (head == NULL)
        {
            cout << "List is empty\n";
            return;
        }

        node *lastNode = head;
        while (lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }

        if (lastNode->prev != NULL)
        {
            lastNode->prev->next = NULL;
        }
        delete lastNode;
    }
};
