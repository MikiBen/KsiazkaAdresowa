#ifndef METODYPOMOCNICZE_H
#define METODYPOMOCNICZE_H

#include <iostream>


#include "Uzytkownik.h"


using namespace std;

class MetodyPomocnicze
{
    public:
    static string konwerjsaIntNaString(int liczba);
   static string wczytajLinie();


    static char wybierzOpcjeZMenuUzytkownika();
    private:
    static char wczytajZnak();


};





#endif

