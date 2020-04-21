#include <iostream>
#include <math.h>
using namespace std;

class Wielokat
{
    virtual float obwod() = 0;
    virtual float pole() = 0;
    virtual void wczytywanieBokami() = 0;
    //virtual void wczytywanieWspolrzednymi() = 0;
};
class Trojkat:public Wielokat
{
protected:
    float bok1, bok2, bok3;
    virtual void wczytywanieBokami()
    {
        cout << "Podaj dlugosc boku 1: ";
        cin >> bok1;
        cout << endl;
        cout << "Podaj dlugosc boku 2: ";
        cin >> bok2;
        cout << endl;
        cout << "Podaj dlugosc boku 3: ";
        cin >> bok3;
        cout << endl;
    }
    virtual float obwod()
    {
        return bok1 + bok2 + bok3;
    }
    virtual float pole()
    {
        float polowaObwodu = obwod() / 2.f;
        return sqrt(polowaObwodu*(polowaObwodu-bok1)*(polowaObwodu-bok2)*(polowaObwodu-bok3));
    }
};
class Czworobok:public Wielokat
{
protected:
    float bok1, bok2, bok3, bok4;
    virtual void wczytywanieBokami()
    {
        cout << "Podaj dlugosc boku 1: ";
        cin >> bok1;
        cout << endl;
        cout << "Podaj dlugosc boku 2: ";
        cin >> bok2;
        cout << endl;
        cout << "Podaj dlugosc boku 3: ";
        cin >> bok3;
        cout << endl;
        cout << "Podaj dlugosc boku 4: ";
        cin >> bok4;
        cout << endl;
    }
    virtual float obwod()
    {
        return bok1 + bok2 + bok3 + bok4;
    }
    virtual float pole()
    {
        cout << "Nie da sie obliczyc pola czworoboku na podstawie samych bokow" << endl;
        return 0;
    }
};
class Pentagon:public Wielokat
{
    float bok1;
    virtual void wczytywanieBokami()
    {
        cout << "Podaj dlugosc boku: ";
        cin >> bok1;
        cout << endl;
    }
    virtual float obwod()
    {
        return 5 * bok1;
    }
    virtual float pole()
    {
        return (5 * pow(bok1, 2)) / (4 * tan(M_PI / 5));
    }
};
class Heksagon:public Wielokat
{
    float bok1;
    virtual void wczytywanieBokami()
    {
        cout << "Podaj dlugosc boku: ";
        cin >> bok1;
        cout << endl;
    }
    virtual float obwod()
    {
        return bok1 * 6;
    }
    virtual float pole()
    {
        return (6 * pow(bok1, 2)) / (4 * tan(M_PI / 6));
    }
};
class Oktagon:public Wielokat
{
    float bok1;
    virtual void wczytywanieBokami()
    {
        cout << "Podaj dlugosc boku: ";
        cin >> bok1;
        cout << endl;
    }
    virtual float obwod()
    {
        return bok1 * 8;
    }
    virtual float pole()
    {
        return (8 * pow(bok1, 2)) / (4 * tan(M_PI / 8));
    }
};
class TrojkatRownoramienny:public Trojkat
{
    virtual void wczytywanieBokami()
    {
        cout << "Podaj dlugosc podstawy: ";
        cin >> bok1;
        cout << endl;
        cout << "Podaj dlugosc ramion: ";
        cin >> bok2;
        cout << endl;
        bok3 = bok2;
    }
};
class TrojkatRownoboczny:public Trojkat
{
    virtual void wczytywanieBokami()
    {
        cout << "Podaj dlugosc boku: ";
        cin >> bok1;
        cout << endl;
        bok2 = bok1;
        bok3 = bok2;
    }
};
class Prostokat:public Czworobok
{
    virtual void wczytywanieBokami()
    {
        cout << "Podaj dlugosc boku 1: ";
        cin >> bok1;
        cout << endl;
        cout << "Podaj dlugosc boku 2: ";
        cin >> bok2;
        cout << endl;
        bok3 = bok1;
        bok4 = bok2;
    }
    virtual float pole()
    {
        return bok1 * bok2;
    }
};
class Kwadrat:public Czworobok
{
    virtual void wczytywanieBokami()
    {
        cout << "Podaj dlugosc boku: ";
        cin >> bok1;
        cout << endl;
        bok2 = bok1;
        bok3 = bok1;
        bok4 = bok1;
    }
    virtual float pole()
    {
        return bok1 * bok1;
    }
};
void Wczytywanie()
{
    int wyborWymiarow, wyborFigury;
    cout << "Wybierz sposob wprowadzania wymiarow figur:" << endl;
    cout << "1 - Dlugosci bokow" << endl;
    cout << "2 - Wspolrzedne" << endl;
    cin >> wyborWymiarow;
    cout << "Wybierz figure:" << endl;
    cout << "1 - Trojkat" << endl;
    cout << "2 - Czworobok" << endl;
    cout << "3 - Pentagon" << endl;
    cout << "4 - Heksagon" << endl;
    cout << "5 - Oktagon" << endl;
    cout << "6 - Trojkat rownoramienny" << endl;
    cout << "7 - Trojkat rownoboczny" << endl;
    cout << "8 - Prostokat" << endl;
    cout << "9 - Kwadrat" << endl;
    cin >> wyborFigury;
    Wielokat* w;
    switch(wyborFigury)
    {
        case 1:
        {
            w = new Trojkat();
            break;
        }
        case 2:
        {
            w = new Czworobok;
            break;
        }
        case 3:
        {
            w = new Pentagon;
            break;
        }
        case 4:
        {
            w = new Heksagon;
            break;
        }
        case 5:
        {
            w = new Oktagon;
            break;
        }
        case 6:
        {
            w = new TrojkatRownoramienny;
            break;
        }
        case 7:
        {
            w = new TrojkatRownoboczny;
            break;
        }
        case 8:
        {
            w = new Prostokat;
            break;
        }
        case 9:
        {
            w = new Kwadrat;
            break;
        }
    }

}

int main()
{

    return 0;
}
