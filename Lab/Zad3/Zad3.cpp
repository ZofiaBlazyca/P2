#include <iostream>
#include <math.h>
#include <list>
using namespace std;

struct punkt
{
    int x, y;
};
punkt wczytajWierzcholek(int nrWierzcholka)
{
    punkt p;
    cout << "Wprowadz wspolrzedne X wierzcholka " << nrWierzcholka << ": ";
    cin >> p.x;
    cout << endl;
    cout << "Wprowadz wspolrzedne Y wierzcholka " << nrWierzcholka << ": ";
    cin >> p.y;
    cout << endl;
    return p;
}
float obliczDlugoscBoku(punkt p1, punkt p2)
{
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}
class Wielokat
{
public:
    virtual void wczytywanieBokami() = 0;
    virtual void wczytywanieWspolrzednymi() = 0;
    virtual float pole() = 0;
    virtual float obwod() = 0;
    virtual void sprawdzPodobienstwo() = 0;
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
    virtual void wczytywanieWspolrzednymi()
    {
        punkt tablicaPunktow[3];
        for(int i = 0; i < 3; i++)
        {
            tablicaPunktow[i] = wczytajWierzcholek(i+1);
        }
        bok1 = obliczDlugoscBoku(tablicaPunktow[0], tablicaPunktow[1]);
        bok2 = obliczDlugoscBoku(tablicaPunktow[1], tablicaPunktow[2]);
        bok3 = obliczDlugoscBoku(tablicaPunktow[2], tablicaPunktow[0]);
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
    virtual void sprawdzPodobienstwo()
    {
        Trojkat t;
        cout << "Wczytywanie wierzcholkow drugiego trojkata" << endl;
        t.wczytywanieWspolrzednymi();
        list <float> boki;
        boki.push_back(bok1);
        boki.push_back(bok2);
        boki.push_back(bok3);
        boki.sort();
        list <float> bokit;
        bokit.push_back(t.bok1);
        bokit.push_back(t.bok2);
        bokit.push_back(t.bok3);
        bokit.sort();
        auto iteratorBoki = boki.begin();
        auto iteratorBokit = bokit.begin();
        float stosunek = *iteratorBoki / *iteratorBokit;
        for(int i = 1; i < boki.size(); i++)
        {
            advance(iteratorBoki, 1);
            advance(iteratorBokit, 1);
            if(fabs(*iteratorBoki / *iteratorBokit - stosunek) > 0.005f)
            {
                cout << "Trojkaty nie sa podobne" << endl;
                return;
            }
        }
        cout << "Trojkaty sa podobne" << endl;
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
    virtual void wczytywanieWspolrzednymi()
    {
        punkt tablicaPunktow[4];
        for(int i = 0; i < 4; i++)
        {
            tablicaPunktow[i] = wczytajWierzcholek(i+1);
        }
        bok1 = obliczDlugoscBoku(tablicaPunktow[0], tablicaPunktow[1]);
        bok2 = obliczDlugoscBoku(tablicaPunktow[1], tablicaPunktow[2]);
        bok3 = obliczDlugoscBoku(tablicaPunktow[2], tablicaPunktow[3]);
        bok4 = obliczDlugoscBoku(tablicaPunktow[3], tablicaPunktow[0]);
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
    virtual void sprawdzPodobienstwo()
    {
        Czworobok c;
        cout << "Wczytywanie wierzcholkow drugiego czworoboku" << endl;
        c.wczytywanieWspolrzednymi();
        list <float> boki;
        boki.push_back(bok1);
        boki.push_back(bok2);
        boki.push_back(bok3);
        boki.push_back(bok4);
        boki.sort();
        list <float> bokic;
        bokic.push_back(c.bok1);
        bokic.push_back(c.bok2);
        bokic.push_back(c.bok3);
        bokic.push_back(c.bok4);
        bokic.sort();
        auto iteratorBoki = boki.begin();
        auto iteratorBokic = bokic.begin();
        float stosunek = *iteratorBoki / *iteratorBokic;
        for(int i = 1; i < boki.size(); i++)
        {
            advance(iteratorBoki, 1);
            advance(iteratorBokic, 1);
            if(fabs(*iteratorBoki / *iteratorBokic - stosunek) > 0.005f)
            {
                cout << "Czworoboki nie sa podobne" << endl;
                return;
            }
        }
        cout << "Czworoboki sa podobne" << endl;
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
    virtual void wczytywanieWspolrzednymi()
    {
        punkt tablicaPunktow[5];
        for(int i = 0; i < 5; i++)
        {
            tablicaPunktow[i] = wczytajWierzcholek(i+1);
        }
        bok1 = obliczDlugoscBoku(tablicaPunktow[4], tablicaPunktow[0]);
        for(int i = 0; i < 4; i++)
        {
            if(obliczDlugoscBoku(tablicaPunktow[i], tablicaPunktow[i+1]) != bok1)
            {
                cout << "Wprowadzono zle wspolrzedne" << endl;
                break;
            }
        }
    }
    virtual float obwod()
    {
        return 5 * bok1;
    }
    virtual float pole()
    {
        return (5 * pow(bok1, 2)) / (4 * tan(M_PI / 5));
    }
    virtual void sprawdzPodobienstwo()
    {
        cout << "Pentagony zawsze sa podobne" << endl;
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
    virtual void wczytywanieWspolrzednymi()
    {
        punkt tablicaPunktow[6];
        for(int i = 0; i < 6; i++)
        {
            tablicaPunktow[i] = wczytajWierzcholek(i+1);
        }
        bok1 = obliczDlugoscBoku(tablicaPunktow[5], tablicaPunktow[0]);
        for(int i = 0; i < 5; i++)
        {
            if(obliczDlugoscBoku(tablicaPunktow[i], tablicaPunktow[i+1]) != bok1)
            {
                cout << "Wprowadzono zle wspolrzedne" << endl;
                break;
            }
        }
    }
    virtual float obwod()
    {
        return bok1 * 6;
    }
    virtual float pole()
    {
        return (6 * pow(bok1, 2)) / (4 * tan(M_PI / 6));
    }
    virtual void sprawdzPodobienstwo()
    {
        cout << "Heksagony zawsze sa podobne" << endl;
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
    virtual void wczytywanieWspolrzednymi()
    {
        punkt tablicaPunktow[8];
        for(int i = 0; i < 8; i++)
        {
            tablicaPunktow[i] = wczytajWierzcholek(i+1);
        }
        bok1 = obliczDlugoscBoku(tablicaPunktow[7], tablicaPunktow[0]);
        for(int i = 0; i < 7; i++)
        {
            if(obliczDlugoscBoku(tablicaPunktow[i], tablicaPunktow[i+1]) != bok1)
            {
                cout << "Wprowadzono zle wspolrzedne" << endl;
                break;
            }
        }
    }
    virtual float obwod()
    {
        return bok1 * 8;
    }
    virtual float pole()
    {
        return (8 * pow(bok1, 2)) / (4 * tan(M_PI / 8));
    }
    virtual void sprawdzPodobienstwo()
    {
        cout << "Oktagony zawsze sa podobne" << endl;
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
    virtual void sprawdzPodobienstwo()
    {
        cout << "Trojkaty rownoboczne zawsze sa podobne" << endl;
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
    virtual void sprawdzPodobienstwo()
    {
        cout << "Kwadraty zawsze sa podobne" << endl;
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
    if(wyborWymiarow == 1)
    {
        w->wczytywanieBokami();
        cout << "Pole figury wynosi: " << w->pole() << endl;
        cout << endl;
        cout << "Obwod figury wynosi: " << w->obwod() << endl;
        cout << endl;
    } else
    {
        w->wczytywanieWspolrzednymi();
        cout << "Pole figury wynosi: " << w->pole() << endl;
        cout << endl;
        cout << "Obwod figury wynosi: " << w->obwod() << endl;
        cout << endl;
        w->sprawdzPodobienstwo();
    }
    delete w;
}

int main()
{
    Wczytywanie();
    return 0;
}
