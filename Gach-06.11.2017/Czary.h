#ifndef Czary_h
#define Czary_h

typedef char* Czary;

void UtworzCzar (const char *nazwaCzaru, Czary* poczatekCzaru, Czary* koniecCzaru);
void RzucCzar (Czary poczatekCzaru, Czary koniecCzaru);

struct PomocniczaKsiegaCzarow
{
    Czary _poczatekCzaru;
    Czary _koniecCzaru;
    PomocniczaKsiegaCzarow* _nastepnyCzar;
};

typedef PomocniczaKsiegaCzarow* KsiegaCzarow;

void DodajCzar(KsiegaCzarow* ksiega , Czary poczatekCzaru, Czary koniecCzaru);

void Czytaj(KsiegaCzarow* ksiega);

void SpalKsiege(KsiegaCzarow ksiega);

void ZniszczCzar(Czary poczatekCzaru, Czary koniecCzaru);

#endif // Czary_h
