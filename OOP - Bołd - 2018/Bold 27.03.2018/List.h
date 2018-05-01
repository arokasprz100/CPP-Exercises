#ifndef List_h
#define List_h

#include <iostream>

#include "Data.h"

class List
{
public:
	List() : m_start(nullptr), m_end(nullptr) {}
	List(const List& copied);
	~List();

	List& insert(const Data& toInsert, bool isBegin = false);
	void print();
	bool find(const Data& toFind);

	static bool Begin;
	static bool End;
private:
	void insertBegin(Data* inserted);
	void insertEnd(Data* inserted);


	Data * m_start;
	Data * m_end;
};

#endif