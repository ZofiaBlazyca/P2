// Zofia Blazyca

// Simulation of a river that consists of empty fields or containing bears or fish
// In each iteration it's picking randomly whether the animal is moving
// If a bear meets fish, the fish is being eaten
// If animals of the same species but different sex meet, a new animal is being created in a random field
// If animals of the same species and same sex meet, they fight and the stronger one survives

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
    virtual void show()
    {
        cout << "Bear " << power << " ";
        if(sex)
        {
            cout << "F" << endl;
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

    virtual void show()
    {
        cout << "Fish " << power << " ";
        if(sex)
        {
            cout << "F" << endl;
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
    cout << "The river in its initial state:" << endl;
    cout << "(Species, strength, sex)" << endl;
    for(int i = 0; i < riverSize; i++)
    {
        if(river[i] != nullptr)
            river[i]->show();
        else
            cout << "0" << endl;
    }
    // running the simulation 3 times
    for(int i = 0; i < 3; i++)
    {
        // iterating on the river
        for(int j = 0; j < riverSize; j++)
        {
            // checking if the field is empty
            if(river[j] == nullptr)
            {
                continue;
            }
            // picking randomly if the animal should be moving
            if(rand() % 2)
            {
                // picking randomly the direction
                if(rand() % 2 && j != 0)
                {
                    // checking if the previous field is empty
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
                    // checking if the previous field is empty
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
        cout << "The river after " << i+1 << " iteration:" << endl;
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