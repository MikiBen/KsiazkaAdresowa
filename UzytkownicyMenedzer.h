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
    vector <Adresat> adresaciWszyscy;
    // Adresat adresat;



    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

    Adresat podajDaneNowegoAdresata();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void pobierzIdOstatniegoAdresat();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowWszystkichUzytkownikowZPliku();
    //int pobierzIdOstatniegoAdresat
    void usuniecieAdresata();
    void wypisanieAdresata(int i);
    //void dopiszAdresataDoPliku(dopiszAdresataDoPliku);
    void nadpisywaniePlikuPoUsunieciu(int idAdresataDoZmiany);

    PlikZAdresatami plikZAdresatami;
    PlikZUzytkownikami plikZUzytkownikami;
        void zmianaHaslaZalogowanegoUzytkownika();

public:
    UzytkownikMenedzer(string nazwaPlikuZUzytkownikami, string nazwaPlikuZAdresatami ): plikZUzytkownikami(nazwaPlikuZUzytkownikami),plikZAdresatami(nazwaPlikuZAdresatami)
    //UzytkownikMenedzer(string nazwaPlikuZUzytkownikami): plikZUzytkownikami(nazwaPlikuZUzytkownikami)
    {
        // PlikZAdresatami plikZAdresatami ("Adresaci.txt");
        //PlikZUzytkownikami plikZUzytkownikami ("Uzytkownicy.txt")
        uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();

    };

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkonikow();
    void logowanieUzytkownika();


    void wylogowanieSieUzytkownika();
    void panelZAdresatami();


    void dodajAdresata();

};

#endif
