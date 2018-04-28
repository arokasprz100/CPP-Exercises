#ifndef Drukarka_h
#define Drukarka_h

#include "Papierozerne.h"
#include "Rozdzielczosc.h"

/// Klasa reprezentujaca drukarke, czyli rzeczywiste
/// urzadzenie pobierajace papier - dlatego dziedziczy po
/// Papierozerne (oraz bo dynamic_cast ma zwrocic poprawny wskaznik)
/// Mamy dziedziczenie wirtualne, bo po Drukarce oraz innym urzadzeniu
/// pochodnym do Papierozerne dziedziczy OfficeMultiTool - nie chcemy
/// miec wiec kilku bazowych instancji klasy Papierozerne, tylko jedna.
/// Klasa Drukarka zawiera w sobie obiekt klasy rozdzielczosc, poniewaz
/// drukarka jest urzadzniem posiadajacym rozdzielczosc (linia 25 w pliku main)
class Drukarka : public virtual Papierozerne
{
public:
	/// Konstruktor, ustawia rozdzielczosc drukaki, poza tym nie robi nic
	Drukarka(Rozdzielczosc rozdzielczoscDrukarki):
		m_rozdzielczoscDrukarki(rozdzielczoscDrukarki) {}

	/// Prosta metoda zwracajaca rozdzielczosc drukarki (getter)
	/// Zapewnia, ze obiekt nie zostanie zmodyfikowany
	const Rozdzielczosc& rozdzielczosc() const {return m_rozdzielczoscDrukarki;}

	/// Wirtialny destruktor, nie robi nic
	virtual ~Drukarka() {}

private:
	/// Rozdzielczosc drukarki
	Rozdzielczosc m_rozdzielczoscDrukarki;
};

#endif