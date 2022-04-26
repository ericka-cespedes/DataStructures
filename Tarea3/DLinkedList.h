#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H

#include <stdexcept>
#include "List.h"
#include "DNode.h"

using std::runtime_error;

template <typename E>
class DLinkedList: public List<E> {
    private:
        DNode<E>*head;
        DNode<E>*tail;
        DNode<E>*current;
        int size;
    public:
        DLinkedList() {
        current = head = new DNode<E>(NULL, NULL);
        head->next = tail = new DNode<E>(NULL, head);
        size = 0;
        }
        ~DLinkedList() {
            clear();
            delete head;
            delete tail;
        }

        void insert(E element) {
            current->next = current->next->previous = new DNode<E>(element, current->next, current);
            /* O,
            current->next->previous = new ...
            current->next = current->next->previous; */
            size++;
        }

        void append (E element) {
            tail->previous = tail->previous->next = new DNode<E> (element, tail, tail->previous);
            size++;
        }

        E remove() throw(runtime_error){
            if (current->next == tail) {
                throw runtime_error("No element to remove");
            }
            E result = current->next->element;
            current->next = current->next->next;
            delete current->next->previous;
            current->next->previous = current;
            size--;
            return result;
        }

        void clear() {
            current = head->next;
            while (head->next != tail) {
                head->next = current->next;
                delete current;
                current = head->next;
            }
            current = tail->previous = head;
            size = 0;
        }

        E getElement() throw (runtime_error){
            if (current->next == tail) {
                throw runtime_error("No current element");
            }
            return current->next->element;
        }

        void goToStart() {
            current = head;
        }

        void goToEnd(){
            current = tail->previous;
        }

        void goToPos(int newPos) throw(runtime_error) {
            if (newPos < 0 || newPos >= size) {
                throw runtime_error("Index out of bounds.");
            }
            current = head;
            for (int i = 0; i < newPos; i++) {
                current = current->next;
            }
        }

        void next(){
            if (current != tail->previous) {
                current = current->next;
            }
        }

        void previous() {
            if (current != head) {
                current = current->previous;
            }
        }

        bool atEnd() {
            return current->next == tail;
        }

        bool atStart() {
            return current == head;
        }

        int getPos() {
            int pos = 0;
            DNode<E> *temp = head;
            while (temp != current) {
                temp = temp->next;
                pos++;
            }
            return pos;
        }

        int getSize() {
            return size;
        }

};

#endif // DLINKEDLIST_H
