/**	
	Clase: Text
	Autores: Ericka Cespédes, María Fernanda Niño y Sara Castro Sáenz.

	Despliega un menú que le pregunta al usuario el texto que desea procesar. Si el archivo pudo abrirse despliega un menú con las opciones
	para operar sobre el Trie.
	
	Opciones:
		1. Se solicita al usuario un prefijo para buscar. Se imprimen todas las palabras que empiezan con el prefijo 
		y la cantidad de veces que aparece en el texto. 

		2. Se solicita al usuario una palabra para buscar. Si la palabra esta en el árbol, se imprime cada una de las lineas del texto que 
		la contienen. 

		3. Se le solicita un número al usuario y se imprimen todas las palabras que tienen esa cantidad de letra.

		0. Se cierra el programa.


*/

#include <iostream>
#include "Trie.h"
#include <string>
#include <locale>
#include "Text.h"
#include <stdexcept>
#include <stdio.h>
#include <windows.h>
#include <iomanip>

std::string getFileName (std::string fileName);
void printMatchesbyPrefix (std::string prefix);
void printWord (std::string word);
void printMatchesBySize (int size);
void printWelcome ();
Trie trie;
Text *text;

int main () {
	setlocale (LC_ALL, "spanish");
	SetConsoleCP (1252);
	SetConsoleOutputCP (1252);
	std::string fileName;

	printWelcome ();

	std::cout << "Ingrese el nombre del archivo\n";
	std::cin >> fileName;

	try {
		text = new Text (getFileName (fileName));
	} catch (const std::exception &e) {
		std::cout << e.what () << "\n\n";
		system ("pause");
		return 1;
	}

	List< KVPair<int, std::string> >* words = text->getWords ();
	for (words->goToStart (); !words->atEnd (); words->next ())
		trie.insert (words->getElement ());

	delete words;

	char input;
	do {
		do {
			system ("CLS");
			printf ("\n\n\n ====MENU====");
			printf ("\n1. Consultar por prefijo");
			printf ("\n2. Buscar palabra");
			printf ("\n3. Buscar por cantidad de letras");
			printf ("\n0. Salir");
			printf ("\n\nEscoja opción (0 - 3)\n");
			fflush (stdin);
			scanf_s ("%c", &input);
		} while (input < '0' || input > '4');

		std::string prefix;
		int size;

		switch (input) {
			case '1':
				system ("CLS");
				printf ("\n\nIngrese el prefijo: ");
				std::cin >> prefix;
				std::cout << std::endl;
				printMatchesbyPrefix (prefix);
				system ("pause");
				break;
			case '2':
				system ("CLS");
				printf ("\n\nIngrese la palabra: ");
				std::cin >> prefix;
				std::cout << std::endl;
				try {
					printWord (prefix);
				} catch (const std::exception &e) {
					std::cerr << e.what ();
				}
				system ("pause");
				break;
			case '3':
				system ("CLS");
				printf ("\n\nIngrese la cantidad de letras: ");
				std::cin >> size;
				std::cout << std::endl;
				if (std::cin.fail ()) {
					std::cin.clear ();
					std::cin.ignore (300, '\n');
					printf ("\n\nDebe ser un número.\n\n");
				} else
					printMatchesBySize (size);

				system ("pause");
				break;
		}

	} while (input != '0');

	return 0;
}

std::string getFileName (std::string fileName) {
	std::string newFileName = fileName;
	if (fileName.length () >= 4 && fileName.substr (fileName.length () - 4) != ".txt")
		newFileName += ".txt";
	return newFileName;
}

void printMatchesbyPrefix (std::string prefix) {
	List< KVPair<std::string, List<int>*> > *matches = trie.getMatches (prefix);
	for (matches->goToStart (); !matches->atEnd (); matches->next ())
		std::cout << matches->getElement ().getKey () << "\t" << matches->getElement ().getValue ()->getSize () << "\n";
	std::cout << std::endl;
	delete matches;
}

void printMatchesBySize (int size) {
	List<std::string> *list = trie.getSizeMatches (size);
	for (list->goToStart (); !list->atEnd (); list->next ())
		std::cout << list->getElement () << std::endl;
	std::cout << std::endl;
	delete list;
}

void printWord (std::string word) {
	List< KVPair<std::string, List<int>*> > *matches = trie.getMatches (word);
	List<int> *lineNumbers;
	for (matches->goToStart (); !matches->atEnd (); matches->next ()) {
		if (matches->getElement ().getKey () == word) {
			lineNumbers = matches->getElement ().getValue ();
			for (lineNumbers->goToStart (); !lineNumbers->atEnd (); lineNumbers->next ())
				std::cout << lineNumbers->getElement () << "\t" << text->getLine (lineNumbers->getElement ()) << "\n\n";
			std::cout << std::endl;
		}
	}
	delete matches, lineNumbers;
}

void printWelcome () {

	std::cout << std::setw (53) << std::setfill ('*') << " \n\n";
	std::cout << std::setw (3) << std::setfill (' ') << "";
	std::cout << " _       __     __" << std::endl;
	std::cout << std::setw (3) << std::setfill (' ') << "";
	std::cout << "| |     / /__  / /________  ___  ___  ___" << std::endl;
	std::cout << std::setw (3) << std::setfill (' ') << "";
	std::cout << "| | /| / / _ \\/ / ___/ __ \\/ __` __ \\/ _ \\ " << std::endl;
	std::cout << std::setw (3) << std::setfill (' ') << "";
	std::cout << "| |/ |/ /  __/ / /__/ /_/ / / / / / /  __/" << std::endl;
	std::cout << std::setw (3) << std::setfill (' ') << "";
	std::cout << "|__/|__/\\___/_/\\___/\\____/_/ /_/ /_/\\___/" << std::endl;

	std::cout << "\n" << std::setw (53) << std::setfill ('-') << " \n\n"
		<< std::setw (5) << std::setfill (' ') << ""
		<< "Este programa lee un archivo de texto\n"
		<< std::setw (5) << std::setfill (' ') << ""
		<< "y agrega las palabras a un trie para\n"
		<< std::setw (5) << std::setfill (' ') << ""
		<< "realizar consultas como:\n\n"
		<< std::setw (7) << std::setfill (' ') << ""
		<< "1. Consulta por prefijo\n"
		<< std::setw (7) << std::setfill (' ') << ""
		<< "2. Buscar palabra\n"
		<< std::setw (7) << std::setfill (' ') << ""
		<< "3. Buscar por cantidad de letras\n\n\n"
		<< std::setw (50) << std::setfill ('*') << ""
		<< std::endl << std::endl;

	system ("pause");
	system ("CLS");

}


