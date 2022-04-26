/**
	Clase: TrieNode
	Autor: Mauricio Avilés

	Clase abstracta genérica en la que se defininen los metodos con los que se opera sobre un diccionario y
	que deben ser implementados en las clases que hereden de esta. 

*/

#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "List.h"

template <typename K, typename V>
class Dictionary {
public:
	Dictionary () {}
	virtual ~Dictionary () {}
	virtual void insert (K key, V value) = 0;
	virtual V remove (K key) = 0;
	virtual V getValue (K key) = 0;
	virtual void setValue (K key, V value) = 0;
	virtual void clear () = 0;
	virtual bool contains (K key) = 0;
	virtual List<K>* getKeys () = 0;
	virtual List<V>* getValues () = 0;
	virtual int getSize () = 0;

protected:
	void checkDuplicated (K key) throw (std::runtime_error) {
		if (contains (key))
			throw std::runtime_error ("Duplicated key\n");
	}

	void checkExisting (K key) throw (std::runtime_error) {
		if (!contains (key))
			throw std::runtime_error ("Key not found\n");
	}
};

#endif // DICTIONARY_H
