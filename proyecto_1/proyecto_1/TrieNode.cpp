#include "TrieNode.h"

TrieNode::TrieNode () : children () {
	lineNumbers = new DLinkedList<int> ();
	isWord = false;
	prefixCount = 0;
}

void TrieNode::setIsWord (bool isWord) {
	this->isWord = isWord;
}

bool TrieNode::getIsWord () {
	return isWord;
}

void TrieNode::setPrefixCount (int count) {
	prefixCount = count;
}

int TrieNode::getPrefixCount () {
	return prefixCount;
}

void TrieNode::increaseCount () {
	prefixCount++;
}

void TrieNode::decreaseCount () {
	prefixCount--;
}

void TrieNode::insertLineNumber (int number) {
	lineNumbers->append (number);
}

List<int>* TrieNode::getLineNumbers () {
	return lineNumbers;
}

bool TrieNode::contains (char c) {
	return children.contains (c);
}

void TrieNode::add (char c) {
	TrieNode *child = new TrieNode ();
	children.insert (c, child);
}

void TrieNode::remove (char c) {
	children.remove (c);
}

TrieNode* TrieNode::getChild (char c) {
	return children.getValue (c);
}

List<char>* TrieNode::getChildren () {
	return children.getKeys ();
}

List<TrieNode*>* TrieNode::getChildrenPointers () {
	return children.getValues ();
}
