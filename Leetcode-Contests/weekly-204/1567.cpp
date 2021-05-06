class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int maxlen = 0;
        int zero = -1, neg = -1;
        bool curr = true;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 0)
            {
                curr = true;
                zero = i;
                neg = -1;
                continue;
            }

            if (nums[i] < 0)
            {
                curr = !curr;
                if (neg == -1)
                    neg = i;
            }

            if (curr)
            {
                maxlen = max(maxlen, i - zero);
            }
            else
            {
                maxlen = max(maxlen, i - neg);
            }
        }

        return maxlen;
    }
};
