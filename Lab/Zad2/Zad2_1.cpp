//Zofia Blazyca

// Program counting the change for purchase based on Polish coinage

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    float price = 0, amountPaid = 0;
    int change = 0;
    cout << "Enter the receivable for purchase: ";
    cin >> price;
    cout << "Enter the amount of money given to salesman: ";
    cin >> amountPaid;
    price *= 100;
    amountPaid *= 100;
    change = amountPaid - price;

    if(change < 0)
    {
        cout << "Don't fool the salesman. You don't have enough money." << endl;
        return 0;
    }
    stack<int> changeStack;
    changeStack.push(1); // 1 gr coin
    changeStack.push(2); // 2 gr coin
    changeStack.push(5); // 5 gr coin
    changeStack.push(10); // 10 gr coin
    changeStack.push(20); // 20 gr coin
    changeStack.push(50); // 50 gr coin
    changeStack.push(100); // 1 zl coin
    changeStack.push(200); // 2 zl coin
    changeStack.push(500); // 5 zl coin
    changeStack.push(1000); // 10 zl banknote
    changeStack.push(2000); // 20 zl banknote
    changeStack.push(5000); // 50 zl banknote
    changeStack.push(10000); // 100 zl banknote
    changeStack.push(20000); // 200 zl banknote
    changeStack.push(50000); // 500 zl banknote

    cout << "Change: " << endl;
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