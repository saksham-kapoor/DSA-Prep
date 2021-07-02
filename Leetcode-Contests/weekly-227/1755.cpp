// Meet in the middle method!
// if constraints around 40 and you have to do 2^N solution, simply divide the array in 2 parts
// calculate 2^(N/2) two times
// then sort second array
// then traverse over array 1 and binary search in array 2

class Solution
{
    void dfs(long sum, int idx, int end, vector<int> &A, long B[], int &i)
    {
        if (idx == end + 1)
        {
            B[i++] = sum;
            return;
        }
        dfs(sum, idx + 1, end, A, B, i);
        dfs(sum + A[idx], idx + 1, end, A, B, i);
    }

public:
    int minAbsDifference(vector<int> &nums, int goal)
    {
        int n = nums.size();
        long res = LONG_MAX;

        long A[(1 << 20) + 2], B[(1 << 20) + 2];
        int i = 0, j = 0;

        dfs(0l, 0, n / 2 - 1, nums, A, i);
        dfs(0l, n / 2, n - 1, nums, B, j);

        sort(B, B + j);

        for (int ii = 0; ii < i; ++ii)
        {
            int find = goal - A[ii];
            int it = lower_bound(B, B + j, find) - B;

            if (it != j)
                res = min(res, (long)abs(A[ii] + B[it] - goal));

            if (--it >= 0)
                res = min(res, (long)abs(A[ii] + B[it] - goal));
        }

        return res;
    }
};