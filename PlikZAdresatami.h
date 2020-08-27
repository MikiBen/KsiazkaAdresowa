#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"
using namespace std;

class PlikZAdresatami :public PlikTekstowy
{
    int idOstatniegoAdresata;
    vector <Adresat> adresaciWszyscy;
    Adresat adresat;
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);

public:
    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    vector <Adresat> wczytajAdresatowWszystkichUzytkownikowZPliku();
    void dopiszAdresataDoPliku(Adresat adresat);
    void nadpisywaniePlikuPoUsunieciu(int idAdresataDoZmiany);

    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);
    int pobierzIdOstatniegoAdresata();
};

#endif
