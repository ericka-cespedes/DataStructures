/**
    Clase: TrieNode
    Autor: Mauricio Avilés
		   Ericka Cespédes, Sara Castro

	Implementación de un Trie. 
	Permite insertar palabras al árbol, si están repetidas solo agrega el número de linea al arreglo 
	que se encuentra en el TrieNode del final de palabra. También se borrar una palabra si esta se encuentra en el árbol.
	Se pueden ralizar busquedas por prefijo, palabra y por cantidad de letras de una palabra.

*/

#ifndef TRIE_H
#define TRIE_H
#include "TrieNode.h"
#include <stdexcept>
#include <string>

class Trie {
private:
	TrieNode * root;
	void clearAux (TrieNode *current);
	void getMatchesAux (TrieNode* current, std::string rest, std::string prefix, List< KVPair<std::string, List<int>*> >* words);
	void getSizeMatchesAux (TrieNode* current, std::string prefix, int size, List<std::string>* words);

public:
	Trie ();
	virtual ~Trie ();
	void insert (KVPair<int, std::string> word);
	bool contains (std::string word, bool prefix = false);
	int prefixCount (std::string prefix);
	void remove (std::string word);
	void clear ();
	List< KVPair<std::string, List<int>*> >* getMatches (std::string prefix);
	List<std::string>* getSizeMatches (int size);

};

#endif // TRIE_H
