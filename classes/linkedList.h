#pragma once
#include <iostream>
using namespace std;

class node
{
public:
    int value;
    node *next;

    node(int data)
    {
        this->value = data;
        this->next = nullptr;
    }
};

class linkedList
{
private:
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
    linkedList()
    {
        head = nullptr;
    }

    void insertAtBeginning(int value)
    {
        node *newNode = new node(value);
        newNode->next = head; // to point the element next element
        head = newNode;
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

    bool search(int value)
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

    void insertAfter(int value, int prev)
    {
        node *temp = head;
        node *prevNode = find(temp, prev);

        if (prevNode == NULL)
        {
            cout << "Node not fount :(\n";
            return;
        }

        node *newNode = new node(value);

        newNode->next = prevNode->next;
        prevNode->next = newNode;
    }

    void insertAtEnd(int value)
    {
        node *newNode = new node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        node *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void deleteByValue(int value)
    {
        // Check if the list is empty
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        // If the head node holds the value to be deleted
        if (head->value == value)
        {
            node *nodeToDelete = head;
            head = head->next;   // Move the head to the next node
            delete nodeToDelete; // Delete the old head
            return;
        }

        // Traverse the list to find the node before the one to delete
        node *temp = head;
        while (temp->next->value != value)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "Node Not Found :(\n";
            return;
        }

        node *nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    void deleteFirstElement()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        node *firstNode = head;
        head = head->next;
        delete firstNode;
    }

    void deleteLastElement()
    {
        if (head == nullptr)
        {
            cout << "List is empty!" << endl;
            return;
        }

        node *temp = head;
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }

        node *lastElement = temp->next;
        temp->next = NULL;
        delete lastElement;
    }
};