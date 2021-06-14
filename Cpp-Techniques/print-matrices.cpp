#include <iostream>
using namespace std;

int main()
{
    int mat[5][5] = {};

    // main
    for (auto &r : mat)
    {
        for (auto &c : r)
            cout << c << " ";
        cout << "\n";
    }

    cout << "\n";

    return 0;
}