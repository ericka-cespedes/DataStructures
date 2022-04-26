#include <iostream>
#include "DLinkedList.h"
#include "DCircleList.h"

using namespace std;

int main() {
    DLinkedList<int> linked;

    cout << "DLinkedList" << endl;
    cout << "Insert 1001 elements" << endl;
    for (int i=0; i<=(1000); i++){
        linked.insert(i);
    }
    cout << "Size " << linked.getSize() << endl;
    cout << "Remove " << linked.remove() << endl;
    cout << "Size " << linked.getSize() << endl;
    cout << "Append" << endl;
    linked.append(10001);
    cout << "Size " << linked.getSize() << endl;
    cout << "goToStart " << endl;
    linked.goToStart();
    cout << "atStart " << linked.atStart() << endl;
    linked.goToEnd();
    cout << "goToEnd" << endl;
    cout << "atEnd " << linked.atEnd() << endl;
    linked.goToPos(500);
    cout << "goToPos 500" <<endl;
    cout << "getPos " << linked.getPos() << endl;
    linked.clear();
    cout << "Size after clear " << linked.getSize() << endl;

    DCircleList<int> circle;

    cout << endl << "DCircleList" << endl;
    cout << "Insert 1001 elements" << endl;
    for (int i=0; i<=(1000); i++){
        circle.insert(i);
    }
    cout << "Size " << circle.getSize() << endl;
    cout << "Front " << circle.getFront() << endl;
    cout << "Back " << circle.getBack() << endl;
    circle.next();
    cout<< "Next" << endl;
    cout << "Front " << circle.getFront() << endl;
    cout << "Back " << circle.getBack() << endl;
    circle.previous();
    cout << "Previous" << endl;
    cout << "Front " << circle.getFront() << endl;
    cout << "Back " << circle.getBack() << endl;
    cout << "Remove " << circle.remove() << endl;
    cout << "Size " << circle.getSize() << endl;
    circle.clear();
    cout << "Size after clear " << circle.getSize() << endl;

    return 0;
}
