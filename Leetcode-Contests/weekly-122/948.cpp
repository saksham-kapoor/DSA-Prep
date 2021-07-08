// Greedy Approach
// Since, we are not able to find any example where greedy approach won't work, we go with greedy

class Solution
{
public:
    int bagOfTokensScore(vector<int> &t, int p)
    {
        int i = 0, j = t.size() - 1, score = 0, res = 0;
        sort(t.begin(), t.end());

        while (i <= j)
        {
            if (p >= t[i])
                ++score, p -= t[i++];
            else if (score >= 1)
                --score, p += t[j--];
            else
                break;

            res = max(res, score);
        }

        return res;
    }
};