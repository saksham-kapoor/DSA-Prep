// Using Vector as stack solution!
class Solution
{
public:
    vector<int> mostCompetitive(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> st;

        for (int i = 0; i < n; ++i)
        {
            int can_add = n - i;

            while (st.size() && st.back() > nums[i] && st.size() + can_add > k)
                st.pop_back();

            if (st.size() < k)
                st.push_back(nums[i]);
        }

        return st;
    }
};