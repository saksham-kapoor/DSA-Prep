// O(N) approach
// 1 pass

class Solution
{
public:
    int getWinner(vector<int> &arr, int k)
    {
        int n = arr.size();
        int curr = max(arr[0], arr[1]), streak = 1;

        if (k == 1)
            return curr;

        for (int i = 2; i < n; ++i)
        {
            if (arr[i] > curr)
            {
                streak = 1;
                curr = arr[i];
            }
            else
            {
                if (++streak == k)
                    return curr;
            }
        }

        return curr;
    }
};