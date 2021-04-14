/*

1   3   5   7
10  11  16  20
23  30  34  60

rows sorted -> asc order
cols sorted -> asc order

Keyword -> Sorted -> Intuition -> Binary Search

Method 1 -> 2 binary Searches
            let target = 16
            binary search on col 
            1
            10
            23
            we get 10 as largest value smaller than 16
            
            binary search on row starting with 10
            10 11 16 20
            if we get 16 return true else return false
            
            Time: O(logm + logn)
            
Method 2 -> Concept of Binary search is to neglect half the elements each time
            What if we do the same?
            
            Start at a corner of the matrix
            
            start at 7
            if target > 7 row++
            else col--
            
            OR
            
            start at 23
            if target > 23 col++
            else row--
            
            OR
            
            start at 1
            if target > 1, col++ or row++?????
            
            Therefore we do not start at 1 or 60
            
            i.e
            
            take starting index as [0][n-1] or [m-1][0]

*/

// o(logm + logn) Method
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &mat, int X)
    {
        int n = mat.size(), m = mat[0].size();
        if (n == 0 || m == 0)
            return false;

        // Applying binary search on col-0
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

        // _floor stores the row number of the largest element smaller than X
        if (_floor == -1) // If no smaller element present
            return 0;

        // Applying binary search on _floor row
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

// o(m + n) Method
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = n - 1;

        while (i < m && j >= 0)
            if (target == matrix[i][j])
                return true;
            else if (target > matrix[i][j])
                ++i;
            else
                --j;

        return false;
    }
};