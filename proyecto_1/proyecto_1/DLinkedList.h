/**
	Clase: TrieNode
	Autor: Mauricio Avilés

	Clase genérica que implementa los métodos de la clase abstracta List<E> y utiliza el DNode para tener acceso al siguiente nodo y al anterior.

*/

#ifndef DLINKEDLIST_H
#define DLINKEDLIST_H
#include "List.h"
#include "DNode.h"
#include <stdexcept>

template <typename E>
class DLinkedList : public List<E> {

private:
	DNode<E> *head;
	DNode<E> *tail;
	DNode<E> *current;
	int size;

public:
	DLinkedList () {
		current = head = new DNode<E> (NULL, NULL);
		head->next = tail = new DNode<E> (NULL, head);
		size = 0;
	}

	~DLinkedList () {
		clear ();
		delete head;
		delete tail;
	}

	void insert (E element) {
		current->next = current->next->previous = new DNode<E> (element, current->next, current);
		size++;
	}

	void append (E element) {
		tail->previous = tail->previous->next = new DNode<E> (element, tail, tail->previous);
		size++;
	}

	E remove () throw (std::runtime_error) {
		if (current->next == tail)
			throw std::runtime_error ("No element to remove");
		E result = current->next->element;
		current->next = current->next->next;
		delete current->next->previous;
		current->next->previous = current;
		size--;
		return result;
	}

	void clear () {
		current = head->next;
		while (head->next != tail) {
			head->next = head->next->next;
			delete current;
			current = head->next;
		}
		size = 0;
		current = tail->previous = head;
	}

	void goToPos (int pos) throw (std::runtime_error) {
		if (pos < 0 || pos >= size)
			throw std::runtime_error ("Index out of bounds");
		current = head;
		for (int i = 0; i < pos; i++)
			current = current->next;
	}

	void previous () {
		if (current != head)
			current = current->previous;
	}

	void next () {
		if (current->next != tail)
			current = current->next;
	}


	E getElement () throw (std::runtime_error) {
		if (current->next == tail)
			throw std::runtime_error ("No element to get");
		return current->next->element;
	}

	void goToStart () {
		current = head;
	}

	void goToEnd () {
		current = tail->previous;
	}

	int getPos () {
		int pos = 0;
		DNode<E>* temp = head;
		while (temp != current) {
			pos++;
			temp = temp->next;
		}
		return pos;
	}

	int getSize () {
		return size;
	}

	bool atEnd () {
		return current->next == tail;
	}

	bool atStart () {
		return current == head;
	}

	void extend (List<E> &list) {
		for (list.goToStart (); !list.atEnd (); list.next ()) {
			append (list.getElement ());
		}
	}
};

#endif // DLINKEDLIST_H
