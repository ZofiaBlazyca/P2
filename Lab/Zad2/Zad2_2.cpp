#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

const static int riverSize = 20;

class Animal
{
public:
    Animal()
    {
        sex = rand() % 2;
        power = (rand() % 100 + 1) / 10.f;
    }
    bool sex;
    float power;
    void meetAnimal(Animal** tab, int myPosition, int anotherPosition);
    virtual void show() = 0;
    virtual bool isBear()
    {
        return false;
    }
};

class Bear: public Animal
{
public:
    Bear(): Animal()
    {

    }
    virtual void meetFish(Animal* animal, Animal** tab)
    {

    }
    virtual void meetBear(Animal* animal)
    {

    }
    virtual void show()
    {
        cout << "B " << power << " ";
        if(sex)
        {
            cout << "K" << endl;
        } else
        {
            cout << "M" << endl;
        }
    }
    virtual bool isBear()
    {
        return true;
    }
};

class Fish: public Animal
{
public:
    Fish(): Animal()
    {

    }
    virtual void meetFish(Animal* animal)
    {

    }
    virtual void needBear(Animal* animal)
    {

    }
    virtual void show()
    {
        cout << "F " << power << " ";
        if(sex)
        {
            cout << "K" << endl;
        } else
        {
            cout << "M" << endl;
        }
    }
};

void Animal::meetAnimal(Animal **tab, int myPosition, int anotherPosition)
{
    if(tab[myPosition]->isBear() == tab[anotherPosition]->isBear())
    {
        if(tab[myPosition]->sex == tab[anotherPosition]->sex)
        {
            if(tab[myPosition]->power > tab[anotherPosition]->power)
            {
                delete(tab[anotherPosition]);
                tab[anotherPosition] = tab[myPosition];
                tab[myPosition] = nullptr;
            } else
            {
                delete(tab[myPosition]);
                tab[myPosition] = nullptr;
            }
        } else
        {
            vector<int> freePositions;
            for(int i = 0; i < riverSize; i++)
            {
                if(tab[i] == nullptr)
                {
                    freePositions.push_back(i);
                }
            }
            if(freePositions.empty())
            {
                return;
            }
            if(tab[myPosition]->isBear())
            {
                tab[freePositions[rand() % freePositions.size()]] = new Bear();
            } else
            {
                tab[freePositions[rand() % freePositions.size()]] = new Fish();
            }
        }
    } else
    {
        if(tab[myPosition]->isBear())
        {
            delete(tab[anotherPosition]);
            tab[anotherPosition] = tab[myPosition];
            tab[myPosition] = nullptr;
        } else
        {
            delete(tab[myPosition]);
            tab[myPosition] = nullptr;
        }
    }
}
int main()
{
    srand(time(NULL));
    Animal* river[riverSize];

    for(int i = 0; i < riverSize; i++)
    {
        int pole = rand() % 3;
        switch(pole)
        {
            case 0:
            {
                river[i] = nullptr;
                break;
            }
            case 1:
            {
                river[i] = new Bear();
                break;
            }
            case 2:
            {
                river[i] = new Fish();
                break;
            }
        }
    }
    cout << "Rzeka w stanie poczatkowym:" << endl;
    for(int i = 0; i < riverSize; i++)
    {
        if(river[i] != nullptr)
            river[i]->show();
        else
            cout << "0" << endl;
    }
    // wykowywanie symulacji 3 razy
    for(int i = 0; i < 3; i++)
    {
        // przechodzenie po calej rzece
        for(int j = 0; j < riverSize; j++)
        {
            // sprawdzanie czy pole nie jest puste
            if(river[j] == nullptr)
            {
                continue;
            }
            // losowanie czy zwierze ma sie ruszac
            if(rand() % 2)
            {
                // losowanie w ktora strone sie poruszyc
                if(rand() % 2 && j != 0)
                {
                    // sprawdzanie czy poprzednie pole jest puste
                    if(river[j-1] == nullptr)
                    {
                        river[j-1] = river[j];
                        river[j] = nullptr;
                    }
                    else
                    {
                        river[j]->meetAnimal(river, j, j-1);
                    }
                } else
                {
                    // sprawdzanie czy poprzednie pole jest puste
                    if(river[j+1] == nullptr)
                    {
                        river[j+1] = river[j];
                        river[j] = nullptr;
                    }
                    else
                    {
                        river[j]->meetAnimal(river, j, j+1);
                    }
                }
            }
        }
        cout << "Rzeka po " << i+1 << " przejsciu:" << endl;
        for(int i = 0; i < riverSize; i++)
        {
            if(river[i] != nullptr)
                river[i]->show();
            else
                cout << "0" << endl;
        }
    }

    for(int i = 0; i < riverSize; i++)
    {
        delete(river[i]);
    }
    return 0;
}