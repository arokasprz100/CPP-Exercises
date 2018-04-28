#ifndef Obserwator_h
#define Obserwator_h

class Obserwator
{
public:
	virtual void aktualizujDane(int dane) = 0;
};


class ObserwatorLicznik : public Obserwator
{
public:
	ObserwatorLicznik():
		m_suma(0) {}

	virtual void aktualizujDane(int dane);

	inline int suma() const {return m_suma;}

private:
	int m_suma;
};


class ObserwatorWypisywacz : public Obserwator
{
public:
	virtual void aktualizujDane(int dane);
};

#endif