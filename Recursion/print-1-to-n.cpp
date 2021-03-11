#include <iostream>
using namespace std;

void print1toN(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    print1toN(n - 1);
    cout << n << " ";
}

void printNto1(int n)
{
    if (n == 1)
    {
        cout << n << " ";
        return;
    }
    cout << n << " ";
    printNto1(n - 1);
}

int main()
{
    int n = 7;
    print1toN(n);
    cout << "\n";
    printNto1(n);
    return 0;
}