class Solution
{
public:
    vector<int> getBiggestThree(vector<vector<int>> &grid)
    {
        int m = grid.size(), n = grid[0].size();
        set<int> st;

        // to calculate sum in O(1) make prefix and suffix array
        int left[m + 1][n + 1], right[m + 1][n + 1];
        memset(left, 0, sizeof(left));
        memset(right, 0, sizeof(right));

        for (int j = 0; j < n; ++j)
        { // col
            for (int i = 0; i < m; ++i)
            { // row
                // left
                left[i][j + 1] = grid[i][j] + left[i + 1][j];

                // right
                right[i][n - j - 1] = grid[i][n - j - 1] + right[i + 1][n - j];

                st.insert(grid[i][j]);
                if (st.size() > 3)
                    st.erase(st.begin());
            }
        }

        // Now we can have to make all possible rhombuses and store in set
        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                int max_len = min(j, min(n - j - 1, (m - i - 1) / 2));

                for (int k = 1; k <= max_len; ++k)
                {
                    int res = 0;
                    // calculate perimeter

                    res += right[i][j] - right[i + k + 1][j + k + 1];
                    res += right[i + k][j - k] - right[i + k + k + 1][j + 1];
                    res += left[i][j + 1] - left[i + k + 1][j - k];
                    res += left[i + k][j + k + 1] - left[i + k + k + 1][j];
                    res -= (grid[i][j] + grid[i + k][j + k] + grid[i + k][j - k] + grid[i + k + k][j]);

                    st.insert(res);
                    if (st.size() > 3)
                        st.erase(st.begin());
                }
            }
        }

        return vector<int>(st.rbegin(), st.rend());
    }
};