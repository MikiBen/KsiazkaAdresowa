
#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H
/*
#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy
{
    const string NAZWA_PLIKU;
    public:
    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {
    }

    string pobierzNazwePliku();
    bool czyPlikJestPusty();

};
*/

#include <iostream>
#include <fstream>

using namespace std;

class PlikTekstowy {

     string NAZWA_PLIKU;

public:

    PlikTekstowy(string nazwaPliku) : NAZWA_PLIKU(nazwaPliku) {
    }

    string pobierzNazwePliku()
    {
        return NAZWA_PLIKU;
    }

    bool czyPlikJestPusty()
    {
        bool pusty = true;
        fstream plikTekstowy;
        plikTekstowy.open(pobierzNazwePliku().c_str(), ios::app);

        if (plikTekstowy.good() == true)
        {
            plikTekstowy.seekg(0, ios::end);
            if (plikTekstowy.tellg() != 0)
                pusty = false;
        }

        plikTekstowy.close();
        return pusty;
    }
};


#endif
