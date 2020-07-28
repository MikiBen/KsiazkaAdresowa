#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;
struct Uzytkownik
{
    int idUzytkownika;
    string login, haslo;
};


class LogowanieUzytkownika
{
private:
    string login, haslo, powtorzoneHaslo;

    int liczbaProb;
public:
    int numerUzytkownika;
    LogowanieUzytkownika(string log="", string has="", int id=-1, int lProb=3)
    {
        login=log;
        haslo=has;
        numerUzytkownika = id;
        liczbaProb= lProb;

    }

    void wczytajLogin()
    {
        system("cls");
        cout<<"Logowanie"<<endl<<"Podaj login"<<endl;
        cin>>login;
    }

    void wczytajHaslo(vector<Uzytkownik>uzytkownicy)
    {
        if(numerUzytkownika>=0)
        {
            cout<<"Podaj haslo"<<endl;
            cin>>haslo;
        }

        if(haslo==uzytkownicy[numerUzytkownika].haslo)
        {
            cout<<"Haslo prawidlowe"<<endl;
            Sleep(2000);
        }

        else
        {
            liczbaProb--;
            system("cls");
            cout<<"Haslo nie prawidlowe"<<endl;
            Sleep(2000);

            if(liczbaProb>0)
            {
                cout<<"Pozostalo Ci: "<<liczbaProb<<" prob."<<endl;
                wczytajHaslo(uzytkownicy);
            }

        }

    }
    void sprawdzLogin(vector<Uzytkownik>uzytkownicy)
    {
        for(int i=0; i<uzytkownicy.size(); i++)
        {
            if(login==uzytkownicy[i].login)
            {
                numerUzytkownika=i;
                wczytajHaslo(uzytkownicy);
            }
        }
        if(numerUzytkownika<0)
        {
            cout<<"brak takiego uzytkownika."<<endl;
            numerUzytkownika=-1;
            Sleep(2000);

        }
    }




};

class OdczytPliku
{
public:
    vector<Uzytkownik>uzytkownicy;
private:
    string login, haslo,linia;
    fstream plik;
    int idUzytkownika;
    int i;
    int polozenieZnaku;

public:

    OdczytPliku(string log="", string has="", int id=0, int ii=0, int polZnaku =0)
    {
        login=log;
        haslo=has;
        idUzytkownika = id;
        i=ii;
        polozenieZnaku = polZnaku;
    }
    vector<Uzytkownik> odczytPlikuUzytkownicy()
    {
        plik.open("Uzytkownicy.txt",ios::in);
        if(plik.good()==true)
        {
            while(getline(plik,linia))

            {
                polozenieZnaku = linia.find_first_of("|");
                idUzytkownika= atoi(linia.substr(0,polozenieZnaku).c_str());
                linia.erase(0,polozenieZnaku+1);

                polozenieZnaku = linia.find_first_of("|");
                login = linia.substr(0,polozenieZnaku);
                linia.erase(0,polozenieZnaku+1);

                polozenieZnaku = linia.find_first_of("|");
                haslo = linia.substr(0,polozenieZnaku);
                linia.erase(0,polozenieZnaku+1);

                uzytkownicy.push_back(Uzytkownik{idUzytkownika,login,haslo});
            }
        }
        plik.close();
        return uzytkownicy;
    }

};


class RejestracjaUzytkownika
{

    int idUzytkonika;
    string login, haslo,linia;
public:
    void rejestracjaUzytkownika(vector<Uzytkownik>uzytkownicy)
    {
        cout<<"Podaj login uzytkownika: "<<endl;
        cin>>login;

        for(int i=0; i<uzytkownicy.size(); i++)
        {
            if(login==uzytkownicy[i].login)
            {
                cout<<"Taki login juz istnieje"<<endl<<"Podaj inny login: "<<endl;
                cin>>login;
                i=-1;
            }
        }
        cout<<"Podaj haslo: "<<endl;
        cin>>haslo;
        if(uzytkownicy.size()>0)
            idUzytkonika= uzytkownicy[uzytkownicy.size()-1].idUzytkownika+1;
        else idUzytkonika=1;
        fstream plik;
        plik.open("Uzytkownicy.txt",ios::out| ios::app);

        linia = "|" + login+ "|" + haslo +  "|";

        plik<<idUzytkonika;
        plik<<linia<<endl;
        plik.close();
    }

};
