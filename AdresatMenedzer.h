#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H


#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Adresat.h"
#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"
#include "PlikZAdresatami.h"
#include "MetodyPomocnicze.h"
//#include "UzytkownicyMenedzer.h"

using namespace std;
class AdresatMenedzer
{
    int idOstatniegoAdresata;
    //int idZalogowanegoUzytkownika;
    //UzytkownikMenedzer uzytkownikMenedzer;
    vector <Adresat> adresaci;
    vector <Adresat> adresaciWszyscy;

    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);

    void wypisanieAdresata(int i);
    //void nadpisywaniePlikuPoUsunieciu(int idAdresataDoZmiany);

    PlikZAdresatami plikZAdresatami;
    int podajIdWybranegoAdresata();

    void zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata);

public:
    AdresatMenedzer(string nazwaPlikuZ): plikZAdresatami(nazwaPlikuZ)
    {

    };
    void usuniecieAdresata();
    void pobierzIdOstatniegoAdresat();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wczytajAdresatowWszystkichUzytkownikowZPliku();
    void wyswietlWszystkichAdresatow(int idZalogowanegoUzytkownika);
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void edytujAdresata();
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();

};

#endif
