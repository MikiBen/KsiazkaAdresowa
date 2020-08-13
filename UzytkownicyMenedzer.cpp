#include "UzytkownicyMenedzer.h"


void UzytkownikMenedzer::wczytajUzytkownikowZPliku()
{
    uzytkownicy = plikZUzytkownikami.wczytajUzytkownikowZPliku();
}

void UzytkownikMenedzer::wylogowanieSieUzytkownika()
{
    idZalogowanegoUzytkownika=0;
}


void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
        //Uzytkownik uzytkownik;
   //uzytkownik = uzytkownicy;
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzId() == idZalogowanegoUzytkownika)
        {
             uzytkownicy[i].ustawHaslo(noweHaslo);
            //uzytkownicy[i].pobierzId() noweHaslo;
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }

   plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
    //plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

       // stworzyc ta funkcje w uzytkoniwk menedzer
}


void UzytkownikMenedzer::logowanieUzytkownika()
{
        //Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    login = MetodyPomocnicze::wczytajLinie();

   // vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

                if (uzytkownicy[i].pobierzHaslo() == haslo)
                {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    system("pause");
UzytkownikMenedzer::panelZAdresatami();
                    //adresaci.panelZAdresatami();
                    return;

                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return;
        }

    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}



void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);

    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    //uzytkownik.id = pobierzIdNowegoUzytkownika();
    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());
    string login,haslo;
    do
    {
        cout << "Podaj login: ";
        //uzytkownik.login = wczytajLinie();
        cin>>login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    cout << "Podaj haslo: ";
    //uzytkownik.haslo = wczytajLinie();
    cin>>haslo;
    uzytkownik.ustawHaslo(haslo);
    return uzytkownik;
}

int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }

    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkonikow()
{
        for (int i=0; i<uzytkownicy.size(); i++)
    {
        cout<<uzytkownicy[i].pobierzId()<<endl;
        cout<<uzytkownicy[i].pobierzLogin()<<endl;
        cout<<uzytkownicy[i].pobierzHaslo()<<endl;
    }
}

void UzytkownikMenedzer::panelZAdresatami()
{
        char wybor;
        while(true)
        {
                wybor = MetodyPomocnicze::wybierzOpcjeZMenuUzytkownika();
                    switch (wybor)
            {
            case '1':
                //idOstatniegoAdresata = dodajAdresata(adresaci, idZalogowanegoUzytkownika, idOstatniegoAdresata);
                break;
            case '2':
                //wyszukajAdresatowPoImieniu(adresaci);
                break;
            case '3':
               // wyszukajAdresatowPoNazwisku(adresaci);
                break;
            case '4':
               // wyswietlWszystkichAdresatow(adresaci);
                break;
            case '5':
               // idUsunietegoAdresata = usunAdresata(adresaci);
               // idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
                break;
            case '6':
                //edytujAdresata(adresaci);
                break;
            case '7':
                 UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika();
                break;
            case '8':
                UzytkownikMenedzer::wylogowanieSieUzytkownika();
               // adresaci.clear();
                return;
            }
        }

}


