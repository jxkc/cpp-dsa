#include "dll.h"

int main() {
    DoubleLinkedList<int> int_dll;

    int_dll.push_back(10);
    int_dll.push_back(20);
    int_dll.push_back(30);

    int_dll.traverse();
}
