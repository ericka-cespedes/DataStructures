#ifndef ORDEREDARRAYLIST_H
#define ORDEREDARRAYLIST_H

#include "ArrayList.h"

template <typename E>
class OrderedArrayList: public ArrayList<E> {
    public:
        OrderedArrayList(int maxSize = DEFAULT_MAX_SIZE) : ArrayList<E>(maxSize) {}
        void insert(E element) throw (runtime_error) {
            ArrayList<E>::goToStart();
            while (!ArrayList<E>::atEnd() && element >= ArrayList<E>::getElement()) {
                ArrayList<E>::next();
            }
            ArrayList<E>::next;
        }
        void append(E element) throw (runtime_error) {
            insert(element);
        }
        bool contains(E element) {
            return indexOf(element) != -1;
        }
        int indexOf(E element) {
            int min = 0;
            int max = ArrayList<E>::size - 1;
            while (min <= max) {
                int mid = (min + max) /2;
                if (element == ArrayList<E>::elements[mid]) {
                    while (ArrayList<E>::elements[mid-1] == ArrayList<E>::elements[mid]) {
                        mid--;
                    }
                    return mid;
                } else if (element < ArrayList<E>::elements[mid]) {
                    max = mid-1;
                } else {
                    min = mid+1;
                }
            }
            return -1;
        }
};

#endif // ORDEREDARRAYLIST_H
