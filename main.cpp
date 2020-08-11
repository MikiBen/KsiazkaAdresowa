#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    int id;

    KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkonikow();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();

    ksiazkaAdresowa.wypiszWszystkichUzytkonikow();
    ksiazkaAdresowa.logowanieUzytkownika();




    return 0;
}

