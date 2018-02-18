#ifndef Student_h
#define Student_h

///Struktura przechowujaca studenta
struct Student
{
    char f_name_init; //Pierwsza litera imienia studenta
    char s_name_init; //Pierwsza litera nazwiska studenta
    int grade; // Ocena studenta
    Student* next; //Wskaznik na skojarzona ze studentem liste innych studentow

};

///Funkcja ustawiajaca parametry studenta: inicjaly jego imienia i nazwiska
///wartosc oceny oraz ustawiajaca wskaznik na nastepnego studenta na NULL
///Pierwsze dwa argumenty to inicjaly, trzeci to ocena (wartosc typu int),
///czwarty to wskaznik na utworzony wczesniej (!) obiekt typu Student
void set_student (const char fln, const char sln, int gr, Student* st);

///Funkcja wypisuj¹ca parametry studenta na standardowe wyjscie
///Przyjmuje referencje na Studenta
///Format wypisywania na przykladzie:
///Initials: M. S. 	grade: 5
void print (Student& st);

///Funkcja dodajaca do listy danego studenta innych studentow
///Jest to zrealizowane za pomoca listy laczonej
///Kazdy student przekazany do tej funkcji zostaje skopiowany
/// - tworzony jest nowy obiekt z danymi za pomoca malloc()
///Pamiec zajeta przez ta funkcje musi byc zwolniona przez
///funkcje clear_all()
///Pierwszym argumentem jest student bedacy poczatkiem listy
///(wskaznik na niego, kolejny to wskaznik na dodawanego studenta)
void attach_back (Student* st1, Student* st2);

///Funkcja wypisuje liste studentow zaczepionych do danego argumentem studenta
///Przyjmuje wskaznik na studenta bedacego poczatkiem listy
void print_all(Student* first);

///Funckja uzywajaca free() do wyczyszczenia listy studentow przypietej
///do podanego jako argument studenta
///Funkcja przyjmuje wskaznik na obiekt typu Student
///Funkcja ta powinna byc wywolana po attach_back()
void clear_all(Student* first);


#endif // Student_h
