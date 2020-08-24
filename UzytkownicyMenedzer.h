#ifndef UZYTKOWNIKMENEDZER_H
#define UZYTKOWNIKMENEDZER_H


#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

//#include "Adresat.h"

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "AdresatMenedzer.h"
//#include "PlikZAdresatami.h"

using namespace std;
class UzytkownikMenedzer
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

    // Adresat podajDaneNowegoAdresata();
    //void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
//void pobierzIdOstatniegoAdresat();
    // void wyswietlWszystkichAdresatow();
    //void wczytajAdresatowWszystkichUzytkownikowZPliku();


    PlikZUzytkownikami plikZUzytkownikami;
    AdresatMenedzer adresatMenedzer;
    void panelZAdresatami();

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami ): plikZUzytkownikami(nazwaPlikuZUzytkownikami),adresatMenedzer(nazwaPlikuZAdresatami)
    //UzytkownikMenedzer(string nazwaPlikuZUzytkownikami): plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {

        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();

    };
    void zmianaHaslaZalogowanegoUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkonikow();
    void logowanieUzytkownika();
    void wylogowanieSieUzytkownika();
    //int pobierzIdZalogowanegoUzytkownika();


};

#endif
