/**
	Clase: TrieNode
	Autor: Mauricio Avilés

	Clase genérica del nodo que se utiliza en la implementación de BSTree. Almacena el elemento, y punteros a los hijos izquierdo y derecho.

*/

#ifndef BSTNODE_H
#define BSTNODE_H
#include <cstddef>

template<typename E>
class BSTNode {
private:
	E element;
	BSTNode<E> *left;
	BSTNode<E> *right;

	BSTNode<E>* getSuccessorAux (BSTNode<E> *pRoot) {
		if (pRoot == NULL)
			return NULL;
		if (pRoot->getLeft () == NULL)
			return pRoot;
		return getSuccessorAux (pRoot->getLeft ());
	}

public:
	BSTNode () {}

	BSTNode (BSTNode<E> *left = NULL, BSTNode<E> *right = NULL) {
		this->left = left;
		this->right = right;
	}

	BSTNode (E element, BSTNode<E> *left = NULL, BSTNode<E> *right = NULL) {
		this->left = left;
		this->right = right;
		this->element = element;
	}

	E getElement () {
		return element;
	}

	void setElement (E element) {
		this->element = element;
	}

	BSTNode<E>* getOnlyChild () {
		return (left == NULL ? right : left);
	}

	BSTNode<E>* getSuccessor () {
		return getSuccessorAux (right);
	}

	bool isLeaf () {
		return left == NULL && right == NULL;
	}

	int childCount () {
		return (left == NULL ? 0 : 1) + (right == NULL ? 0 : 1);
	}

	BSTNode<E>* getRight () {
		return right;
	}

	void setRight (BSTNode<E> *right) {
		this->right = right;
	}

	BSTNode<E>* getLeft () {
		return left;
	}

	void setLeft (BSTNode<E> *left) {
		this->left = left;
	}

};

#endif // BSTNODE_H
