#include <iostream>
#include "classes/linkedList.h"
using namespace std;

int main()
{
    linkedList list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(3);

    list.display();
    return 0;
}