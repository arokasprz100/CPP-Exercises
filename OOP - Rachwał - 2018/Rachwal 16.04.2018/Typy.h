#ifndef Typy_h
#define Typy_h

class ObiektMiotajacy;


#include <iostream>

class typ
{
public:
	ObiektMiotajacy* rzucajacy;

};


class typ3 : public typ
{
public:
	void PrzedstawSie() const { std::cout<<"Nazywam sie 3"<<std::endl; }
};

class typ1 : public typ3
{
public:
	void PrzedstawSie() const { std::cout<<"Nazywam sie 1"<<std::endl; }

};



class typ4 : public typ
{
public:
	void PrzedstawSie() const { std::cout<<"Nazywam sie 4"<<std::endl; }

};

class typ2 : public typ4
{
public:
	void PrzedstawSie() const { std::cout<<"Nazywam sie 2"<<std::endl; }

};

#endif