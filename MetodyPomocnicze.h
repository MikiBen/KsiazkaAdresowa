#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>


#include "Uzytkownik.h"
#include "Adresat.h"

using namespace std;

class MetodyPomocnicze
{
    public:
    static string konwerjsaIntNaString(int liczba);
   static string wczytajLinie();
   //Adresat adresat;


    static char wybierzOpcjeZMenuUzytkownika();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);

    static int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    static int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    static int wczytajLiczbeCalkowita();
    static char wybierzOpcjeZMenuEdycja();
    static string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    static void wyswietlDaneAdresata(Adresat adresat);
    static void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    private:
    static char wczytajZnak();
    static int konwersjaStringNaInt(string liczba);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
//MetodyPomocnicze::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
};





#endif

