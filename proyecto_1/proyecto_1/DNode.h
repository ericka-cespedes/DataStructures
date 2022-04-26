/**
	Clase: TrieNode
	Autor: Mauricio Avilés

	Nodo genérico que almacena un elemento, un puntero para el nodo anterior y otro para el siguiente.

*/

#ifndef DNODE_H
#define DNODE_H

template <typename E>
class DNode {
public:
	E element;
	DNode<E> *next;
	DNode<E> *previous;

	DNode (E element, DNode<E> *next, DNode *previous) {
		this->element = element;
		this->next = next;
		this->previous = previous;
	}

	DNode (DNode<E> *next, DNode<E> *previous) {
		this->next = next;
		this->previous = previous;
	}

};
#endif // DNODE_H
