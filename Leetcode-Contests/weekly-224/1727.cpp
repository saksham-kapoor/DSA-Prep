// amazing question
class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size(), res = 0;

        for (int i = 0; i < n; ++i)
            for (int j = 1; j < m; ++j)
                if (mat[j][i] == 1)
                    mat[j][i] += mat[j - 1][i];

        for (int i = m - 1; i >= 0; --i)
        {
            sort(mat[i].begin(), mat[i].end(), greater<int>());

            for (int k = 0; k < n && mat[i][k] > 0; ++k)
                res = max(res, mat[i][k] * (k + 1));
        }

        return res;
    }
};

// slight refactoring
class Solution
{
public:
    int largestSubmatrix(vector<vector<int>> &mat)
    {
        int m = mat.size(), n = mat[0].size(), res = 0;
        vector<int> heights;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n && i != 0; ++j)
                mat[i][j] += mat[i][j] == 1 ? mat[i - 1][j] : 0;

            heights = mat[i];
            sort(heights.begin(), heights.end(), greater<int>());

            for (int k = 0; k < n && heights[k] > 0; ++k)
                res = max(res, heights[k] * (k + 1));
        }

        return res;
    }
};