#include "AdresatMenedzer.h"

void AdresatMenedzer::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}

void AdresatMenedzer::wczytajAdresatowWszystkichUzytkownikowZPliku()
{
    adresaciWszyscy = plikZAdresatami.wczytajAdresatowWszystkichUzytkownikowZPliku();
}

Adresat AdresatMenedzer::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;

    adresat.ustawId( ++idOstatniegoAdresata);
    adresat.ustawIdUzytkownika(idZalogowanegoUzytkownika);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocnicze::wczytajLinie());
    adresat.ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie()));

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocnicze::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko()));

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocnicze::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocnicze::wczytajLinie());

    return adresat;
}



void AdresatMenedzer::pobierzIdOstatniegoAdresat()
{
    int liczbaAdresatow;
    //jeśli chcemy indwidualne naliczanie adresatów to użyjmy vector adresaci
    wczytajAdresatowWszystkichUzytkownikowZPliku();
    liczbaAdresatow =   adresaciWszyscy.size()-1;

    if(liczbaAdresatow >0)
        idOstatniegoAdresata = adresaciWszyscy[liczbaAdresatow].pobierzId();
    else idOstatniegoAdresata = 0;


}

void AdresatMenedzer::wyswietlWszystkichAdresatow(int idZalogowanegoUzytkownika)
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        {
            for (int i=0; i<adresaci.size(); i++)
            {
                cout<<adresaci[i].pobierzId()<<endl;
                cout<<adresaci[i].pobierzImie()<<endl;
                cout<<adresaci[i].pobierzNazwisko()<<endl;
                cout<<adresaci[i].pobierzNumerTelefonu()<<endl;
                cout<<adresaci[i].pobierzEmail()<<endl;
                cout<<adresaci[i].pobierzAdres()<<endl;
            }
        }
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdresatMenedzer::usuniecieAdresata()
{
    int numerDoUsuniecia;
    char potwierdzenie;
    system("cls");
    cout<<"Podaj numer id kontaktu do usuniecia: "<<endl;
    cin>>numerDoUsuniecia;


    //sprawdzenie czy należy adresat do użytkownika

    for(int i=0; i<adresaci.size(); i++)
    {
        if(numerDoUsuniecia==adresaci[i].pobierzId())
        {
            cout<<"Czy potwierdzasz usuniecie ponizszego adresata: "<<endl;
            cout<<"Potwierdzenie za pomoc¹ znaku t/T"<<endl;
            wypisanieAdresata(i);

            cin>>potwierdzenie;
            if(potwierdzenie=='t'||potwierdzenie=='T')
            {
                adresaci.erase(adresaci.begin()+i);
                plikZAdresatami.nadpisywaniePlikuPoUsunieciu(numerDoUsuniecia);
                cout<<endl<<"Usunieto adresata. Wcisnij dowolny klawisz by wrocic do menu glownego "<<endl;
                system("pause");
                return;
            }
            else return;

        }
    }
    cout<<endl<<"Brak adresata o takim ID "<<endl;
    system("pause");
}


void AdresatMenedzer::wypisanieAdresata(int i)
{
    cout<< adresaci[i].pobierzImie()<<endl;

    cout<< adresaci[i].pobierzNazwisko()<<endl;
    cout<< adresaci[i].pobierzNumerTelefonu()<<endl;
    cout<< adresaci[i].pobierzEmail()<<endl;
    cout<< adresaci[i].pobierzAdres()<<endl<<endl;
}





void AdresatMenedzer::dodajAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;

    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);

    //idOstatniegoAdresata;
}


void AdresatMenedzer::edytujAdresata()
{
        system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (int i = 0; i < adresaci.size(); i++)
    {
        if (adresaci[i].pobierzId() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
             wybor = MetodyPomocnicze::wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                adresaci[i].ustawImie(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzImie())) ;
                //dresat.ustawImie(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                adresaci[i].ustawNazwisko(MetodyPomocnicze::wczytajLinie());
                adresaci[i].ustawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresaci[i].pobierzNazwisko())) ;
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                adresaci[i].ustawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                adresaci[i].ustawEmail(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                adresaci[i].ustawAdres(MetodyPomocnicze::wczytajLinie());
                zaktualizujDaneWybranegoAdresata(adresaci[i], idEdytowanegoAdresata);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
     system("pause");
}

void AdresatMenedzer::zaktualizujDaneWybranegoAdresata(Adresat adresat, int idEdytowanegoAdresata)
{
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    numerLiniiEdytowanegoAdresata = plikZAdresatami.zwrocNumerLiniiSzukanegoAdresata(idEdytowanegoAdresata);
    liniaZDanymiAdresata = MetodyPomocnicze::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);
    plikZAdresatami.edytujWybranaLinieWPliku(numerLiniiEdytowanegoAdresata, liniaZDanymiAdresata);

    cout << endl << "Dane zostaly zaktualizowane." << endl << endl;
}

int AdresatMenedzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}


void AdresatMenedzer::wyszukajAdresatowPoImieniu()
{
    string imiePoszukiwanegoAdresata = "";
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O IMIENIU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o imieniu: ";
        imiePoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        imiePoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(imiePoszukiwanegoAdresata);

        for (vector <Adresat>::iterator  itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzImie() == imiePoszukiwanegoAdresata)
            {
                MetodyPomocnicze::wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
        MetodyPomocnicze::wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta" << endl << endl;
    }
    cout << endl;
    system("pause");
}


void AdresatMenedzer::wyszukajAdresatowPoNazwisku()
{
    string nazwiskoPoszukiwanegoAdresata;
    int iloscAdresatow = 0;

    system("cls");
    if (!adresaci.empty())
    {
        cout << ">>> WYSZUKIWANIE ADRESATOW O NAZWISKU <<<" << endl << endl;

        cout << "Wyszukaj adresatow o nazwisku: ";
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::wczytajLinie();
        nazwiskoPoszukiwanegoAdresata = MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(nazwiskoPoszukiwanegoAdresata);

        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            if (itr -> pobierzNazwisko() == nazwiskoPoszukiwanegoAdresata)
            {
                MetodyPomocnicze::wyswietlDaneAdresata(*itr);
                iloscAdresatow++;
            }
        }
         MetodyPomocnicze::wyswietlIloscWyszukanychAdresatow(iloscAdresatow);
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    cout << endl;
    system("pause");
}
