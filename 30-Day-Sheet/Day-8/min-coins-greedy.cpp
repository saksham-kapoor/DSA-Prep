#include <iostream>
#include <vector>
using namespace std;

void solve(vector<int> &coins, int val)
{
    int n = coins.size(), i = n - 1;

    cout << "Coins: ";
    while (val != 0)
    {
        if (coins[i] > val)
            --i;
        else
        {
            val -= coins[i];
            cout << coins[i] << " ";
        }
    }

    cout << "\n";
}

int main()
{

    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500};
    int val = 93;

    solve(coins, val);

    return 0;
}