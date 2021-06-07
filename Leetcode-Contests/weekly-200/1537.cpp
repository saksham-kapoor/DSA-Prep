// 2 pointer approach
// O(n) time, O(1) space
class Solution
{
    const static int MOD = 1e9 + 7;

public:
    int maxSum(vector<int> &A, vector<int> &B)
    {
        int i = 0, j = 0;
        long sumA = 0, sumB = 0, sum = 0;

        while (i < A.size() && j < B.size())
        {
            if (A[i] < B[j])
                sumA += A[i++];
            else if (A[i] > B[j])
                sumB += B[j++];
            else
            {
                sum += max(sumA, sumB) + A[i];
                sumA = sumB = 0;
                ++i;
                ++j;
            }
        }

        while (i < A.size())
            sumA += A[i++];

        while (j < B.size())
            sumB += B[j++];

        sum += max(sumA, sumB);

        return sum % MOD;
    }
};

// Recursive Solution => Slow
// O(n) space, O(n) time average
// DFS + MEMO
class Solution
{
    const static int MOD = 1e9 + 7;
    unordered_map<int, int> arr1, arr2;
    array<vector<int>, 2> AB;
    long dp[2][(int)(1e5 + 1)];

    long solve(int arrIdx, int idx)
    {
        if (idx >= AB[arrIdx].size())
            return 0;

        if (dp[arrIdx][idx] != -1)
            return dp[arrIdx][idx];

        long ans = AB[arrIdx][idx] + solve(arrIdx, idx + 1);

        if (arrIdx == 0)
        {
            if (arr2.find(AB[arrIdx][idx]) != arr2.end())
            {
                ans = max(ans, AB[arrIdx][idx] + solve(1, arr2[AB[arrIdx][idx]]));
            }
        }
        else
        {
            if (arr1.find(AB[arrIdx][idx]) != arr1.end())
            {
                ans = max(ans, AB[arrIdx][idx] + solve(0, arr1[AB[arrIdx][idx]]));
            }
        }

        return dp[arrIdx][idx] = ans;
    }

public:
    int maxSum(vector<int> &A, vector<int> &B)
    {
        int i = 0, j = 0, n = A.size(), m = B.size();
        memset(dp, -1, sizeof(dp));

        // save duplicates in map
        while (i < n && j < m)
        {
            if (A[i] == B[j])
            {
                arr1[A[i]] = i + 1;
                arr2[B[j]] = j + 1;
                ++i;
                ++j;
            }
            else if (A[i] < B[j])
                ++i;
            else
                ++j;
        }

        AB[0] = A;
        AB[1] = B;

        long res = max(solve(0, 0), solve(1, 0));
        return res % MOD;
    }
};