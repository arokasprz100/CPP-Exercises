#ifndef Data_h
#define Data_h

#include <string>
#include <iostream>

class Data
{
public:
	Data() : m_next(nullptr) {}
	virtual ~Data() {};

	virtual std::string getData() = 0;
	virtual Data* clone() const = 0;
	virtual bool compare(const Data* compared) = 0;

	void deleteData();

	Data * m_next;
};


class IntData : public Data
{
public:
	IntData (int data) : m_data(data) {}
	virtual ~IntData() {std::cout<<"~IntData"<<std::endl; }

	virtual std::string getData() { return std::to_string(m_data); }
	virtual IntData* clone() const { return new IntData(*this); }
	virtual bool compare(const Data* compared);

private:
	int m_data;
};


class StringData : public Data
{
public:
	StringData(std::string data) : m_data(data) {}
	virtual ~StringData() {std::cout<<"~StringData"<<std::endl;}

	virtual std::string getData() {return m_data;}
	virtual StringData* clone() const {return new StringData(*this);}
	virtual bool compare(const Data* compared);

private:
	std::string m_data;
};


class FloatData : public Data 
{
public:
	FloatData(float data) : m_data(data) {}
	virtual ~FloatData() {std::cout<<"~FloatData"<<std::endl;}

	virtual std::string getData() {return std::to_string(m_data);}
	virtual FloatData* clone() const {return new FloatData(*this);}
	virtual bool compare(const Data* compared);

private:
	float m_data;
};


#endif