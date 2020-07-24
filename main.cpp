#include <iostream>
#include <windows.h>
#include <fstream>
#include <vector>

using namespace std;

struct Adresat {
    int idAdresata;
    string imie, nazwisko, numerTelefonu, email, adres;
};

struct Uzytkownik {
    int idUzytkownika;
    string login, haslo;
};

void nadpisywaniePlikuPoUsunieciu(int idAdresataDoZmiany) {
    string linia;
    fstream plik;
    fstream plikTymczasowy;
    int idAdresata,polozenieZnaku;
    plik.open("Ksiazka_kontaktow.txt",ios::in);
    plikTymczasowy.open("Adresaci_tymczasowy.txt",ios::out| ios::app);

    while(getline(plik,linia)) {
        polozenieZnaku = linia.find_first_of("|");
        idAdresata = atoi(linia.substr(0,polozenieZnaku).c_str());
        if(idAdresataDoZmiany!=idAdresata) {

            plikTymczasowy<<linia<<endl;
        }
    }
    plik.close();
    remove ("Ksiazka_kontaktow.txt");
    plikTymczasowy.close();
    rename("Adresaci_tymczasowy.txt","Ksiazka_kontaktow.txt");
}

void nadpisywaniePlikuPoEdycji(vector <Adresat> adresaci, int idDoZmiany, int idUzytkownika) {
    string linia;
    fstream plik;
    fstream plikTymczasowy;
    int idAdresata,polozenieZnaku;
    plik.open("Ksiazka_kontaktow.txt",ios::in);
    plikTymczasowy.open("Adresaci_tymczasowy.txt",ios::out| ios::app);

    while(getline(plik,linia)) {
        polozenieZnaku = linia.find_first_of("|");
        idAdresata = atoi(linia.substr(0,polozenieZnaku).c_str());
        if(adresaci[idDoZmiany].idAdresata!=idAdresata) {

            plikTymczasowy<<linia<<endl;

        } else {
            linia = "|" +adresaci[idDoZmiany].imie + "|" + adresaci[idDoZmiany].nazwisko +  "|" + adresaci[idDoZmiany].numerTelefonu + "|"
                    + adresaci[idDoZmiany].email +  "|" + adresaci[idDoZmiany].adres + "|";
            plikTymczasowy<<adresaci[idDoZmiany].idAdresata;
            plikTymczasowy<<"|";
            plikTymczasowy<<idUzytkownika;
            plikTymczasowy<<linia<<endl;
        }
    }
    plik.close();
    remove ("Ksiazka_kontaktow.txt");
    plikTymczasowy.close();
    rename("Adresaci_tymczasowy.txt","Ksiazka_kontaktow.txt");
}

vector<Adresat> odczytPliku(int idUzytkownika) {
    vector<Adresat>adresaci;
    string linia,wyraz,imie,nazwisko,numerTelefonu,email,adres;
    fstream plik;
    int odczytaneIdUzytkownika,idAdresata;
    int i=0;
    int polozenieZnaku;
    plik.open("Ksiazka_kontaktow.txt",ios::in);
    while(getline(plik,linia)) {

        polozenieZnaku = linia.find_first_of("|");
        idAdresata = atoi(linia.substr(0,polozenieZnaku).c_str());
        linia.erase(0,polozenieZnaku+1);

        polozenieZnaku = linia.find_first_of("|");
        odczytaneIdUzytkownika = atoi(linia.substr(0,polozenieZnaku).c_str());
        linia.erase(0,polozenieZnaku+1);
        if(odczytaneIdUzytkownika==idUzytkownika) {
            polozenieZnaku = linia.find_first_of("|");
            imie = linia.substr(0,polozenieZnaku);
            linia.erase(0,polozenieZnaku+1);

            polozenieZnaku = linia.find_first_of("|");
            nazwisko = linia.substr(0,polozenieZnaku);
            linia.erase(0,polozenieZnaku+1);

            polozenieZnaku = linia.find_first_of("|");
            numerTelefonu = linia.substr(0,polozenieZnaku);
            linia.erase(0,polozenieZnaku+1);

            polozenieZnaku = linia.find_first_of("|");
            email = linia.substr(0,polozenieZnaku);
            linia.erase(0,polozenieZnaku+1);

            polozenieZnaku = linia.find_first_of("|");
            adres = linia.substr(0,polozenieZnaku);
            linia.erase(0,polozenieZnaku+1);

            adresaci.push_back(Adresat{idAdresata,imie,nazwisko,numerTelefonu,email,adres});
            i++;
        }
    }
    return adresaci;
}

vector<Adresat> DodanieKontaktu(vector <Adresat> adresaci, int idUzytkownika) {
    string imie, nazwisko, nrTelefonu, email, adres,numer,linia;
    int idAdresata;
    int polozenieZnaku;
    ("cls");
    cin.sync();
    cout<<"Podaj imie: ";
    getline(cin,imie);
    cout<<"Podaj nazwisko: ";
    getline(cin,nazwisko);
    cout<<"Podaj nrTelefonu: ";
    getline(cin,nrTelefonu);
    cout<<"Podaj email: ";
    getline(cin,email);
    cout<<"Podaj adres: ";
    getline(cin,adres);

    fstream plik;
    plik.open("Ksiazka_kontaktow.txt",ios::in);
    if(plik.good()==true)
        {
            while(getline(plik,linia))
         {   polozenieZnaku = linia.find_first_of("|");
        idAdresata = atoi(linia.substr(0,polozenieZnaku).c_str())+1;
         }
        }

    else idAdresata =1;
    plik.close();
    adresaci.push_back(Adresat{idAdresata,imie,nazwisko,nrTelefonu,email,adres});

    cout<<endl<<"Dodano kontakt: "<< endl;
    cout<<"Imie: "<< imie<< endl;
    cout<<"Nazwisko: "<< nazwisko<< endl;
    cout<<"NumerTelefonu: "<< nrTelefonu<< endl;
    cout<<"email: "<< email<< endl;
    cout<<"adres: "<< adres<< endl;
    Sleep(3000);

    plik.open("Ksiazka_kontaktow.txt",ios::out| ios::app);
    linia = "|" + imie + "|" + nazwisko +  "|" + nrTelefonu + "|" + email +  "|" + adres + "|";

    plik<<idAdresata;
    plik<<"|";
    plik<<idUzytkownika;
    plik<<linia<<endl;
    plik.close();

    return adresaci;
}

void wyszukanieKontaktuPoImieniu(vector <Adresat> adresaci) {
    string kontaktDoWyszukania;

    system("cls");
    cout<<"Podaj imie do wyszukania: "<<endl;
    cin>>kontaktDoWyszukania;

    for(int i=0; i<adresaci.size(); i++) {
        if(kontaktDoWyszukania==adresaci[i].imie) {
            cout<<"Kontakty z wybranym imieniem:"<<endl;
            cout<< adresaci[i].imie<<endl;
            cout<< adresaci[i].nazwisko<<endl;
            cout<< adresaci[i].numerTelefonu<<endl;
            cout<< adresaci[i].email<<endl;
            cout<< adresaci[i].adres<<endl<<endl;
        }
    }
    cout<<endl<<"Wyszukanie zakonczone. Aby zakonczyc wyszukiwanie wcisnij dowolnu klawisz"<<endl;
    system("pause");
}

void wyszukanieKontaktuPoNazwisku(vector <Adresat> adresaci) {
    string kontaktDoWyszukania;
    system("cls");
    cout<<"Podaj nazwisko do wyszukania: "<<endl;
    cin>>kontaktDoWyszukania;
    for(int i=0; i<adresaci.size(); i++) {
        if(kontaktDoWyszukania==adresaci[i].nazwisko) {
            cout<<"Kontakty z wybranym nazwiskiem:"<<endl;
            cout<< adresaci[i].imie<<endl;
            cout<< adresaci[i].nazwisko<<endl;
            cout<< adresaci[i].numerTelefonu<<endl;
            cout<< adresaci[i].email<<endl;
            cout<< adresaci[i].adres<<endl<<endl;
        }
    }
    cout<<endl<<"Wyszukanie zakonczone. Aby zakonczyc wyszukiwanie wcisnij dowolnu klawisz"<<endl;
    system("pause");
}

void wyswietlanieWszystkichKontatkow(vector <Adresat> adresaci) {
    system("cls");
    for(int i=0; i<adresaci.size(); i++) {
        cout<< "numer adresata:"<<adresaci[i].idAdresata<<endl;
        cout<< adresaci[i].imie<<endl;
        cout<< adresaci[i].nazwisko<<endl;
        cout<< adresaci[i].numerTelefonu<<endl;
        cout<< adresaci[i].email<<endl;
        cout<< adresaci[i].adres<<endl<<endl;
    }
    cout<<endl<<"Wyswietlanie zakonczone. Wcisnij dowolny klawisz by wrocic do poprzedniego menu "<<endl;
    system("pause");
}


vector<Adresat> usuniecieAdresata(vector <Adresat> adresaci) {
    int numerDoUsuniecia;
    char potwierdzenie;
    system("cls");
    cout<<"Podaj numer id kontaktu do usuniecia: "<<endl;
    cin>>numerDoUsuniecia;

    for(int i=0; i<adresaci.size(); i++) {
        if(numerDoUsuniecia==adresaci[i].idAdresata) {
            cout<<"Czy potwierdzasz usuniecie ponizszego adresata: "<<endl;
            cout<<"Potwierdzenie za pomoc¹ znaku t/T"<<endl;
            cout<< adresaci[i].imie<<endl;
            cout<< adresaci[i].nazwisko<<endl;
            cout<< adresaci[i].numerTelefonu<<endl;
            cout<< adresaci[i].email<<endl;
            cout<< adresaci[i].adres<<endl<<endl;

            cin>>potwierdzenie;
            if(potwierdzenie=='t'||potwierdzenie=='T') {
                adresaci.erase(adresaci.begin()+i);
                nadpisywaniePlikuPoUsunieciu(numerDoUsuniecia);
                cout<<endl<<"Usunieto adresata. Wcisnij dowolny klawisz by wrocic do menu glownego "<<endl;
                system("pause");
                return adresaci;
            } else return adresaci;
        }
    }
    cout<<"Brak adresata o takim numerze. Wcisnij dowolny klawisz by wrocic do menu glownego " <<endl;
    system("pause");
    return adresaci;
}

vector<Adresat> edycjaKontaktow(vector <Adresat> adresaci, int idUzytkownika) {
    int numerDoEdycji;
    string daneDoZmiany;
    char wybor;
    system("cls");
    cout<<"Podaj numer id kontaktu do edycji: "<<endl;
    cin>>numerDoEdycji;

    for(int i=0; i<adresaci.size(); i++) {
        if(numerDoEdycji==adresaci[i].idAdresata) {
            system("cls");
            cout<< "1. Imie "<<endl;
            cout<< "2. Nazwisko"<<endl;
            cout<< "3. Numer telefonu"<<endl;
            cout<< "4. email"<<endl;
            cout<< "6. Powrot do menu glownego"<<endl;
            cin>>wybor;
        }
        if (wybor == '1') {
            cout<<"Obecne imie to: "<<adresaci[i].imie<<endl<<"Podaj nowe imie: "<<endl;
            cin>>daneDoZmiany;
            adresaci[i].imie=daneDoZmiany;
            nadpisywaniePlikuPoEdycji(adresaci, i, idUzytkownika);
            return adresaci;
        } else if (wybor == '2') {
            cout<<"Obecne nazwisko to: "<<adresaci[i].nazwisko<<endl<<"Podaj nowe nazwisko: "<<endl;
            cin>>daneDoZmiany;
            adresaci[i].nazwisko=daneDoZmiany;
            nadpisywaniePlikuPoEdycji(adresaci, i, idUzytkownika);
            return adresaci;
        } else if (wybor == '3') {
            cout<<"Obecny numer telefonu to: "<<adresaci[i].nazwisko<<endl<<"Podaj nowy numer telefonu: "<<endl;
            cin>>daneDoZmiany;
            adresaci[i].numerTelefonu=daneDoZmiany;
            nadpisywaniePlikuPoEdycji(adresaci, i,idUzytkownika);
            return adresaci;
        } else if (wybor == '4') {
            cout<<"Obecny adres email to: "<<adresaci[i].nazwisko<<endl<<"Podaj nowy adres email: "<<endl;
            cin>>daneDoZmiany;
            adresaci[i].email=daneDoZmiany;
            nadpisywaniePlikuPoEdycji(adresaci, i,  idUzytkownika);
            return adresaci;
        } else if (wybor == '5') {
            cout<<"Obecny adres to: "<<adresaci[i].nazwisko<<endl<<"Podaj nowy adres: "<<endl;
            cin>>daneDoZmiany;
            adresaci[i].adres=daneDoZmiany;
            nadpisywaniePlikuPoEdycji(adresaci, i, idUzytkownika);
            return adresaci;
        } else if (wybor == '6') {
            return adresaci;
        }

    }
    cout<<"Brak adresata o takim numerze. Wcisnij dowolny klawisz by wrocic do menu glownego " <<endl;
    system("pause");
    return adresaci;
}

vector<Uzytkownik>odczytPlikuUzytkownicy() {
    vector<Uzytkownik>uzytkownicy;
    string login, haslo,linia;
    fstream plik;
    int idUzytkownika;
    int i=0;
    int polozenieZnaku;

    plik.open("Uzytkownicy.txt",ios::in);
    if(plik.good()==true) {
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

int logowanieUzytkownika (vector<Uzytkownik>uzytkownicy) {
    string login="", haslo="";
    int liczbaProb=2;
    system("cls");
    cout<<"Logowanie"<<endl<<"Podaj login: "<<endl;
    cin>>login;

    for(int i=0; i<uzytkownicy.size(); i++) {
        if(liczbaProb<0) {
            cout<<"Logowanie nie udane"<<endl;
            Sleep(3000);
            return 0;
        }
        if(login==uzytkownicy[i].login) {
            cout<<"Podaj haslo: "<<endl;
            cin>>haslo;
            if(haslo==uzytkownicy[i].haslo) {
                cout<<"Haslo prawidlowe"<<endl;
                Sleep(3000);
                return uzytkownicy[i].idUzytkownika;
            } else {
                cout<<"Haslo nie prawidlowe"<<endl<<"Pozostalo Ci prob: "<<liczbaProb<<endl;
                i--;
                liczbaProb--;
            }
        }
    }
    cout<<"Brak takiego loginu"<<endl;
    Sleep(3000);
    return 0;
}

void nadpisywaniePlikuUzytkownicy(vector<Uzytkownik> uzytkownicy) {
    string linia;
    fstream plik;
    plik.open("Uzytkownicy.txt",ios::out);

    for(int i=0; i<uzytkownicy.size(); i++) {
        linia = "|" + uzytkownicy[i].login + "|" + uzytkownicy[i].haslo;
        plik<<uzytkownicy[i].idUzytkownika;
        plik<<linia<<endl;
    }
    plik.close();
}


vector<Uzytkownik> zmianaHasla(vector<Uzytkownik> uzytkownicy, int idUzytkownika) {

    string noweHaslo, powtorzoneNoweHaslo, stareHaslo;
    system("cls");
    cout<<"Podaj stare haslo: "<<endl;
    cin>>stareHaslo;
    if(stareHaslo==uzytkownicy[idUzytkownika-1].haslo) {
        cout<<"Podaj nowe haslo: "<<endl;
        cin>>noweHaslo;
        cout<<"Powtorz nowe haslo: "<<endl;
        cin>>powtorzoneNoweHaslo;
        if (powtorzoneNoweHaslo==noweHaslo) {
            cout<<"Haslo zostalo zmienione";
            uzytkownicy[idUzytkownika-1].haslo = powtorzoneNoweHaslo;
            nadpisywaniePlikuUzytkownicy(uzytkownicy);
            Sleep(3000);
            return uzytkownicy;
        } else cout<<"Wpisano nie prawidlowe haslo "<< endl;
        Sleep(3000);

    } else cout<<"Haslo nie prawidlowe"<<endl;
    Sleep(3000);

    return uzytkownicy;
}

int oknoPoZalogowaniu(int idUzytkownika, string login, vector<Uzytkownik>uzytkownicy) {
    vector<Adresat>adresaci;
    char wybor;

    fstream plik;
    plik.open("Ksiazka_kontaktow.txt",ios::in);
    if(plik.good()==true)
        adresaci = odczytPliku(idUzytkownika);
    plik.close();
    while(1) {
        system("cls");
        cout<< "1. Dodaj adresata "<<endl;
        cout<< "2. Wyszukanie po imieniu"<<endl;
        cout<< "3. Wyszukanie po nazwisku"<<endl;
        cout<< "4. Wyswietl wszystkich adresatow"<<endl;
        cout<< "5. Usun adresata"<<endl;
        cout<< "6. Edytuj adresata"<<endl;
        cout<< "7. Zmiana hasla"<<endl;
        cout<< "9. Wyloguj sie"<<endl;
        cin>>wybor;
        if (wybor == '1') {
            adresaci = DodanieKontaktu(adresaci,idUzytkownika);
        } else if (wybor == '2') {
            wyszukanieKontaktuPoImieniu(adresaci);
        } else if (wybor == '3') {
            wyszukanieKontaktuPoNazwisku(adresaci);
        } else if (wybor == '4') {
            wyswietlanieWszystkichKontatkow(adresaci);
        } else if (wybor == '5') {
            adresaci = usuniecieAdresata(adresaci);
        } else if (wybor == '6') {
            adresaci = edycjaKontaktow(adresaci,idUzytkownika);

        } else if (wybor == '7') {
            uzytkownicy = zmianaHasla(uzytkownicy,idUzytkownika);
        } else if (wybor == '9') {
            return 0;
        }
    }
}


void rejestracjaUzytkownika(vector<Uzytkownik>uzytkownicy) {

    int idUzytkonika;
    string login, haslo,linia;
    system("cls");
    cout<<"Podaj login uzytkownika: "<<endl;
    cin>>login;

    for(int i=0; i<uzytkownicy.size(); i++) {
        if(login==uzytkownicy[i].login) {
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

int main() {

    vector<Uzytkownik>uzytkownicy;
    int idUzytkownika;
    char wybor;

    while(1) {
        system("cls");
        cout<< "1. Logowanie "<<endl;
        cout<< "2. Rejestracja"<<endl;
        cout<< "9. Zakoncz program"<<endl;
        cin>>wybor;

        if (wybor == '1') {
            uzytkownicy = odczytPlikuUzytkownicy();
            idUzytkownika=logowanieUzytkownika(uzytkownicy);
            if(idUzytkownika>0) {
                idUzytkownika = oknoPoZalogowaniu(idUzytkownika,uzytkownicy[idUzytkownika-1].login,uzytkownicy);
            }
        } else if (wybor == '2') {
            uzytkownicy = odczytPlikuUzytkownicy();
            rejestracjaUzytkownika(uzytkownicy);
        } else if (wybor == '9') {
            exit(0);
        }
    }
    return 0;
}

