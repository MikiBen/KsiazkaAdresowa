
#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{

    string nazwaPlikuZAdresatami;

    bool czyPlikJestPusty();
    Adresat adresat;
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
public:
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);
    PlikZAdresatami();
    /*PlikZUzytkownikami(string nazwa):nazwaPlikuZUzytkownikami(nazwa){};

    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
    */
};

#endif
