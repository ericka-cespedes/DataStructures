#include <iostream>
#include "OrderedArrayList.h"
#include "OrderedLinkedList.h"

using namespace std;

int main() {
    OrderedArrayList<int> Array;
    Array.insert(0);
    Array.insert(20);
    Array.insert(500);
    Array.insert(10);
    Array.insert(30);
    Array.insert(50);
    Array.insert(1000);
    Array.goToStart();
    while (!Array.atEnd()) {
        cout << Array.getElement();
        Array.next();
    }
}
