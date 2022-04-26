/**
	Clase: TrieNode
	Autor: Mauricio Avilés

	Clase genérica que almacena un par llave/valor

*/

#ifndef KVPAIR_H
#define KVPAIR_H

template<typename K, typename V>
class KVPair {
private:
	K key;
	V value;

public:

	KVPair () {}

	KVPair (K key) {
		this->key = key;
	}

	KVPair (K key, V value) {
		this->key = key;
		this->value = value;
	}

	void operator= (const KVPair &other) {
		key = other.key;
		value = other.value;
	}

	bool operator== (const KVPair &other) {
		return key == other.key;
	}

	bool operator!= (const KVPair &other) {
		return key != other.key;
	}

	bool operator< (const KVPair &other) {
		return key < other.key;
	}

	bool operator<= (const KVPair &other) {
		return key <= other.key;
	}

	bool operator> (const KVPair &other) {
		return key > other.key;
	}

	bool operator>= (const KVPair &other) {
		return key >= other.key;
	}

	K getKey () {
		return key;
	}

	V getValue () {
		return value;
	}

	void setKey (K key) {
		this->key = key;
	}

	void setValue (V value) {
		this->value = value;
	}

};

#endif // KVPAIR_H
