
#ifndef PLIKZUZYTKOWNIKAMI_H
#define PLIKZUZYTKOWNIKAMI_H

#include <iostream>
#include <vector>
#include <fstream>


#include "Uzytkownik.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZUzytkownikami
{
//fstream plikTekstowy;
    const string nazwaPlikuZUzytkownikami;
    //string daneJednegoUzytkownikaOddzielonePionowymiKreskami;
    //vector <Uzytkownik> uzytkownik; ///Czy OK???

    bool czyPlikJestPusty();
    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    Uzytkownik pobierzDaneUzytkownika(string daneJednegoUzytkownikaOddzielonePionowymiKreskami);

public:
    PlikZUzytkownikami(string nazwa):nazwaPlikuZUzytkownikami(nazwa){};

    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    vector <Uzytkownik> wczytajUzytkownikowZPliku();
    void zapiszWszystkichUzytkownikowDoPliku(Uzytkownik uzytkownicy);

//vector <Uzytkownik> uzytkownik; ///Czy OK???
};

#endif
