#ifndef Verifier_h
#define Verifier_h

#include <string>
#include <iostream>

class ArgVerificationFailed
{
public:
	ArgVerificationFailed (std::string message) :
		m_message(message) {}

	friend std::ostream& operator << (std::ostream& stream, const ArgVerificationFailed& toPrint);

private:
	std::string m_message;
};


class is
{
public:
	is (int number):
		m_number(number) {}

	bool operator > (const int rhs);

	bool operator >= (const int rhs);

	bool operator < (const int rhs);

	bool operator <= (const int rhs);

private:
	int m_number;

};



#define SECURED(x) std::string a = x; try{

#define ENDSECURED } catch(ArgVerificationFailed& e){std::cout<<"ArgVerificationFailed in " <<a<<" " << e <<std::endl;}


#endif