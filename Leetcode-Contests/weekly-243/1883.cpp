/*

dp[i][j] = min time of arrival
i -> roads
j -> number of skips
value => min time of arrival when we travel i roads with j jumps

dp[i][j] = (if i don't skip) ceil(dp[i - 1][j]) + d / s
           (if i skip) dp[i - 1][j - 1] + d / s

take min of the two

*/

// Original Approach
class Solution
{
    constexpr static double eps = 1e-9;
    double dp[1001][1001] = {};

    double total_time(int skips, int n, int max_skips, vector<int> &dist, int speed)
    {
        for (int i = 2; i <= n; ++i)
        {
            dp[i][skips] = min(dp[i - 1][skips - 1], ceil(dp[i - 1][skips] - eps)) + (double)dist[i - 1] / speed;
        }
        return dp[n][skips];
    }

public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore)
    {
        int n = dist.size(); // 0 ... n - 1
        int max_skips = n - 1;

        // double dp[n + 1][max_skips + 1]; // stores min time of arrival using 'i' roads and 'j' skips

        // let number of skips be 0
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = ceil(dp[i - 1][0] - eps) + (double)dist[i - 1] / speed;
        }

        if (dp[n][0] <= (double)hoursBefore)
            return 0;

        // let number of roads be 0
        for (int i = 1; i <= max_skips; ++i)
        {
            dp[1][i] = dp[1][i - 1];
        }

        for (int skips = 1; skips <= max_skips; ++skips)
        {
            double time_taken = total_time(skips, n, max_skips, dist, speed);
            if (time_taken <= (double)hoursBefore)
                return skips;
        }

        return -1;
    }
};

// Original But Without Extra Function
class Solution
{
    constexpr static double eps = 1e-9;
    double dp[1001][1001] = {};

public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore)
    {
        int n = dist.size(); // 0 ... n - 1
        int max_skips = n - 1;

        // let number of skips be 0
        for (int i = 1; i <= n; ++i)
        {
            dp[i][0] = ceil(dp[i - 1][0] - eps) + (double)dist[i - 1] / speed;
        }

        if (dp[n][0] <= (double)hoursBefore)
            return 0;

        // time taken by first road irrespective of skips
        for (int i = 1; i <= max_skips; ++i)
        {
            dp[1][i] = dp[1][i - 1];
        }

        // we calculate for 'k' skips, as soon as we find a possible answer, we return
        for (int skips = 1; skips <= max_skips; ++skips)
        {
            for (int i = 2; i <= n; ++i)
            {
                dp[i][skips] = min(dp[i - 1][skips - 1], ceil(dp[i - 1][skips] - eps)) + (double)dist[i - 1] / speed;
            }
            if (dp[n][skips] <= (double)hoursBefore)
                return skips;
        }

        return -1;
    }
};

// SPACE OPTIMIZED DP
class Solution
{
    constexpr static double eps = 1e-9;
    array<double, 1001> dp = {}, prev = {};

public:
    int minSkips(vector<int> &dist, int speed, int hoursBefore)
    {
        int n = dist.size(); // 0 ... n - 1
        int max_skips = n - 1;

        // let number of skips be 0
        for (int i = 1; i <= n; ++i)
        {
            prev[i] = ceil(prev[i - 1] - eps) + (double)dist[i - 1] / speed;
        }

        if (prev[n] <= (double)hoursBefore)
            return 0;

        // time taken by first road irrespective of skips
        dp[1] = prev[1];

        // we calculate for 'k' skips, as soon as we find a possible answer, we return
        for (int skips = 1; skips <= max_skips; ++skips)
        {
            for (int i = 2; i <= n; ++i)
            {
                dp[i] = min(prev[i - 1], ceil(dp[i - 1] - eps)) + (double)dist[i - 1] / speed;
            }
            if (dp[n] <= (double)hoursBefore)
                return skips;
            prev = dp;
        }

        return -1;
    }
};