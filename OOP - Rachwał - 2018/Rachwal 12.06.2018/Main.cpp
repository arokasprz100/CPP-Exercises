// Nazwa pliku wykonywalnego: Ksztalty

// Prosze dopisac kod, dodac nowe pliki, tak aby program wykonywal
// sie, a wynik jego dzialania byl taki sam jak podany na końcu tego
// pliku.
//
// Dziedziczenie szablonów można też wykorzystać do przydatnej sztuczki,
// zwanej po angielsku "couriously reccuring template pattern". 

// Proszę zaimplementować mechanizm automatycznego liczenia ilości 
// obiektów danej klasy. 
// Uwaga: To standardowe zadanie na zastosowanie konstruktorów, destruktorów 
// i statycznych składowych klasy. Ale, mechanizm ten proszę uzyskać z wykorzystaniem
// dziedziczenia szablonów.

// UWAGA: Przed rozpoczeciem pisania prosze przeczytac zadanie do konca.
// UWAGA: W tym zadaniu: PI to 3.1415. Wzor na pole trojkata: sqrt( x(x-a)(x-b)(x-c) ) 
// gdzie "x" to polowa obwodu trojkata.

// Glownym celem zadania jest napisanie kilku klas zwiazanych relacja
// dziedziczenia.  Klasy te opisuja elementarne ksztalty. Kazdy ksztalt
// posiada jakies polimorficzne metody i konieczna infrastrukture.
// Istotna cechą hierarchii klas jest polimorficzne zachowanie operatora <<

// Pliku Main.cpp, nie wolno modyfikowac.
// Ostateczny program powinien byc przyjazny dla programisty 
// (miec czytelny i dobrze napisany kod). 

// Program nalezy kompilowac z flagami -Wall -g.

// Makefile powinien zawierac rowniez cel "clean", ktory usuwa pliki
// obiektowe i plik wykonywalny.

// Przy wykonaniu zadania nie wolno korzystac z internetu, notatek,
// ani zadnych innych materialow (w tym wlasnych wczesniej
// przygotowanych plikow oprocz makefile)

// Rozwiazanie (czyli dodane pliki, makefile i Main.cpp) nalezy
// wgrac do UPEL.

#include <iostream>
#include "Main.h"


int main() {

  Kwadrat kw(4);
  Trojkat tr(3,2,4);
  const Kolo ko(3);

  const Ksztalt* wszystkie[4] = {&kw,&ko, &tr};

  std::cout<< "Ksztalt:\n" << wszystkie[0] << std::endl;
  std::cout<< "Ksztalty:\n" << wszystkie << std::endl;

  wszystkie[3] = new Kwadrat(7);

  std::cout<< "#Ksztalty: " << Ksztalt::N() << std::endl;
  delete wszystkie[3];
  
  for ( unsigned idx = 0; idx < Ksztalt::N(); ++idx ) {
     std::cout << wszystkie[idx] << "  pole powierzchni " << wszystkie[idx]->polePow() << std::endl;
  }  
}
/* wynik
Ksztalt:
Kwadrat o boku: 4

Ksztalty:
Kwadrat o boku: 4
Kolo o promieniu: 3
Trojkat bokach: 3 2 4

#Ksztalty: 4
Kwadrat o boku: 4
  pole powierzchni 16
Kolo o promieniu: 3
  pole powierzchni 9.4245
Trojkat bokach: 3 2 4
  pole powierzchni 2.90474
 */
