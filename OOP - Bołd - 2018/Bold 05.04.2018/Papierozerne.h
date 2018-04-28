#ifndef Papierozerne_h
#define Papierozerne_h

/// Klasa reprezentujaca urzadzenie zuzywajace papier
/// Sluzy jako klasa bazowa dla kilku urzadzen
/// Pomimo ze nie zostaly tu zaimplementowane zadne
/// mechanizmy zapobiegajace temu, tworzenie instanci
/// tej klasy nie ma sensu
class Papierozerne
{
public:
	/// Wirtualny destruktor, nie robi nic. Pojawia sie ze 
	/// wzgledu na delete w pliku main oraz dynamic_cast
	virtual ~Papierozerne() {}
};

#endif