class Solution
{
public:
    bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target)
    {
        int arr[3] = {};
        for (auto &t : triplets)
        {
            if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2])
                arr[0] = max(arr[0], t[0]), arr[1] = max(arr[1], t[1]), arr[2] = max(arr[2], t[2]);
        }

        for (int i = 0; i < 3; ++i)
            if (arr[i] != target[i])
                return false;

        return true;
    }
};