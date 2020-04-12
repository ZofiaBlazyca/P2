#include <iostream>
#include <stack>

using namespace std;

int main()
{
    float price = 0, amountPaid = 0;
    int change = 0;
    cout << "Podaj kwote nalezna za zakupy: ";
    cin >> price;
    cout << "Podaj kwote podana sprzedawcy: ";
    cin >> amountPaid;
    price *= 100;
    amountPaid *= 100;
    change = amountPaid - price;

    if(change < 0)
    {
        cout << "Nie oszukuj kasjera. Masz za malo pieniedzy." << endl;
        return 0;
    }
    stack<int> changeStack;
    changeStack.push(1); // moneta 1 gr
    changeStack.push(2); // moneta 2 gr
    changeStack.push(5); // moneta 5 gr
    changeStack.push(10); // moneta 10 gr
    changeStack.push(20); // moneta 20 gr
    changeStack.push(50); // moneta 50 gr
    changeStack.push(100); // moneta 1 zl
    changeStack.push(200); // moneta 2 zl
    changeStack.push(500); // moneta 5 zl
    changeStack.push(1000); // banknot 10 zl
    changeStack.push(2000); // banknot 20 zl
    changeStack.push(5000); // banknot 50 zl
    changeStack.push(10000); // banknot 100 zl
    changeStack.push(20000); // banknot 200 zl
    changeStack.push(50000); // banknot 500 zl

    cout << "Reszta: " << endl;
    while(!changeStack.empty())
    {
        int amount = change / changeStack.top();
        if(amount != 0)
        {
            cout << changeStack.top() / 100.f << ": ";
            cout << amount << endl;
        }
        change %= changeStack.top();
        changeStack.pop();
    }

    return 0;
}