#include "Text.h"
#include "DLinkedList.h"
#include <sstream> 
#include <fstream>
#include <algorithm>
#include <stdexcept>

void Text::parseFile (std::string fileName) throw (std::runtime_error) {
	std::string line, word;
	std::fstream stream;
	int lineCount = 1;
	stream.open (fileName);
	if (!stream.is_open ())
		throw std::runtime_error ("Archivo no se pudo abrir o no existe.");

	while (std::getline (stream, line)) {
		if(!line.empty())
			lines->insert (lineCount, line);
		lineCount++;
	}

	stream.close ();
}

std::string Text::cleanWord (std::string word) {
	auto notLetter = [] (char x) {
		return ispunct ((unsigned char) x);
	};

	std::string temp = word;
	temp.erase (std::remove_if (temp.begin (), temp.end (), notLetter), temp.end ());
	return temp;
}

Text::Text (std::string fileName) {
	lines = new BSTDictionary<int, std::string> ();
	Text::parseFile (fileName);
}

Text::~Text () {
	delete lines;
}

std::string Text::getLine (int line) {
	return lines->getValue (line);
}

List< KVPair<int, std::string> >* Text::getWords () {
	List< KVPair<int, std::string> > *words = new DLinkedList< KVPair<int, std::string> > ();
	List<int>* lines = this->lines->getKeys ();
	for (lines->goToStart (); !lines->atEnd (); lines->next ()) {
		std::stringstream stream (getLine (lines->getElement ()));
		std::string word;
		while (std::getline (stream, word, ' ')) {
			KVPair<int, std::string> p (lines->getElement (), cleanWord (word));
			words->append (p);
		}
	}
	delete lines;
	return words;
}

