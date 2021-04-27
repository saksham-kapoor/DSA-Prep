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