#ifndef DCIRCLELIST_H
#define DCIRCLELIST_H

#include <stdexcept>
#include "DNode.h"

using std::runtime_error;

template <typename E>
class DCircleList {
    private:
        DNode<E>*current;
        int size;
    public:
        DCircleList() {
            current = NULL;
            size = 0;
        }
        ~DCircleList() {
            clear();
        }
        void insert(E element) {
            if (current == NULL) {
                current = new DNode<E>(element, current, current);
            }
            else {
                current->next = new DNode<E>(element, current->next, current);
            }
            size++;
        }
        E remove() throw(runtime_error) {
            if (current == NULL) {
                    throw runtime_error("Empty list.");
            }
            E result = current->next->element;
            DNode<E> *temp = current->next;
            if (current == temp) {
                current = NULL;
            }
            else {
                current->next = current->next->next;
            }
            delete temp;
            size--;
            return result;
        }
        void clear() {
            while (current != NULL) {
                remove();
            }
        }
        E getFront() throw (runtime_error) {
            if (current == NULL) {
                throw runtime_error("Empty list.");
            }
            return current->next->element;
        }
        E getBack() throw(runtime_error) {
            if (current == NULL) {
                throw runtime_error("Empty list.");
            }
            return current->element;
        }
        void next() {
            if (current != NULL && size > 1) {
                current = current->next;
            }
        }
        void previous() {
            if (current != NULL && size > 1) {
                current = current->previous;
            }
        }
        int getSize() {
            return size;
        }
};

#endif // DCIRCLELIST_H
