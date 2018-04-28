/*
 Tematem zadania jest napisanie nazrzedzia pozwalajacego na sledzenie wykonania programu.
 W programie bedziemy mieli mozliwosc "zaznaczenia" miejsca w ktorym wchodzimy w nowy zakres.
 Jesli to zrobimy podczas wykonywania programu powinnismy dostac serie komunikatow pokazujacych w jakie zakresy wchodzimy.

 (UWAGA: prosze nie zmieniac tego pliku nawet odrobine poniewaz numery linni sie zepsuja)
 Implementacja:
 Wszyskie zakresy nalezy przechowywac w globalnej liscie polaczonej.
 Mozna/trzeba wykozystac liste z zadania poprzedniego Person ~= Scope
 (+jedna dodatkowa zmienna to linii)
 i trzeba dodac funkcje print i usunOstatni.

 ENTER_SCOPE to makrodefinicja tworzaca tymczasowa zmienna, jej konstruktor wypelnia
 globalna liste zakresow (dodaje ostatni element), jej destruktor oproznia te liste
 z ostatniego elementu.

 Ilosc kodu do napisania to ok 10 linijek + lista.

 Kompilowac z flagami -Wall -g do pliku stest.

*/
#include <iostream>
#include "scope.h"

void f1() {
  ENTER_SCOPE(__FUNCTION__, __LINE__, "");
  {
      ENTER_SCOPE(__FUNCTION__, __LINE__, "inner_scope");
  }
}


void f2() {
  ENTER_SCOPE(__FUNCTION__, __LINE__, "");
  f1();
}


int main() {
  ENTER_SCOPE(__FUNCTION__, __LINE__, "poczatek");
  f2();
  {
    ENTER_SCOPE(__FUNCTION__, __LINE__,"pierwsza petla");
    for ( int i = 0; i < 10; i++ ) {
      std::cout << " indeks " << i << std::endl;
    }
  }
}
/* wynik
entering :[main:40:poczatek]
entering :[main:40:poczatek][f2:34:]
entering :[main:40:poczatek][f2:34:][f1:26:]
entering :[main:40:poczatek][f2:34:][f1:26:][f1:28:inner_scope]
leaving  :[main:40:poczatek][f2:34:][f1:26:][f1:28:inner_scope]
leaving  :[main:40:poczatek][f2:34:][f1:26:]
leaving  :[main:40:poczatek][f2:34:]
entering :[main:40:poczatek][main:43:pierwsza petla]
 indeks 0
 indeks 1
 indeks 2
 indeks 3
 indeks 4
 indeks 5
 indeks 6
 indeks 7
 indeks 8
 indeks 9
leaving  :[main:40:poczatek][main:43:pierwsza petla]
leaving  :[main:40:poczatek]
 */
