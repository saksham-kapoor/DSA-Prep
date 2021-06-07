// PRIORITY QUEUE SOLUTION
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        int n = nums.size(), res = INT_MAX, min_val = INT_MAX;
        priority_queue<int> pq;

        for (auto &i : nums)
        {
            if (i & 1)
                i <<= 1;

            pq.push(i);
            min_val = min(min_val, i);
        }

        while (pq.top() % 2 == 0)
        {
            pq.push(pq.top() / 2);
            min_val = min(min_val, pq.top() / 2);
            pq.pop();
            res = min(res, pq.top() - min_val);
        }

        return res;
    }
};

// SET SOLUTION
class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        int n = nums.size(), diff = INT_MAX;

        for (int i = 0; i < nums.size(); ++i)
            if (nums[i] & 1)
                nums[i] <<= 1;

        set<int> st(nums.begin(), nums.end());

        while (*(st.rbegin()) % 2 == 0)
        {
            diff = min(diff, *(st.rbegin()) - *(st.begin()));
            st.insert(*(st.rbegin()) / 2);
            st.erase(prev(st.end()));
        }

        diff = min(diff, *(st.rbegin()) - *(st.begin()));

        return diff;
    }
};