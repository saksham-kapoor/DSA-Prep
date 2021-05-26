/*
    Method 1 -> Find Split Position!
    split position will be the one with min(a's to the right + b's to the left)
    then ans = a's to the right + b's to the left
*/
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int cnt_a = 0, cnt_b = 0, n = s.size(), res = INT_MAX;

        // count total number of a's
        for (auto &c : s)
            cnt_a += c == 'a';

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'b')
            {
                res = min(res, cnt_b + cnt_a);
                ++cnt_b; // add as there is 1 more 'b' to the left
            }
            else
            {
                --cnt_a; // substract as now there is 1 less 'a' to the right
            }
        }

        return min(res, cnt_a + cnt_b);
    }
};

/*
    Method 2 -> Find Bad pairs
    Bad pair is a subsequence in s like 'ba'
    in this we either remove 'a' or 'b' to make it valid as string can only contain {aa..abbb.., aaa..., bbbb...}
    question reduces to 'count the number of bad pairs'
*/
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int bad_pairs = 0, cnt_b = 0;

        for (auto &c : s)
        {
            if (c == 'b')
                cnt_b++;
            else if (cnt_b > 0)
            {
                bad_pairs++;
                cnt_b--;
            }
        }

        return bad_pairs;
    }
};

/*
    Method 3 -> DP
    let dp[i] store the minimum number of deletions to make string[0...i] valid
    
    # dp[i + 1]
        if(s[i + 1] is 'a')
            2 options
                1) delete this a, dp[i + 1] = dp[i] + 1
                2) keep this a, and delete all b's to the left (if any) dp[i + 1] = cnt_b;
                therefore, dp[i + 1] = min(dp[i] + 1, cnt_b)
        else
            since dp[i] is valid
            we can simple add 'b' and it doesn't make the string invalid!
*/
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size(), cnt_b = 0;
        int dp[n + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'b')
            {
                dp[i + 1] = dp[i];
                cnt_b++;
            }
            else
            {
                dp[i + 1] = min(dp[i] + 1, cnt_b);
            }
        }

        return dp[n];
    }
};

/*
    Method 4 -> DP with O(1) space!
    since, while calculating dp[i + 1] we only care about dp[i] and no dp value before it
    so simple store prev dp and new dp in same same variable instead of array!
*/
class Solution
{
public:
    int minimumDeletions(string s)
    {
        int n = s.size(), cnt_b = 0;
        int dp = 0;

        for (int i = 0; i < n; ++i)
        {
            if (s[i] == 'b')
            {
                cnt_b++;
            }
            else
            {
                dp = min(dp + 1, cnt_b);
            }
        }

        return dp;
    }
};