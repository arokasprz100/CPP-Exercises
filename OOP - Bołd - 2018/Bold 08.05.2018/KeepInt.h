#ifndef KeepInt_h
#define KeepInt_h

class KeepInt
{
public:
	KeepInt(int& intToKeep) 
		: m_intToKeep(intToKeep), m_startingValue(intToKeep) {}

	void Restore();

	~KeepInt();
	
private:
	int& m_intToKeep;
	int m_startingValue;

};

#endif