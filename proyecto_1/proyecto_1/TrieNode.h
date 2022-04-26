/**	
	Clase: TrieNode
	Autores: Mauricio Avilés
		     Ericka Cespédes, Sara Castro

	Nodo de la clase Trie. Almacena un puntero a sus hijos y dice si es final de palabra o no.
	También almacena los números de linea en el que se encuentra cada palabra.

*/

#ifndef TRIENODE_H
#define TRIENODE_H
#include "BSTDictionary.h"
#include "List.h"

class TrieNode {
private:
	bool isWord;
	int prefixCount;
	BSTDictionary<char, TrieNode*> children;
	List<int> *lineNumbers;

public:
	TrieNode ();
	void setIsWord (bool isWord);
	bool getIsWord ();
	void setPrefixCount (int count);
	int getPrefixCount ();
	void increaseCount ();
	void decreaseCount ();
	void insertLineNumber (int number);
	List<int>* getLineNumbers ();
	bool contains (char c);
	void add (char c);
	void remove (char c);
	TrieNode* getChild (char c);
	List<char>* getChildren ();
	List<TrieNode*>* getChildrenPointers ();

};

#endif // TRIENODE_H
