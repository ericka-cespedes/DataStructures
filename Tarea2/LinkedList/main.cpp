#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
    LinkedList<int> L;
    for (int i =0; i==10; i++) {
        L.insert(i);
        cout << L.getElement();
    }

}
