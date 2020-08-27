#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkonikow()

{
    uzytkownikMenedzer.wypiszWszystkichUzytkonikow();
}

void KsiazkaAdresowa::logowanieUzytkownika()
{
    uzytkownikMenedzer.logowanieUzytkownika();
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer = new AdresatMenedzer(NAZWA_PLIKU_Z_ADRESATAMI,uzytkownikMenedzer.pobierzIdZalogowanegoUzytkownika());
        panelZAdresatami();
    }
}

void KsiazkaAdresowa::dodajAdresata()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer->dodajAdresata();
    }
    else
    {
        cout<< "Musisz sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika()
{
    uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wylogowanieSieUzytkownika()
{
    uzytkownikMenedzer.wylogowanieSieUzytkownika();
    delete adresatMenedzer;
    adresatMenedzer = NULL;
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer->wyswietlWszystkichAdresatow();
    }
    else
    {
        cout<< "Musisz sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyszukajAdresatowPoImieniu()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer->wyszukajAdresatowPoImieniu();
    }
    else
    {
        cout<< "Musisz sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::wyszukajAdresatowPoNazwisku()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer->wyszukajAdresatowPoNazwisku();
    }
    else
    {
        cout<< "Musisz sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::usuniecieAdresata()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer->usuniecieAdresata();
    }
    else
    {
        cout<< "Musisz sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::edytujAdresata()
{
    if(uzytkownikMenedzer.czyUzytkownikJestZalogowany())
    {
        adresatMenedzer->edytujAdresata();
    }
    else
    {
        cout<< "Musisz sie zalogowac" << endl;
        system("pause");
    }
}

void KsiazkaAdresowa::panelZAdresatami()
{
    char wybor;
    while(true)
    {
        wybor = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();
        switch (wybor)
        {
        case '1':
            dodajAdresata();
            break;
        case '2':
            wyszukajAdresatowPoImieniu();
            break;
        case '3':
            wyszukajAdresatowPoNazwisku();
            break;
        case '4':
            wyswietlWszystkichAdresatow();
            break;
        case '5':
            usuniecieAdresata();
            break;
        case '6':
            edytujAdresata();
            break;
        case '7':
            zmianaHaslaZalogowanegoUzytkownika();
            break;
        case '8':
            wylogowanieSieUzytkownika();
            return;
        }
    }

}
