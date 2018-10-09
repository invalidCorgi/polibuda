#include <iostream>
#include <string>
#include <time.h>
#include <cstdlib>
using namespace std;

class Czlowiek
{
protected:
    string imie="jam";
    string nazwisko="jest";
public:
    Czlowiek(string _imie, string _nazwisko)
    {
        imie = _imie;
        nazwisko = _nazwisko;
        cout << "Olaboga czleka mi konstruujo" << endl;
    }
    Czlowiek()
    {
        imie = "a";
        nazwisko = "b";
        cout << "Olaboga czleka mi konstruujo" << endl;
    }
    virtual void PrzedstawSie()
    {
        cout << "Jestem " << imie << " " <<  nazwisko << endl;
    }
    virtual void Pij(){};
    virtual ~Czlowiek()
    {
        cout << "Czlowieka zabijajo, ratujcie" << endl;
    }
};

class Student : Czlowiek
{
private:
    int NrIndeksu=132312;
public:
    Student(string _imie, string _nazwisko, int _nr) : Czlowiek(_imie, _nazwisko)
    {
        NrIndeksu = _nr;
        cout << "Studenciak powstaje, tyle strat dla homo sapiens" << endl;
    }
    void PrzedstawSie()
    {
        cout << "Jestem " << imie << " " <<  nazwisko << endl;
        cout << "Moj Nr indeksu to " << NrIndeksu << endl;
    }
    void Pij()
    {
        cout << "Poprosze skrzynke wodki, amarene i dwie oranzady" << endl;
    }
    virtual ~Student()
    {
        cout << "W koncu umar studenciak, tyle zyskow" << endl;
    }
};

class Pracownik : Czlowiek
{
public:
    Pracownik(string _imie, string _nazwisko) : Czlowiek(_imie, _nazwisko)
    {
        cout << "Prawilny pracownik zawsze prawilny" << endl;
    }
    Pracownik() : Czlowiek(){}
    void Pij()
    {
        cout << "Dej pan mie setke i ide dalej plakac nad wlasnym zyciem" << endl;
    }
    virtual ~Pracownik()
    {
        cout << "Umiera pracownik, klekajcie narody" << endl;
    }
};

int main()
{
    Student *s;
    cout << sizeof(*s);
    int liczbaOsob;
    srand(time(nullptr));
    cin >> liczbaOsob;
    cout << "Liczba osob w kolejce: " << liczbaOsob << endl;
    Czlowiek **lista;
    lista = new Czlowiek*[liczbaOsob];
    for(int i=0; i<liczbaOsob; i++)
    {
        if((rand()%2)==0)
            lista[i] = (Czlowiek*)new Pracownik("a","b");
        else
            lista[i] = (Czlowiek*)new Student("c","d",rand());
    }
    for(int i=0; i<liczbaOsob; i++)
    {
        lista[i]->PrzedstawSie();
        lista[i]->Pij();
        delete lista[i];
    }
    delete [] lista;

    return 0;
}
