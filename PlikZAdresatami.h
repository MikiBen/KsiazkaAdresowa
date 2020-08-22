
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

    //string nazwaPlikuZAdresatami;

    //bool czyPlikJestPusty(fstream &plikTekstowy);
    Adresat adresat;
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
public:
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    vector <Adresat> wczytajAdresatowWszystkichUzytkownikowZPliku();
    void dopiszAdresataDoPliku(Adresat adresat);
   // PlikZAdresatami();

    PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
   // PlikZAdresatami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    /*PlikZUzytkownikami(string nazwa):nazwaPlikuZUzytkownikami(nazwa){};

    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);
    */
};

#endif
