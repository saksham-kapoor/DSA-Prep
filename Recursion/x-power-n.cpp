#include <iostream>
using namespace std;

int xPowerN(int x, int n)
{
    if (n == 1)
        return x;
    return x * xPowerN(x, n - 1);
}

int main()
{
    int x = 2, n = 11;
    cout << xPowerN(x, n) << "\n";
    return 0;
}