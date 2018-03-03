#ifndef Fraction_h
#define Fraction_h

class Fraction 
{
public:
	Fraction (int numerator, int denominator);
	void Print() const;
	Fraction Add(const Fraction& added) const;

private:
	int m_numerator;
	int m_denominator;
	int m_integerPart;

};

#endif