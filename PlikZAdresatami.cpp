
#include "PlikZAdresatami.h"

/*PlikZAdresatami::PlikZAdresatami()
{
    nazwaPlikuZAdresatami = "Adresaci.txt";
}
*/
void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    //string nazwaPlikuZAdresatami = "Adresaci.txt";
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);


        if (PlikZAdresatami::czyPlikJestPusty() == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
        }
        else
        {
            plikTekstowy<< endl  << liniaZDanymiAdresata ;
        }
    }
    else
    {
        cout << "Nie udalo sie otworzyc pliku i zapisac w nim danych." << endl;
    }
    plikTekstowy.close();
    system("pause");
}

/*bool PlikZAdresatami::czyPlikJestPusty()
{
    //fstream plikTekstowy;
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.good()==false)
        return true;
    else
        return false;
}
*/

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata = "";
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie()+ '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}


vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;

    vector <Adresat> adresaci;
    int idOstatniegoAdresata = 0;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idZalogowanegoUzytkownika == MetodyPomocnicze::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    }
    else
        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
    plikTekstowy.close();
    return adresaci;
}
    vector <Adresat> PlikZAdresatami::wczytajAdresatowWszystkichUzytkownikowZPliku()
    {
        Adresat adresat;

        vector <Adresat> adresaci;
        int idOstatniegoAdresata = 0;
        string daneJednegoAdresataOddzielonePionowymiKreskami = "";
        string daneOstaniegoAdresataWPliku = "";
        fstream plikTekstowy;
        plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

        if (plikTekstowy.good() == true)
        {
            while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
            {

                    adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                    adresaci.push_back(adresat);

            }
            //daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
        }
        else
            cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
        plikTekstowy.close();
        return adresaci;
        /*
            if (daneOstaniegoAdresataWPliku != "")
            {
                idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);

            }
            else
                idOstatniegoAdresat = 0;
                */
    }

    Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami)
    {
        Adresat adresat;
        string pojedynczaDanaAdresata = "";
        int numerPojedynczejDanejAdresata = 1;

        for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
        {
            if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
            {
                pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
            }
            else
            {
                switch(numerPojedynczejDanejAdresata)
                {
                case 1:
                    adresat.ustawId(atoi(pojedynczaDanaAdresata.c_str()));
                    break;
                case 2:
                    adresat.ustawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                    break;
                case 3:
                    adresat.ustawImie(pojedynczaDanaAdresata);
                    break;
                case 4:
                    adresat.ustawNazwisko(pojedynczaDanaAdresata);
                    break;
                case 5:
                    adresat.ustawNumerTelefonu(pojedynczaDanaAdresata);
                    break;
                case 6:
                    adresat.ustawEmail(pojedynczaDanaAdresata);
                    break;
                case 7:
                    adresat.ustawAdres(pojedynczaDanaAdresata);
                    break;
                }
                pojedynczaDanaAdresata = "";
                numerPojedynczejDanejAdresata++;
            }
        }
        return adresat;
    }


    void PlikZAdresatami::nadpisywaniePlikuPoUsunieciu(int idAdresataDoZmiany)
{
    string linia;
    fstream plik;
    fstream plikTymczasowy;
 //pobierzNazwePliku();
    int idAdresata,polozenieZnaku;
    plik.open(pobierzNazwePliku(),ios::in);
    plikTymczasowy.open( pobierzNazwePliku() + "_tymczasowy.txt",ios::out| ios::app);

    while(getline(plik,linia))
    {
        polozenieZnaku = linia.find_first_of("|");
        idAdresata = atoi(linia.substr(0,polozenieZnaku).c_str());

        if(idAdresataDoZmiany!=idAdresata)
        {

            plikTymczasowy<<linia<<endl;
        }
    }

    plik.close();
    remove (pobierzNazwePliku().c_str());
    plikTymczasowy.close();

    rename((pobierzNazwePliku() + "_tymczasowy.txt").c_str(),pobierzNazwePliku().c_str());
}


int PlikZAdresatami::zwrocNumerLiniiSzukanegoAdresata(int idAdresata)
{
    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;
    plikTekstowy.open(pobierzNazwePliku().c_str(), ios::in);

    if (plikTekstowy.good() == true && idAdresata != 0)
    {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idAdresata == MetodyPomocnicze::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                czyIstniejeAdresat = true;
                plikTekstowy.close();
                return numerLiniiWPlikuTekstowym;
            }
            else
                numerLiniiWPlikuTekstowym++;
        }
        if (czyIstniejeAdresat = false)
        {
            plikTekstowy.close();
            return 0;
        }
    }
    return 0;
}


void PlikZAdresatami::edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami)
{
    fstream plik, plikTymczasowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;

    plik.open(pobierzNazwePliku().c_str(), ios::in);
    plikTymczasowy.open((pobierzNazwePliku() + "_tymczasowy.txt").c_str(), ios::out | ios::app);

    if (plik.good() == true)
    {
        while (getline(plik, wczytanaLinia))
        {
            if (numerWczytanejLinii == numerEdytowanejLinii)
            {
                if (numerWczytanejLinii == 1)
                    plikTymczasowy << liniaZDanymiAdresataOddzielonePionowymiKreskami;
                else if (numerWczytanejLinii > 1)
                    plikTymczasowy << endl << liniaZDanymiAdresataOddzielonePionowymiKreskami;
            }
            else
            {
                if (numerWczytanejLinii == 1)
                    plikTymczasowy << wczytanaLinia;
                else if (numerWczytanejLinii > 1)
                    plikTymczasowy << endl << wczytanaLinia;
            }
            numerWczytanejLinii++;
        }
    plik.close();
    remove (pobierzNazwePliku().c_str());
    plikTymczasowy.close();

    rename((pobierzNazwePliku() + "_tymczasowy.txt").c_str(),pobierzNazwePliku().c_str());
    }
}
