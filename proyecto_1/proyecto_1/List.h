/**
	Clase: List
	Autor: Mauricio Avil�s

	Clase abstracta gen�rica en la que se defininen los metodos con los que se opera sobre la lista
	que deben ser implementados en las clases que hereden de esta.

*/

#ifndef LIST_H
#define LIST_H
#include <iostream>

template <typename E>
class List {
private:
	void operator =(const List&) {}
	List (const List& obj) {}

public:
	List () {}
	virtual ~List () {}
	virtual void insert (E element) = 0;
	virtual void append (E element) = 0;
	virtual E remove () = 0;
	virtual void clear () = 0;
	virtual E getElement () = 0;
	virtual void goToStart () = 0;
	virtual void goToEnd () = 0;
	virtual void goToPos (int pos) = 0;
	virtual void next () = 0;
	virtual bool atEnd () = 0;
	virtual void previous () = 0;
	virtual bool atStart () = 0;
	virtual int getPos () = 0;
	virtual int getSize () = 0;
};

#endif // LIST_H
