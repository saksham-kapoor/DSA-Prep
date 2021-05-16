class FindSumPairs
{
    vector<int> one;
    vector<int> t;
    unordered_map<int, int> two;

public:
    FindSumPairs(vector<int> &nums1, vector<int> &nums2)
    {
        one = nums1;
        t = nums2;
        for (auto &i : nums2)
        {
            two[i]++;
        }
    }

    void add(int index, int val)
    {
        two[t[index]]--;
        t[index] += val;
        two[t[index]]++;
    }

    int count(int tot)
    {
        int pairs = 0;

        for (int i = 0; i < one.size(); ++i)
        {
            int target = tot - one[i];
            pairs += two[target];
        }

        return pairs;
    }
};