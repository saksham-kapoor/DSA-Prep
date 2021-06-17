// LONGEST COMMON SUBSEQUENCE USING LONGEST INCREASING SUBSEQUENCE
// WORKS ONLY BECAUSE WE HAVE DISTINCT ELEMENTS IN THE TARGET ARRAY

class Solution
{
public:
    int minOperations(vector<int> &target, vector<int> &A)
    {
        unordered_map<int, int> mp;

        for (auto &t : target)
            mp[t] = mp.size();

        vector<int> lis;

        for (auto &i : A)
        {
            auto it = mp.find(i);
            if (it != mp.end())
            {
                int idx = lower_bound(lis.begin(), lis.end(), it->second) - lis.begin();
                if (idx < lis.end() - lis.begin())
                    lis[idx] = it->second;
                else
                    lis.push_back(it->second);
            }
        }

        return target.size() - lis.size();
    }
};