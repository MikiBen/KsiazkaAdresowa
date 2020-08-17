#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H

#include <iostream>

#include "UzytkownicyMenedzer.h"


using namespace std;

class KsiazkaAdresowa
{
    UzytkownikMenedzer uzytkownikMenedzer;
   // int idZalogowanegoUzytkownika;
public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami): uzytkownikMenedzer(nazwaPlikuZUzytkownikami){

    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkonikow();
    void logowanieUzytkownika();

    /*void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieSieUzytkownika();
*/
};
#endif
