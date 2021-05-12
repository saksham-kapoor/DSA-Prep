class Solution
{
public:
    int maxCoins(vector<int> &A)
    {
        sort(A.begin(), A.end());
        int n = A.size();

        // each of us will get a pile of n/3
        // we leave the smallest pile for bob
        int sum = 0;

        for (int i = n / 3; i < n; i += 2)
        {
            sum += A[i];
        }

        return sum;
    }
};