#ifndef LicznikInstancji_h
#define LicznikInstancji_h

/*
 * Szablon klasy reprezentujacej licznik instancji obiektu. Aby uzywac tego licznika nalezy
 * podziedziczyc po konkretyzacji tego szablonu dla typu, ktorego instancje chcemy liczyc.
 * Przyklad: mamy klase A i chcemy liczyc ile w danym momencie jest obiektow tej klasy - 
 * robimy wiec tak: class A : public LicznikInstancji<A> { -- implementacja klasy -- };
 * Jest to realizacja wzorca CRTP. Ponizszy szablon produkuje klasy abstrakcyjne z uwagi na
 * to, ze jego destruktor jest czysto wirtualny.
 * Uwaga: z uwagi na fakt implementacji licznika za pomoca pola statycznego, istnieje mozliwosc
 * liczenia instancji tylko jednej klasy (i jej pochodnych) na raz.
 */
template <typename T>
class LicznikInstancji
{
public:
	/*
	 * Konstruktor bezargumentowy. Wywoluje sie, gdy powstaje obiekt dziedziczacy po
	 * liczniku. Jego implementacja zwieksza liczbe instancji.
	 */
	LicznikInstancji() { ++m_liczbaInstancji; }

	/*
	 * Czysto wirtualny destruktor - wywoluje sie w momencie niszczenia obiektu klasy dziedziczacej
	 * po konkretyzacji tego szablonu. Zawiera implementacje zmniejszajaca licznik o 1 za kazdym 
	 * zniszczonym obiektem.
	 */ 
	virtual ~LicznikInstancji()  = 0; 

	/*
	 * Statyczna metoda zwracajaca liczbe instancji liczonej klasy. 
	 */
	static const unsigned dajLiczbeInstancji() { return m_liczbaInstancji; }


private:
	/*
	 * Statyczne pole reprezentujace liczbe instancji liczonej klasy. Na poczatku ustawiane na 0.
	 */
	static unsigned m_liczbaInstancji;
};

/// Inicjalizowanie i implementacje: 

template <typename T>
unsigned LicznikInstancji<T>::m_liczbaInstancji = 0;

template <typename T>
LicznikInstancji<T>::~LicznikInstancji() { --m_liczbaInstancji; }


#endif