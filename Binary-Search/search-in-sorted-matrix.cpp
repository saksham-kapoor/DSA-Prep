// 2 Methods

// O(m+n)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int X)
    {
        int n = mat.size(), m = mat[0].size();
        if (n == 0 || m == 0)
            return false;

        int i = 0, j = m - 1;
        while (i < n && j >= 0)
        {
            int mid = mat[i][j];
            if (mid == X)
                return 1;
            else if (mid < X)
                i++;
            else
                j--;
        }

        return 0;
    }
};

// O(logn + logm)

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int X)
    {
        int n = mat.size(), m = mat[0].size();
        if (n == 0 || m == 0)
            return false;

        int l1 = 0, h1 = mat.size() - 1, _floor = -1;
        while (l1 <= h1)
        {
            int m1 = l1 + (h1 - l1) / 2;
            if (mat[m1][0] == X)
                return 1;
            else if (mat[m1][0] < X)
            {
                l1 = m1 + 1;
                _floor = m1;
            }
            else
                h1 = m1 - 1;
        }
        if (_floor == -1)
            return 0;
        int l2 = 0, h2 = mat[0].size() - 1;
        while (l2 <= h2)
        {
            int m2 = l2 + (h2 - l2) / 2;
            if (mat[_floor][m2] == X)
                return 1;
            else if (mat[_floor][m2] < X)
                l2 = m2 + 1;
            else
                h2 = m2 - 1;
        }
        return 0;
    }
};
