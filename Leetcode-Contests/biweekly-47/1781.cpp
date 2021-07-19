// Always focus on how to minize operations

class Solution
{
public:
    int beautySum(string s)
    {
        int res = 0;

        for (int i = 0; i < s.size(); ++i)
        {
            int cnt[26] = {}, min_f = 0, max_f = 0;

            for (int j = i; j < s.size(); ++j)
            {
                int curr = s[j] - 'a';
                max_f = max(max_f, ++cnt[curr]);

                if (min_f >= cnt[curr] - 1) // minimize eredundant operations
                {
                    min_f = cnt[curr];
                    for (int i = 0; i < 26; ++i)
                    {
                        if (cnt[i] > 0)
                        {
                            min_f = min(min_f, cnt[i]);
                        }
                    }
                }

                res += max_f - min_f;
            }
        }

        return res;
    }
};