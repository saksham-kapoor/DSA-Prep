// O(n^3) solution

class Solution
{
public:
    int countGoodTriplets(vector<int> &ar, int a, int b, int c)
    {
        int count = 0, n = ar.size();
        for (int i = 0; i < n - 2; ++i)
        {
            for (int j = i + 1; j < n - 1; ++j)
            {
                for (int k = j + 1; k < n; ++k)
                {
                    if (abs(ar[i] - ar[j]) <= a && abs(ar[j] - ar[k]) <= b && abs(ar[i] - ar[k]) <= c)
                        ++count;
                }
            }
        }
        return count;
    }
};