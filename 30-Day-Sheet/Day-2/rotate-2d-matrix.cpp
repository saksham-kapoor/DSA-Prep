/*

Intuition - Rotating a matrix made all rows as columns and vice-versa.
            This is same as the transpose property.
            So, take a transpose and then move accordingly.

General Method for Matrix rotation 90deg -

    1. Take the transpose
    2. Reverse all rows

    OR

    1. Reverse all columns
    2. Take the transpose

    Example -

    Original Array
    1 2 3
    4 5 6
    7 8 9

    Transpose
    1 4 7
    2 5 8
    3 6 9

    Required ans [Reverse all rows in transpose]
    7 4 1
    8 5 2
    9 6 3


*/

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        // transpose
        // swap all symmetrical elements except diagnols
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < i; j++)
                if (i != j)
                    swap(matrix[i][j], matrix[j][i]);

        // reverse all rows
        for (int i = 0; i < matrix.size(); i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

// Rotating Ring by Ring Solution
// Difficult to find positions
void rotate(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int a = 0;
    int b = n - 1;
    while (a < b)
    {
        for (int i = 0; i < (b - a); ++i)
        {
            swap(matrix[a][a + i], matrix[a + i][b]);
            swap(matrix[a][a + i], matrix[b][b - i]);
            swap(matrix[a][a + i], matrix[b - i][a]);
        }
        ++a;
        --b;
    }
}