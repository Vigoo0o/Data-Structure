#include <iostream>
// #include "classes/linkedList.h"
// #include "classes/arrayStack.h"
// #include "classes/linkedStack.h"
#include "classes/doublyLinkedList.h"
using namespace std;

// struct node
// {
//     int value;
//     node *next;
//     node *prev;

//     node(int data)
//     {
//         this->value = data;
//         this->next = nullptr;
//         this->prev = nullptr;
//     }
// };

// void insertAtBeginning(node *&head, int value)
// {
//     node *newNode = new node(value);
//     newNode->next = head;
//     head->prev = newNode;
//     head = newNode;
// }

// node *find(node *head, int value)
// {
//     while (head != NULL)
//     {
//         if (head->value == value)
//             return head;

//         head = head->next;
//     }
//     return NULL;
// }

// void insertAfter(node *head, int value, int after)
// {
//     node *target = find(head, after);

//     if (target == NULL)
//     {
//         cout << "Node Not Found :(\n";
//         return;
//     }

//     node *newNode = new node(value);
//     newNode->next = target->next;
//     newNode->prev = target;

//     if (target->next != NULL)
//     {
//         target->next->prev = newNode;
//     }

//     target->next = newNode;
// }

int main()
{
    // node *head;

    // node *node1 = new node(1);
    // node *node2 = new node(2);
    // node *node3 = new node(3);

    // // Connect Nodes
    // node1->next = node2;

    // node2->next = node3;
    // node2->prev = node1;

    // node3->prev = node2;

    // head = node1;

    // insertAfter(head, 100, 1);
    // insertAfter(head, 200, 2);
    // insertAfter(head, 300, 3);

    // while (head != NULL)
    // {
    //     cout << head->value << " -> ";
    //     head = head->next;
    // }
    // cout << "NULL\n";

    // +++++++++++++++++++++++++++++++++++++++++++++

    doublyLinkedList<int> list;

    list.insertAtBeginning(3);
    list.insertAtBeginning(2);
    list.insertAtBeginning(1);

    list.insertAfter(100, 1);
    list.insertAfter(200, 2);
    list.insertAfter(300, 3);

    list.display();

    list.deleteFirstNode();
    list.deleteLastNode();

    list.display();

    return 0;
}