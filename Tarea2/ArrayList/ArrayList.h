#ifndef ARRAYLIST_H
#define ARRAYLIST_H

#include "List.h"

#define DEFAULT_MAX_SIZE 1024
#include <stdexcept>

using std::runtime_error;

template <typename E>
class ArrayList: public List<E> {
private:
    E*elements;
    int max;
    int size;
    int pos;
public:
    ArrayList(int maxSize = DEFAULT_MAX_SIZE) {
        elements = new E[maxSize];
        max = maxSize;
        size = 0;
        pos = 0;
    }
    ~ArrayList() {
        delete [] elements;
    }

    void insert(E element) {
        if (size == max) {
            E*tempElements;
            tempElements = new E[max*2];
            for (int i = 0; i <= max; i++) {
                tempElements[i] = elements[i];
            }
            delete[] elements;
            elements = tempElements;
            delete[] tempElements;
            max*=2;
        }
        for (int i = size; i > pos; i--){
            elements[i] = elements[i-1];
        }
        elements[pos] = element;
        size++;
    }
    void append(E element) {
        if (size == max){
            E*tempElements;
            tempElements = new E[max*2];
            for (int i = 0; i < max; i++) {
                tempElements[i] = elements[i];
            }
            delete[] elements;
            elements = tempElements;
            delete[] tempElements;
            max*=2;
        }
        elements[size] = element;
        size++;
    }
    E remove() throw(runtime_error) {
        if (size == 0) {
            throw runtime_error("Empty list");
        }
        if ((pos < 0) || (pos >= size)) {
            throw runtime_error("Index out of bounds");
        }
        E res = elements[pos];
        for (int i = pos; i < size; i++) {
            elements[i] = elements[i+1];
        }
        size--;
        return res;
    }
    void clear() {
        size = 0;
        pos = 0;
        delete[] elements;
        elements = new E[max];
    }
    E getElement () throw(runtime_error) {
        if ((pos < 0) || (pos >= size)) {
            throw runtime_error("Index out of bounds");
        }
        return elements[pos];
    }
    void goToStart() {
        pos = 0;
    }
    void goToEnd() {
        pos = size;
    }
    void goToPos(int newPos) throw(runtime_error) {
        if ((newPos < 0) || (newPos > size)) {
            throw runtime_error("Index out of bounds");
        }
        pos = newPos;
    }
    void next() {
        if (pos < size) {
            pos++;
        }
    }
    void previous() {
        if (pos > 0) {
            pos--;
        }
    }
    bool atStart() {
        return pos == 0;
    }
    bool atEnd() {
        return pos == size;
    }
    int getPos() {
        return pos;
    }
    int getSize() {
        return size;
    }
    bool contains(E element) throw(runtime_error) {
        if (size == 0) {
            throw runtime_error("Empty list");
        }
        for (int i = 0; i < size; i++) {
            if (elements[i] == element) {
                return true;
            }
        }
        return false;
    }
    int indexOf(E element) {
        for (int i = 0; i < size; i++) {
            if (elements[i] == element) {
                return i;
            }
        }
        return -1;
    }
    /*
    void extend(ArrayList L) {
        if (size == max){
            E*tempElements;
            tempElements = new E[max*2];
            for (int i = 0; i < max; i++) {
                tempElements[i] = elements[i];
            }
            delete[] elements;
            elements = tempElements;
            delete[] tempElements;
            max*=2;
        }
        for (int i = 0; i < sizeof(L); i++) {
            elements[size] = L[i];
            size++;
        }
    }*/
};

#endif
