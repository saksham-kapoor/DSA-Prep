#include <iostream>
using namespace std;

int main()
{
    int m = 5, n = 5;
    int mat[5][5] = {
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5},
        {1, 2, 3, 4, 5}};

    int row[7][7] = {}, col[7][7] = {}, d1[7][7] = {}, d2[7][7] = {}, sum[7][7] = {};

    // main code
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            row[i][j] = mat[i - 1][j - 1] + row[i][j - 1];
            col[i][j] = mat[i - 1][j - 1] + col[i - 1][j];
            d1[i][j] = mat[i - 1][j - 1] + d1[i - 1][j - 1];
            d2[i][j] = mat[i - 1][j - 1] + d2[i - 1][j + 1];
            sum[i][j] = mat[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
        }
    }

    // print all matrices
    // row prefix
    for (auto &r : row)
    {
        for (auto &c : r)
            cout << c << "\t";
        cout << "\n";
    }

    cout << "\n";

    // col prefix
    for (auto &r : col)
    {
        for (auto &c : r)
            cout << c << "\t";
        cout << "\n";
    }

    cout << "\n";

    // d1 prefix
    for (auto &r : d1)
    {
        for (auto &c : r)
            cout << c << "\t";
        cout << "\n";
    }

    cout << "\n";

    // row prefix
    for (auto &r : d2)
    {
        for (auto &c : r)
            cout << c << "\t";
        cout << "\n";
    }

    cout << "\n";

    // sum prefix
    for (auto &r : sum)
    {
        for (auto &c : r)
            cout << c << "\t";
        cout << "\n";
    }

    return 0;
}