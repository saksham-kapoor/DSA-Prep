// In place checking, O(n^2) but way faster
// eliminating invalid rotations
// https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/discuss/1254089/c-straightforward-solution-comparing-in-place/964028
class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        int n = mat.size();
        array<bool, 4> c = {1, 1, 1, 1};

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (mat[i][j] != target[i][j])
                    c[0] = false; // same place
                if (mat[i][j] != target[j][n - i - 1])
                    c[1] = false; // 90deg
                if (mat[i][j] != target[n - i - 1][n - j - 1])
                    c[2] = false; // 180 deg
                if (mat[i][j] != target[n - j - 1][i])
                    c[3] = false; // 270 deg
            }
        }

        return c[0] || c[1] || c[2] || c[3];
    }
};

// Simple Rotate and Check Approach O(n^2) time, O(1) space
class Solution
{
    void rotate(vector<vector<int>> &mat)
    {
        int n = mat.size();

        for (int i = 0; i < n; ++i)
            for (int j = i + 1; j < n; ++j)
                swap(mat[i][j], mat[j][i]);

        for (int i = 0; i < n; ++i)
            reverse(mat[i].begin(), mat[i].end());
    }

public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        if (mat == target)
            return true;

        for (int i = 0; i < 3; ++i)
        {
            rotate(mat);
            if (mat == target)
                return true;
        }

        return false;
    }
};