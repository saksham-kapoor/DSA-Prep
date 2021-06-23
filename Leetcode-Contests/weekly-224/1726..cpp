// extremely fast vector + sort solution
class Solution
{
public:
    int tupleSameProduct(vector<int> &A)
    {
        vector<int> v;

        for (int i = 0; i < A.size(); ++i)
            for (int j = i + 1; j < A.size(); ++j)
                v.push_back(A[i] * A[j]);

        sort(v.begin(), v.end());
        int i = 0, j, cnt, res = 0;

        while (i < v.size())
        {
            j = i;
            cnt = 0;
            while (v[i] == v[j])
                ++cnt, ++j;
            i = j;
            res += (cnt) * (cnt - 1) / 2;
        }

        return res * 8;
    }
};

// unordered_map method
class Solution
{
public:
    int tupleSameProduct(vector<int> &nums)
    {
        unordered_map<int, int> mp;

        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                mp[nums[i] * nums[j]]++;

        int res = 0;
        for (auto &[m, cnt] : mp)
            res += cnt * (cnt - 1) / 2;

        return res * 8;
    }
};