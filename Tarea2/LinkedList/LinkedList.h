#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "List.h"
#include "Node.h"
#include <stdexcept>

using std::runtime_error;

template <typename E>
class LinkedList: public List<E> {
    private:
        Node<E>* head;
        Node<E>* tail;
        Node<E>* current;
        int size;
    public:
        LinkedList() {
            head = tail = current = new Node<E>();
            size = 0;
        }
        ~LinkedList() {
            clear();
            delete head;
        }
        void insert(E element) {
            current->next = new Node<E>(element, current->next);
            if (current == tail) {
                tail = tail->next;
            }
            size++;
        }
        void append(E element) {
            tail->next = new Node<E>(element);
            tail = tail->next;
            size++;
        }
        E remove() throw(runtime_error) {
            if (current->next == NULL) {
                throw runtime_error("No element to remove.");
            }
            E result = current->next->element;
            Node<E>*temp = current->next;
            current->next = current->next->next;
            if (current->next == NULL) {
                tail = current;
            }
            delete temp;
            size--;
            return result;
        }
        void clear() {
            current = head;
            while (head != NULL) {
                head = head->next;
                delete current;
                current = head;
            }
            head = tail = current = new Node<E>();
            size = 0;
        }
        E getElement() throw(runtime_error) {
            if (current->next == NULL) {
                throw runtime_error("No element to get.");
            }
            return current->next->element;
        }
        void goToStart() {
            current = head;
        }
        void goToEnd() {
            current = tail;
        }
        void goToPos(int newPos) throw(runtime_error) {
            if ((newPos <0) || (newPos > size)) {
                throw runtime_error("Index out of bounds.");
            }
            current = head;
            for (int i = 0; i < newPos; i++) {
                current = current->next;
            }
        }
        void next() {
            if (current != tail) {
                current = current->next;
            }
        }
        void previous() {
            if (current != head) {
                Node<E>*temp = head;
                while (temp->next != current) {
                    temp = temp->next;
                }
                current = temp;
            }
        }
        bool atStart() {
            return current == head;
        }
        bool atEnd() {
            return current == tail;
        }
        int getPos() {
            int pos = 0;
            Node<E>* temp = head;
            while (temp != current) {
                pos++;
                temp = temp->next;
            }
            return pos;
        }
        int getSize() {
            return size;
        }
        void reverse() {
            current = head;
            Node<E>*prev = NULL;
            Node<E>*next = NULL;

            while (current != NULL) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            head = prev;
        }
};

#endif // LINKEDLIST_H
