#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

char wczytajZnak()
{
    string wejscie = "";
    char znak  = {0};

    while (true)
    {
        getline(cin, wejscie);

        if (wejscie.length() == 1)
        {
            znak = wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak. Wpisz ponownie." << endl;
    }
    return znak;
}

char wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = wczytajZnak();

    return wybor;
}

int main()
{
    char wybor;
    while (true)
    {
            wybor = wybierzOpcjeZMenuGlownego();
            KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");

            switch (wybor)
            {
            case '1':
                ksiazkaAdresowa.rejestracjaUzytkownika();
                break;
            case '2':
                ksiazkaAdresowa.logowanieUzytkownika();
                break;
            case '9':
                exit(0);
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
                system("pause");
                break;
            }
    }






   // KsiazkaAdresowa ksiazkaAdresowa("Uzytkownicy.txt");
    //ksiazkaAdresowa.wypiszWszystkichUzytkonikow();
   //ksiazkaAdresowa.rejestracjaUzytkownika();
 // ksiazkaAdresowa.rejestracjaUzytkownika();
//ksiazkaAdresowa.wypiszWszystkichUzytkonikow();

   //ksiazkaAdresowa.logowanieUzytkownika();
   //ksiazkaAdresowa.wypiszWszystkichUzytkonikow();

   // ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();

//ksiazkaAdresowa.wypiszWszystkichUzytkonikow();







    return 0;
}

