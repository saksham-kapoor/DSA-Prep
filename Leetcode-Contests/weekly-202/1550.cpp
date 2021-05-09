class Solution
{
public:
    bool threeConsecutiveOdds(vector<int> &arr)
    {
        int n = arr.size();
        if (n <= 2)
            return false;

        int count = 0;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] % 2 == 0)
                count = 0;
            else if (++count == 3)
                return true;
        }

        return false;
    }
};