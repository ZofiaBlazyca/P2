// Zofia Blazyca

// Program sorting an array using quicksort or mergesort
// Program assumes the existence of file "liczby.txt" with numbers to sort
// before starting the program, the path in line 41 should be modified

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
    cout << "Enter the name of the file with data:";
    cin >> nazwa;
    while(nazwa != "liczby.txt")
    {
        cout << "Wrong name! Enter once again: ";
        cin >> nazwa;
    }

    // wybieranie sposobu sortowania
    int nrSortowania;
    cout << "Choose the sorting method:" << endl;
    cout << "1 - Quicksort" << endl;
    cout << "2 - Mergesort" << endl;
    cin >> nrSortowania;
    while(nrSortowania != 1 && nrSortowania != 2)
    {
        cout << "Wrong number! Enter once again: ";
        cin >> nrSortowania;
    }

    // operating on the file and creating an array using pointer
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

    // checking the input
    cout << "Array before sorting:" << endl;
    for(int i = 0; i < liczbaElementow; i++)
    {
        cout << tab[i] << " ";
    }
    cout << endl << endl;

    //choosing appropriate function
    if(nrSortowania == 1)
    {
        sortuj(tab, 0, liczbaElementow - 1, liczbaElementow);
    }
    else
    {
        sortuj(0, liczbaElementow - 1, liczbaElementow, tab);
    }

    cout << "Sorted array:" << endl;
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
    // quicksort recursive

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
    cout << "Array after the next step of sorting:" << endl;
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
    // mergesort recursive
    if (lewy < prawy)
    {
        int srodek = lewy + (prawy - lewy) / 2;

        sortuj(lewy, srodek, liczbaElementow, tab);
        sortuj(srodek + 1, prawy, liczbaElementow, tab);

        cout << "Array after the next step of sorting:" << endl;
        for(int i = 0; i < liczbaElementow; i++)
        {
            cout << tab[i] << " ";
        }
        cout << endl << endl;

        polacz(tab, lewy, srodek, prawy);
    }
}
