
#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>


#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"
#include "PlikTekstowy.h"
using namespace std;

class PlikZUzytkownikami :public PlikTekstowy
{

    //const string NAZWA_PLIKU_Z_UZYTKOWNIKAMI;


    //bool czyPlikJestPusty(fstream &plikTekstowy);
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
   // PlikZUzytkownikami(string nazwa):NAZWA_PLIKU_Z_UZYTKOWNIKAMI(nazwa){};
    PlikZUzytkownikami(string nazwaPliku) : PlikTekstowy(nazwaPliku) {};
    //likZAdresatami(string nazwa) : PlikTekstowy(nazwa) {};

    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(vector <Uzytkownik> uzytkownicy);

};

#endif
