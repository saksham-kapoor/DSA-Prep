/*

Very similar to search in sorted matrix - 1 problem

Only difference here is that the starting element of a row
may not be greater than the ending element of the previous row

Ex -

1 4 7
2 5 8
3 6 9

Therefore we cannot apply binary search on col 0 and then on the resultant row
Therefore we rule out TC of O(logm + logn)

Method -> O(m+n) method
          Clear solution, do a dry run  

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
            else if (target < matrix[i][j])
                j--;
            else
                i++;

        return false;
    }
};