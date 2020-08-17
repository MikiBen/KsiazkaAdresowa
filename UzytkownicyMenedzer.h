#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H


#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"

using namespace std;
class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    vector <Uzytkownik> uzytkownicy;
    vector <Adresat> adresaci;
   // Adresat adresat;


    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);
    PlikZUzytkownikami plikZUzytkownikami;
    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void pobierzIdOstatniegoAdresat();
    void wyswietlWszystkichAdresatow();

    //void dopiszAdresataDoPliku(dopiszAdresataDoPliku);

public:

    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami): plikZUzytkownikami(nazwaPlikuZUzytkownikami){
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
    };
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkonikow();

    //void wczytajUzytkownikowZPliku();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();

    void wylogowanieSieUzytkownika();
    void panelZAdresatami();


    void dodajAdresata();

};

#endif
