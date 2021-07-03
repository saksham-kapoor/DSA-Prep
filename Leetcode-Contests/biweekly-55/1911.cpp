// SAME AS BUY SELL STOCK WITH UNLIMITED TRANSACTIONS
class Solution
{
public:
    long long maxAlternatingSum(vector<int> &A)
    {
        long long res = A[0];

        for (int i = 1; i < A.size(); ++i)
            res += max(0, A[i] - A[i - 1]);

        return res;
    }
};

// Recursion + Memoization
// at each idx we have 2 options, take this element and invert sign for next element
// or
// leave this element and keep the sign same for next element
class Solution
{
    long long dp[2][100005];

    long long solve(int idx, vector<int> &A, bool pos)
    {
        if (idx == A.size())
            return 0;

        if (dp[pos][idx] != -1)
            return dp[pos][idx];

        int curr = pos ? A[idx] : -A[idx];
        long long res1 = solve(idx + 1, A, pos);
        long long res2 = curr + solve(idx + 1, A, !pos);

        return dp[pos][idx] = max(res1, res2);
    }

public:
    long long maxAlternatingSum(vector<int> &nums)
    {
        memset(dp, -1, sizeof(dp));
        return solve(0, nums, 1);
    }
};

// dp tabulation
class Solution
{
public:
    long long maxAlternatingSum(vector<int> &A)
    {
        long long dp[2][100005];
        // dp[sign][idx] = max value till A[idx] with sign of A[idx] as sign
        // dp[sign][idx] = max(dp[sign][idx - 1], dp[!sign][idx - 1] + sign == 1 ? A[idx] : -A[idx]);

        dp[0][0] = 0;
        dp[1][0] = A[0];

        for (int i = 1; i < A.size(); ++i)
        {
            dp[0][i] = max(dp[0][i - 1], -A[i] + dp[1][i - 1]);
            dp[1][i] = max(dp[1][i - 1], A[i] + dp[0][i - 1]);
        }

        return max(dp[0][A.size() - 1], dp[1][A.size() - 1]);
    }
};

// O(1) space dp
// inspired by prev solution
class Solution
{
public:
    long long maxAlternatingSum(vector<int> &A)
    {
        long long neg = 0, pos = A[0];
        // odd -> max value taking A[i] as negative element
        // even -> max value taking A[i] as positive element

        for (int i = 1; i < A.size(); ++i)
        {
            long long newPos = max(pos, neg + A[i]);
            neg = max(neg, pos - A[i]);
            pos = newPos;
        }

        return max(neg, pos);
    }
};