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