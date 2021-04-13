class Solution
{
public:
    vector<int> constructArray(int n, int k)
    {
        vector<int> ans;
        int i = 2, j = n;
        ans.push_back(1);

        int p = 1;
        while (k != 1)
        {
            if (p & 1)
                ans.push_back(j--);
            else
                ans.push_back(i++);
            k = k - 1;
            p = p + 1;
        }

        p = p - 1;

        while (ans.size() != n)
        {
            if (p & 1)
                ans.push_back(j--);
            else
                ans.push_back(i++);
        }

        return ans;
    }
};