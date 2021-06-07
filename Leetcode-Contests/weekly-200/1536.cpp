// Greedy Swap
// o(n^2) time

class Solution
{
    int minSwaps(int curr[], int n)
    {
        int swaps = 0;

        // calculating swaps
        for (int i = 0; i < n - 1; ++i)
        {
            int find = n - i - 1, j = i, cur = 0;

            for (; j < n; ++j)
            {
                if (curr[j] >= find)
                    break;
            }

            if (j == n)
                return -1;

            while (i != j)
            {
                swap(curr[j - 1], curr[j]);
                ++swaps;
                --j;
            }
        }

        return swaps;
    }

public:
    int minSwaps(vector<vector<int>> &grid)
    {
        int n = grid.size();

        int curr[n];
        for (int i = 0; i < n; ++i)
        {
            int zeros = 0;

            for (int j = n - 1; j >= 0; --j)
            {
                if (grid[i][j] != 0)
                    break;
                zeros++;
            }

            curr[i] = min(zeros, n - 1);
        }

        return minSwaps(curr, n);
    }
};