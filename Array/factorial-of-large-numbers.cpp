#include <iostream>
#include <vector>
using namespace std;

void printRevArray(vector<int> A, int n)
{
    for (int i = n - 1; i >= 0; i--)
        cout << A[i];
    cout << "\n";
}

void printFact(int n)
{
    vector<int> vals(10000, 0);
    int size = 1, i = 2;
    vals[0] = 1;
    while (i <= n)
    {
        int carry = 0, j;
        for (j = 0; j < vals.size(); j++)
        {
            if (carry == 0 && vals[j] == 0 && j >= size)
                break;
            vals[j] *= i;
            vals[j] += carry;
            carry = vals[j] / 10;
            vals[j] %= 10;
        }
        size = j;
        i++;
    }
    printRevArray(vals, size);
}

int main()
{
    int T;
    cin >> T;
    while (T)
    {
        int n;
        cin >> n;
        printFact(n);
        T--;
    }
    return 0;
}