// Optimised Method cannot be used to solve this as constraints are very high, check 'permutation sequence' for better method

string Solution::getPermutation(int n, int k)
{
    string res;
    vector<int> nums;

    for (int i = 1; i <= n; ++i)
        nums.push_back(i);

    for (int i = 0; i < k - 1; ++i)
        next_permutation(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); ++i)
        res += to_string(nums[i]);

    return res;
}
