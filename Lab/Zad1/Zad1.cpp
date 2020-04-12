// Zofia Blazyca
// Program sortujacy tablice jednym ze sposobow: quicksort lub mergesort
// Program zaklada, ze jest stworzony plik o nazwie "liczby.txt"
// z liczbami do posortowania, przed rozpoczeciem dzialania programu nalezy
// podac odpowiednia sciezke w linii 41

#include <iostream>
#include <fstream>

using namespace std;

void sortuj(int tab[], int lewy, int prawy, int liczbaElementow);
void sortuj(int lewy, int prawy, int liczbaElementow, int tab[]);
void polacz(int tab[], int lewy, int srodek, int prawy);

int main()
{
    // wczytywanie nazwy
    string nazwa;
    cout << "Podaj nazwe pliku z danymi:";
    cin >> nazwa;
    while(nazwa != "liczby.txt")
    {
        cout << "Niepoprawna nazwa! Podaj jeszcze raz: ";
        cin >> nazwa;
    }

    // wybieranie sposobu sortowania
    int nrSortowania;
    cout << "Wybierz sposob sortowania:" << endl;
    cout << "1 - Sortowanie szybkie" << endl;
    cout << "2 - Sortowanie przez scalanie" << endl;
    cin >> nrSortowania;
    while(nrSortowania != 1 && nrSortowania != 2)
    {
        cout << "Niepoprawny numer! Podaj jeszcze raz: ";
        cin >> nrSortowania;
    }

    // dzialanie na pliku i tworzenie tablicy za pomoca wskaznika
    ifstream plo;
    plo.open("C:\\Users\\Zosix\\CLionProjects\\P2\\Lab\\Zad1\\liczby.txt");

    int liczbaElementow = 0;
    string smietnik;
    while (!plo.eof())
    {
        plo >> smietnik;
        liczbaElementow++;
    }

    int* tab;
    tab = new int[liczbaElementow];

    plo.clear();
    plo.seekg(0, ios::beg);

    int j = 0;
    while (!plo.eof())
    {
        plo >> tab[j];
        j++;
    }
    plo.close();

    // sprawdzenie wczytywania
    cout << "Tablica przed sortowaniem:" << endl;
    for(int i = 0; i < liczbaElementow; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl << endl;

    //wybor odpowiedniej funkcji
    if(nrSortowania == 1)
    {
        sortuj(tab, 0, liczbaElementow - 1, liczbaElementow);
    }
    else
    {
        sortuj(0, liczbaElementow - 1, liczbaElementow, tab);
    }

    cout << "Tablica posortowana:" << endl;
    for(int i = 0; i < liczbaElementow; i++)
    {
        cout << tab[i] << " ";
    }

    delete [] tab;
    return 0;
}

void swap(int &a, int &b)
{
    int buff = a;
    a = b;
    b = buff;
}

void sortuj(int tab[], int lewy, int prawy, int liczbaElementow)
{
    // quicksort rekurencja

    if(prawy <= lewy)
        return;

    int i = lewy - 1;
    int j = prawy + 1;


    int pivot = tab[(lewy + prawy) / 2];
    while(true)
    {
        while(tab[++i] < pivot);
        while(tab[--j] > pivot);

        if(i < j)
            swap(tab[i], tab[j]);
        else
        {
            if(i == j)
            {
                i++;
                j--;
            }
            break;
        }
    }
    cout << "Tablica po kolejnym kroku sortowania:" << endl;
    for(int i = 0; i < liczbaElementow; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl << endl;

    if(j > lewy)
        sortuj(tab, lewy, j, liczbaElementow);
    if(i < prawy)
        sortuj(tab, i, prawy, liczbaElementow);
}

void polacz(int tab[], int lewy, int srodek, int prawy)
{
    int indeksPierwszejPodtablicy, indeksDrugiejPodtablicy, indeksPolaczonejTablicy;
    int n1 = srodek - lewy + 1;
    int n2 =  prawy - srodek;

    int L[n1], P[n2];

    for (indeksPierwszejPodtablicy = 0; indeksPierwszejPodtablicy < n1; indeksPierwszejPodtablicy++)
        L[indeksPierwszejPodtablicy] = tab[lewy + indeksPierwszejPodtablicy];
    for (indeksDrugiejPodtablicy = 0; indeksDrugiejPodtablicy < n2; indeksDrugiejPodtablicy++)
        P[indeksDrugiejPodtablicy] = tab[srodek + 1 + indeksDrugiejPodtablicy];

    indeksPierwszejPodtablicy = 0;
    indeksDrugiejPodtablicy = 0;
    indeksPolaczonejTablicy = lewy;
    while (indeksPierwszejPodtablicy < n1 && indeksDrugiejPodtablicy < n2)
    {
        if (L[indeksPierwszejPodtablicy] <= P[indeksDrugiejPodtablicy])
        {
            tab[indeksPolaczonejTablicy] = L[indeksPierwszejPodtablicy];
            indeksPierwszejPodtablicy++;
        }
        else
        {
            tab[indeksPolaczonejTablicy] = P[indeksDrugiejPodtablicy];
            indeksDrugiejPodtablicy++;
        }
        indeksPolaczonejTablicy++;
    }

    while (indeksPierwszejPodtablicy < n1)
    {
        tab[indeksPolaczonejTablicy] = L[indeksPierwszejPodtablicy];
        indeksPierwszejPodtablicy++;
        indeksPolaczonejTablicy++;
    }

    while (indeksDrugiejPodtablicy < n2)
    {
        tab[indeksPolaczonejTablicy] = P[indeksDrugiejPodtablicy];
        indeksDrugiejPodtablicy++;
        indeksPolaczonejTablicy++;
    }
}

void sortuj(int lewy, int prawy, int liczbaElementow, int tab[])
{
    // mergesort rekurencja
    if (lewy < prawy)
    {
        int srodek = lewy + (prawy - lewy) / 2;

        sortuj(lewy, srodek, liczbaElementow, tab);
        sortuj(srodek + 1, prawy, liczbaElementow, tab);

        cout << "Tablica po kolejnym kroku sortowania:" << endl;
        for(int i = 0; i < liczbaElementow; i++)
        {
            cout << tab[i] << " ";
        }
        cout << endl << endl;

        polacz(tab, lewy, srodek, prawy);
    }
}
