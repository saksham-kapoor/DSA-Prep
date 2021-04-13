/*

Method 1 -> Traverse entire matrix

            Make 2 unordered_sets -> rows, cols
            if(matrix[i][j] == 0) rows.insert(i), cols.insert(j)

            Traverse again
            if(rows.find(i) != rows.end() || cols.find(j) != cols.end())
                matrix[i][j] = 0;
            
            Time: O(m*n)
            Space: O(m+n)

Method 2 -> Concept similar to Method 1
            
            Here, instead of making 2 sets to mark rows and cols
            if we mark it on the first element of each row/col

            1 1 1
            1 0 1
            1 1 1

            first traverse, row 0 and col 0, and store if they should be set to zero
            in booleans row0, col0

            then traverse entire matrix except row 0 and col 0
            and mark the first element of row/col

            1 0 1
            0 0 1
            1 1 1

            as matrix[1][1] == 0
            we mark -> matrix[1][0] = matrix[0][1] = 0

            now we traverse again
            and mark matrix[i][j] = 0 if (matrix[i][0] == 0 || matrix[0][j] == 0)

            1 0 1
            0 0 0
            1 0 1

*/

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size(), n = matrix[0].size();
        bool set_row_0_to_zero = false, set_col_0_to_zero = false;

        // traversing row 0
        for (int j = 0; j < n; j++)
            if (matrix[0][j] == 0)
            {
                set_row_0_to_zero = true;
                break;
            }

        // traversing col 0
        for (int i = 0; i < m; i++)
            if (matrix[i][0] == 0)
            {
                set_col_0_to_zero = true;
                break;
            }

        // traversing entire matrix except row 0, col 0
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[i][j] == 0)
                    matrix[i][0] = matrix[0][j] = 0;

        // traversing entire matrix except row 0, col 0
        for (int i = 1; i < m; i++)
            for (int j = 1; j < n; j++)
                if (matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0;

        // traversing row 0
        if (set_row_0_to_zero)
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;

        // traversing col 0
        if (set_col_0_to_zero)
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
    }
};