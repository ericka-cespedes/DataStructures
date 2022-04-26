/**	
	Clase: Text
	Autor: Sara Castro Sáenz

	Esta clase abre y procesa linea por linea un archivo de texto, si no puede abrirlo despliega un mensaje de error.
	Las lineas de texto se guardan en un diccionario junto con el número de linea. 
	La case retorna la linea de texto que se le especifique o una lista con todas las palabras del texto sin signos de puntuación. 

*/

#ifndef TEXT_H
#define TEXT_H
#include <string>
#include "List.h"
#include "BSTDictionary.h"
#include "KVPair.h"

class Text {
private:
	BSTDictionary<int, std::string> *lines;
	void parseFile (std::string fileName);
	std::string cleanWord (std::string word);

public:
	Text (std::string fileName);
	~Text ();
	std::string getLine (int line);
	List< KVPair<int, std::string> >* getWords ();
};

#endif // TEXT_H


