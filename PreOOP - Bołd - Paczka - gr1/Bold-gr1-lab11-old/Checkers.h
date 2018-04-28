#ifndef Checkers_h
#define Checkers_h

#include <string>
#include <cctype>

class Checker
{
public:
	Checker (std::string name):
		m_checkerName(name) {}

	std::string getName() const {return m_checkerName;}

	virtual bool checkCondition(std::string toCheck){ return false;}

	virtual Checker * clone() const {return new Checker(*this);}

	virtual ~Checker() {}

protected:
	std::string m_checkerName;

};


class capitalLetter : public Checker
{
public:
	capitalLetter():
		Checker("CapitalLetter()") {}

	bool checkCondition(std::string toCheck);

	virtual Checker * clone() const {return new capitalLetter(*this);}

};


class letter : public Checker
{
public:
	letter(char letterCondition):
		Checker(std::string("Letter(")+ letterCondition+ std::string(")")), m_letterCondition(letterCondition) {}

	bool checkCondition(std::string toCheck);

	virtual Checker * clone() const {return new letter(*this);}

private:
	char m_letterCondition;
};


class letterFromRange : public Checker
{
public:
	letterFromRange(char rangeStart, char rangeEnd):
		Checker(std::string("InRange(")+rangeStart + std::string(",") + rangeEnd + std::string(")")), m_rangeStart(rangeStart), m_rangeEnd(rangeEnd) {}

	bool checkCondition(std::string toCheck);

	virtual Checker * clone() const {return new letterFromRange(*this);}

private:
	char m_rangeStart;
	char m_rangeEnd;

};


class anythingUntilLetter : public Checker
{
public:
	anythingUntilLetter(char letterCondition):
		Checker(std::string("UntilLetter(") + letterCondition + std::string(")")), m_letterCondition(letterCondition) {}

	bool checkCondition(std::string toCheck);

	virtual Checker * clone() const {return new anythingUntilLetter(*this);}

private:
	char m_letterCondition;
};

#endif