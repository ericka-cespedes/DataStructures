/**
	Clase: TrieNode
	Autor: Mauricio Avilés

	Un diccionario que implementa los metodos de Dictionary<K, V> y utiliza BSTree para almacenar los pares llave/valor
	Permite la búsqueda de un valor por medio de una llave.

*/

#ifndef BSTDICTIONARY_H
#define BSTDICTIONARY_H
#include <stdexcept>
#include "Dictionary.h"
#include "BSTree.h"
#include "KVPair.h"
#include "List.h"
#include "DLinkedList.h"

template<typename K, typename V>
class BSTDictionary : public Dictionary<K, V> {
private:
	BSTree< KVPair<K, V> > *pairs;

public:
	BSTDictionary () {
		pairs = new BSTree< KVPair<K, V> > ();
	}

	virtual ~BSTDictionary () {
		delete pairs;
	}

	void insert (K key, V value)throw (std::runtime_error) {
		this->checkDuplicated (key);
		KVPair<K, V> p (key, value);
		pairs->insert (p);
	}

	V remove (K key)throw (std::runtime_error) {
		this->checkExisting (key);
		KVPair<K, V> p (key);
		return pairs->remove (p).getValue ();
	}

	V getValue (K key)throw (std::runtime_error) {
		this->checkExisting (key);
		KVPair<K, V> p (key);
		return pairs->find (p).getValue ();
	}

	void setValue (K key, V value)throw (std::runtime_error) {
		this->checkExisting (key);
		KVPair<K, V> p (key, value);
		pairs->remove (p);
		pairs->insert (p);
	}

	void clear () {
		pairs->clear ();
	}

	bool contains (K key) {
		KVPair<K, V> p (key);
		return pairs->contains (p);
	}

	List<K>* getKeys () {
		DLinkedList< KVPair<K, V> > elements;
		elements.extend (*pairs->getElements ());
		List<K> *keys = new DLinkedList<K> ();
		for (elements.goToStart (); !elements.atEnd (); elements.next ())
			keys->append (elements.getElement ().getKey ());
		return keys;
	}

	List<V>* getValues () {
		DLinkedList< KVPair<K, V> > elements;
		elements.extend (*pairs->getElements ());
		List<V> *values = new DLinkedList<V> ();
		for (elements.goToStart (); !elements.atEnd (); elements.next ())
			values->append (elements.getElement ().getValue ());
		return values;
	}

	int getSize () {
		return pairs->getSize ();
	}

	KVPair<K, V> getPair (K key) {
		KVPair<K, V> p (key);
		return pairs->find (p);
	}

};

#endif // BSTDICTIONARY_H
