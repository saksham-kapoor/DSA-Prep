class Solution
{
public:
    int findLatestStep(vector<int> &arr, int m)
    {
        int n = arr.size();

        int group[n + 2], count[n + 1];
        memset(group, 0, sizeof(group));
        memset(count, 0, sizeof(count));

        int ans = -1, step = 1;

        for (auto &i : arr)
        {
            int left = group[i - 1], right = group[i + 1];
            group[i] = group[i - left] = group[i + right] = left + right + 1;
            count[left]--;
            count[right]--;
            count[group[i]]++;

            if (count[m])
                ans = step;

            step++;
        }

        return ans;
    }
};