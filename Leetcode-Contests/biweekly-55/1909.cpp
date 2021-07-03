// O(N) 1 Pass solution
// whenever, there is a conflict
// i.e A[i - 1] >= A[i]
// this means that we will have to remove either A[i] or A[i - 1]
// how?

// suppose A[i - 2] < A[i] so we don't need A[i - 1], ++cnt;
// or
// A[i - 2] >= A[i], so we replace A[i] with A[i - 1], ++cnt;
class Solution
{
public:
    bool canBeIncreasing(vector<int> &A)
    {
        int cnt = 0;

        for (int i = 1; i < A.size(); ++i)
        {
            if (A[i] <= A[i - 1]) // conflict
            {
                if (++cnt == 2)
                    return false;

                if (i > 1 && A[i - 2] >= A[i])
                    A[i] = A[i - 1];
            }
        }

        return true;
    }
};

// Super Intuitive Solution!
// LIS >= A.size() - 1
// O(NlogN) solution
class Solution
{
public:
    bool canBeIncreasing(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> t;

        for (int i = 0; i < n; ++i)
        {
            auto it = lower_bound(begin(t), end(t), nums[i]);
            if (it == t.end())
                t.push_back(nums[i]);
            else
                *it = nums[i];
        }

        return t.size() >= nums.size() - 1;
    }
};