#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;

ll t[250];

ll fibonacci(int n)
{
    if (t[n] != -1)
        return t[n];
    return t[n] = fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n = 50;
    memset(t, -1, sizeof(t));
    t[0] = 0;
    t[1] = 1;
    cout << fibonacci(n) << "\n";
    return 0;
}