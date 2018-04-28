#include "Czary.h"
#include <cstdlib>
#include <iostream>


void UtworzCzar (const char*  nazwaCzaru, Czary* poczatekCzaru, Czary* koniecCzaru)
{
    int dlugoscCzaru=0;
    while (nazwaCzaru[dlugoscCzaru]!='\0')
        dlugoscCzaru++;
    (*poczatekCzaru)=(Czary)malloc(dlugoscCzaru*sizeof(char)+1);
    for (int i=0; i<dlugoscCzaru; i++)
        (*poczatekCzaru)[i]=nazwaCzaru[i];
    (*poczatekCzaru)[dlugoscCzaru]='\0';
    (*koniecCzaru)=&((*poczatekCzaru)[dlugoscCzaru]);
}

void RzucCzar (Czary poczatekCzaru, Czary koniecCzaru)
{
    using namespace std;
    int i=0;
    while (&poczatekCzaru[i]!=&(*koniecCzaru))
    {
        cout<<poczatekCzaru[i];
        i++;

    }
    cout<<endl;
}

void DodajCzar(KsiegaCzarow* ksiega , Czary poczatekCzaru, Czary koniecCzaru)
{
    if ((*ksiega)==0)
    {
        (*ksiega)=(PomocniczaKsiegaCzarow*)malloc(sizeof(PomocniczaKsiegaCzarow));
        (*ksiega)->_poczatekCzaru=poczatekCzaru;
        (*ksiega)->_koniecCzaru=koniecCzaru;
        (*ksiega)->_nastepnyCzar=0;
        return;
    }
    KsiegaCzarow temp=(*ksiega);
    while (temp->_nastepnyCzar!=0)
        temp=temp->_nastepnyCzar;
    temp->_nastepnyCzar=(PomocniczaKsiegaCzarow*)malloc(sizeof(PomocniczaKsiegaCzarow));
    temp=temp->_nastepnyCzar;
    temp->_poczatekCzaru=poczatekCzaru;
    temp->_koniecCzaru=koniecCzaru;
    temp->_nastepnyCzar=0;


}


void Czytaj(KsiegaCzarow* ksiega)
{
    using namespace std;
    KsiegaCzarow temp=(*ksiega);
    cout<<"KSIEGA CZAROW"<<endl;
    while (temp!=0)
    {
        cout<<temp->_poczatekCzaru<<endl<<endl;
        temp=temp->_nastepnyCzar;

    }
}

void SpalKsiege(KsiegaCzarow ksiega)
{
    KsiegaCzarow temp=ksiega;
    while (ksiega!=0)
    {
        temp=ksiega->_nastepnyCzar;
        free (ksiega);
        ksiega=temp;

    }

}

void ZniszczCzar(Czary poczatekCzaru, Czary koniecCzaru)
{
    free (poczatekCzaru);
    koniecCzaru=0;
    poczatekCzaru=0;

}
