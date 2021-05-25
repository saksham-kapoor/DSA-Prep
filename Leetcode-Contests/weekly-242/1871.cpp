// BFS Solution -> O(n) solution!
class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        if (s.back() == '1')
            return false;

        int n = s.size(), reach = 0;
        queue<int> q;
        q.push(0);

        while (q.size())
        {
            int start = q.front();
            q.pop();

            if (start == n - 1)
                return true;

            for (int i = max(reach, start + minJump); i <= min(n - 1, start + maxJump); ++i)
            {
                if (s[i] == '0')
                    q.push(i);
            }

            reach = min(n - 1, start + maxJump);
        }

        return false;
    }
};

// Sliding Window Method!-> O(n)
class Solution
{
public:
    bool canReach(string s, int minJump, int maxJump)
    {
        if (s.back() == '1')
            return false;

        int n = s.size(), cnt = 0;

        vector<bool> dp(n, false);
        dp[0] = true;

        for (int i = 1; i < n; ++i)
        {
            if (i >= minJump)
                cnt += dp[i - minJump];
            if (i > maxJump)
                cnt -= dp[i - maxJump - 1];
            dp[i] = cnt > 0 && s[i] == '0';
        }

        return dp[n - 1];
    }
};

// O(nlogN) Solution!
class Solution
{
public:
    bool canReach(string s, int minJ, int maxJ)
    {
        int n = s.size();

        if (s[n - 1] == '1')
            return false;

        set<int> st;
        st.insert(n - 1);

        for (int i = n - 2; i >= 0; --i)
        {
            if (s[i] == '1')
                continue;

            auto pos = st.lower_bound(i + minJ);
            if (pos == st.end() || *pos > min(n - 1, i + maxJ))
                continue;
            st.insert(i);
        }

        if (st.find(0) != st.end())
            return true;
        return false;
    }
};