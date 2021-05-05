class Solution
{
public:
    int sumOddLengthSubarrays(vector<int> &arr)
    {
        int overall_sum = 0, sum = 0;
        int n = arr.size();

        for (int i = 0; i < n; ++i)
        {
            sum = 0;
            for (int j = i; j < n; ++j)
            {
                sum += arr[j];
                if ((j - i) % 2 == 0)
                {
                    overall_sum += sum;
                }
            }
        }

        return overall_sum;
    }
};