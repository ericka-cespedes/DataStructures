/**
	Clase: TrieNode
	Autor: Mauricio Avilés

	Implementación de un árbol de búsqueda binario, en el que los elementos del subárbol derecho son iguales o mayores que el elemento de la raíz y
	los elementos del subárbol izquierdo son menores  que el elemento de la raíz;

*/

#ifndef BSTREE_H
#define BSTREE_H
#include "BSTNode.h"
#include "List.h"
#include <stdexcept>
#include "DLinkedList.h"

template<typename E>
class BSTree {
private:
	BSTNode<E> *root;

public:
	BSTree () {
		root = NULL;
	}

	~BSTree () {
		clear ();
	}

	void insert (E element) {
		root = insertAux (root, element);
	}

private:
	BSTNode<E>* insertAux (BSTNode<E> *pRoot, E element) {
		if (pRoot == NULL)
			return new BSTNode<E> (element);
		if (element < pRoot->getElement ())
			pRoot->setLeft (insertAux (pRoot->getLeft (), element));
		else
			pRoot->setRight (insertAux (pRoot->getRight (), element));
		return pRoot;
	}

public:
	E find (E element) throw (std::runtime_error) {
		return findAux (root, element);
	}

private:
	E findAux (BSTNode<E> *pRoot, E element) throw (std::runtime_error) {
		if (pRoot == NULL)
			throw std::runtime_error ("Key not found.\n");
		if (element == pRoot->getElement ())
			return pRoot->getElement ();
		return (element < pRoot->getElement () ? findAux (pRoot->getLeft (), element) : findAux (pRoot->getRight (), element));
	}

public:
	E remove (E element) {
		E res = find (element);
		root = removeAux (root, element);
		return res;
	}

private:
	BSTNode<E>* removeAux (BSTNode<E> *pRoot, E element) throw (std::runtime_error) {
		if (pRoot == NULL)
			throw std::runtime_error ("Key not found.\n");

		if (element < pRoot->getElement ()) {
			pRoot->setLeft (removeAux (pRoot->getLeft (), element));
			return pRoot;
		} else if (element > pRoot->getElement ()) {
			pRoot->setRight (removeAux (pRoot->getRight (), element));
			return pRoot;
		}

		if (pRoot->isLeaf ()) {
			delete pRoot;
			return NULL;
		}

		if (pRoot->childCount () == 1) {
			BSTNode<E> *child = pRoot->getOnlyChild ();
			delete pRoot;
			return child;
		} else {
			BSTNode<E> *succ = pRoot->getSuccessor ();
			swap (pRoot, succ);
			pRoot->setRight (removeAux (pRoot->getRight (), element));
			return pRoot;
		}
	}

private:
	void swap (BSTNode<E> *node1, BSTNode<E> *node2) {
		E temp = node1->getElement ();
		node1->setElement (node2->getElement ());
		node2->setElement (temp);
	}

public:
	bool contains (E element) {
		return containsAux (root, element);
	}

private:
	bool containsAux (BSTNode<E> *pRoot, E element) {
		if (pRoot == NULL)
			return false;
		if (pRoot->getElement () == element)
			return true;
		return (element < pRoot->getElement () ? containsAux (pRoot->getLeft (), element) : containsAux (pRoot->getRight (), element));
	}

public:
	void clear () {
		clearAux (root);
		root = NULL;
	}

private:
	void clearAux (BSTNode<E> *pRoot) {
		if (pRoot == NULL)
			return;
		clearAux (pRoot->getLeft ());
		clearAux (pRoot->getRight ());
		delete pRoot;
	}

public:
	List<E>* getElements () {
		List<E> *elements = new DLinkedList<E> ();
		getElementsAux (root, elements);
		return elements;
	}

private:
	void getElementsAux (BSTNode<E> *pRoot, List<E> *elements) {
		if (pRoot == NULL)
			return;
		getElementsAux (pRoot->getLeft (), elements);
		elements->append (pRoot->getElement ());
		getElementsAux (pRoot->getRight (), elements);
	}

public:
	int getSize () {
		return getSizeAux (root);
	}

private:
	int getSizeAux (BSTNode<E> *pRoot) {
		if (pRoot == NULL)
			return 0;
		return 1 + getSizeAux (pRoot->getLeft ()) + getSizeAux (pRoot->getRight ());
	}

};

#endif // BSTREE_H
