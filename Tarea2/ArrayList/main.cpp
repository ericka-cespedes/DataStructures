#include <iostream>
#include "ArrayList.h"

using namespace std;

int main() {
    int max = 1024;
    ArrayList<int> ArrayInsert(max);
    cout << "Start insert: ";
    for (int i=0; i<=(max+10); i++){
        ArrayInsert.insert(i);
        cout << ArrayInsert.getElement();
        cout << ", ";
    }
    cout << "\nArray's size: " << ArrayInsert.getSize();
    cout << "\nEnd insert" << "\n";
    //remove
    cout << "Start remove: ";
    ArrayInsert.remove();
    cout << ArrayInsert.remove();
    cout << " End remove" << "\n" << "Start goToStart: ";
    //goToStart
    ArrayInsert.goToStart();
    cout << "Pos: " << ArrayInsert.getPos();
    cout << " End goToStart" << "\n" << "Start atStart: ";
    //atStart
    cout << ArrayInsert.atStart();
    cout << " End atStart" << "\n" << "Start goToEnd: ";
    //goToEnd
    ArrayInsert.goToEnd();
    cout << "Pos: " << ArrayInsert.getPos();
    cout << " End goToEnd" << "\n" << "Start atEnd: ";
    //atEnd
    cout << ArrayInsert.atEnd();
    cout << " End atEnd" << "\n" << "Start goToPos: ";
    //goToPos
    ArrayInsert.goToPos(1000);
    cout << "Pos: " << ArrayInsert.getPos();
    cout << " End goToPos(1000)" << "\n" << "Start atStart: ";
    //atStart
    cout << ArrayInsert.atStart();
    cout << " End atStart" << "\n" << "Start atEnd: ";
    //atEnd
    cout << ArrayInsert.atEnd();
    cout << " End atEnd" << "\n" << "Start next: ";
    //next
    ArrayInsert.next();
    cout << "Pos: " << ArrayInsert.getPos();
    cout << " End next" << "\n" << "Start previous: ";
    //previous
    ArrayInsert.previous();
    cout << "Pos: " << ArrayInsert.getPos();
    cout << " End previous" << "\n" << "Start contains(1000): ";
    //contains
    cout << ArrayInsert.contains(1000);
    cout << " End contains" << "\n" << "Start indexOf(1000): ";
    //indexOf
    cout << ArrayInsert.indexOf(1000);
    cout << "\nArray.goToPos(Array.indexOf(1000)): ";
    ArrayInsert.goToPos(ArrayInsert.indexOf(1000));
    cout << ArrayInsert.getElement();
    cout << "\nEnd indexOf" << "\n";
}
