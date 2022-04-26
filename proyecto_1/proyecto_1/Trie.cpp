#include "Trie.h"
#include "DLinkedList.h"

Trie::Trie () {
	root = new TrieNode ();
}

Trie::~Trie () {
	clear ();
	delete root;
}

void Trie::insert (KVPair<int, std::string> word) {
	TrieNode *current = root;
	for (unsigned int i = 0; i < word.getValue ().size (); i++) {
		current->increaseCount ();
		if (!current->contains (word.getValue ()[i]))
			current->add (word.getValue ()[i]);
		current = current->getChild (word.getValue ()[i]);
	}

	if (!contains (word.getValue ())) {
		current->increaseCount ();
		current->setIsWord (true);
	}	

	current->insertLineNumber (word.getKey ());
}

bool Trie::contains (std::string word, bool prefix) {
	TrieNode *current = root;
	for (unsigned int i = 0; i < word.size (); i++) {
		if (!current->contains (word[i]))
			return false;
		current = current->getChild (word[i]);
	}
	return (prefix ? true : current->getIsWord ());
}

int Trie::prefixCount (std::string prefix) {
	TrieNode *current = root;
	for (unsigned int i = 0; i < prefix.size (); i++) {
		if (!current->contains (prefix[i]))
			return 0;
		current = current->getChild (prefix[i]);
	}
	return current->getPrefixCount ();
}

void Trie::remove (std::string word)throw (std::runtime_error) {
	if (!contains (word))
		throw std::runtime_error ("Word not found.");
	TrieNode *current = root;
	for (unsigned int i = 0; i < word.size (); i++) {
		current->decreaseCount ();
		TrieNode *child = current->getChild (word[i]);
		if (current->getPrefixCount () == 0)
			delete current;
		else if (child->getPrefixCount () == 1)
			current->remove (word[i]);
		current = child;
	}
	current->decreaseCount ();
	current->getPrefixCount () == 0 ? delete current : current->setIsWord (false);
}

void Trie::clear () {
	clearAux (root);
	root = new TrieNode ();
}

void Trie::clearAux (TrieNode* current) {
	List<TrieNode*> *pointers = current->getChildrenPointers ();
	pointers->goToStart ();
	while (!pointers->atEnd ()) {
		clearAux (pointers->getElement ());
		pointers->next ();
	}
	delete current;
}

List< KVPair<std::string, List<int>*> >* Trie::getMatches (std::string prefix) {
	List< KVPair<std::string, List<int>*> > *words = new DLinkedList< KVPair<std::string, List<int>*> > ();
	getMatchesAux (root, prefix, "", words);
	return words;
}

void Trie::getMatchesAux (TrieNode* current, std::string rest, std::string prefix, List< KVPair<std::string, List<int>*> >* words) {
	if (rest.size () == 0 && current->getIsWord ()) {
		KVPair<std::string, List<int>*> p (prefix, current->getLineNumbers ());
		words->append (p);
	}

	List<char> *children = current->getChildren ();
	for (children->goToStart (); !children->atEnd (); children->next ()) {
		char c = children->getElement ();
		if (rest.size () == 0) {
			std::string newPrefix = prefix;
			newPrefix.append (1, c);
			getMatchesAux (current->getChild (c), rest, newPrefix, words);
		} else if (c == rest[0]) {
			std::string newPrefix = prefix;
			newPrefix.append (1, c);
			rest.erase (0, 1);
			getMatchesAux (current->getChild (c), rest, newPrefix, words);
			break;
		}
	}
	delete children;
}

List<std::string>* Trie::getSizeMatches (int size) {
	List<std::string> *words = new DLinkedList<std::string> ();
	getSizeMatchesAux (root, "", size, words);
	return words;
}

void Trie::getSizeMatchesAux (TrieNode * current, std::string prefix, int size, List<std::string>* words) {
	if (prefix.size () == (unsigned) size && current->getIsWord ())
		words->append (prefix);

	List<char> *children = current->getChildren ();
	for (children->goToStart (); !children->atEnd (); children->next ()) {
		char c = children->getElement ();
		std::string newPrefix = prefix;
		newPrefix.append (1, c);
		getSizeMatchesAux (current->getChild (c), newPrefix, size, words);
	}
	delete children;
}


