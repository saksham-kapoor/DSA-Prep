#include <iostream>
#include <vector>
using namespace std;

// using memoization (dp)
int f(int n, vector<int> &qb)
{
    if (n <= 1)
        return n;
    if (qb[n] != -1)
        return qb[n];

    int k = f(n - 1, qb) + f(n - 2, qb);
    qb[n] = k;
    return k;
}

int main()
{
    int n = 10;
    vector<int> qb(n + 1, -1);
    cout << n << "th Fibonacci Number: " << f(n, qb);
    return 0;
}