// Simple o(n) sliding window solution
// Sliding window brings down complexity of brute solutions from o(n^2) to o(n)
class Solution
{
public:
    vector<int> decrypt(vector<int> &code, int k)
    {
        int n = code.size();
        vector<int> res(n, 0);

        if (k == 0)
            return res;

        int start = 1, end = k, sum = 0;
        if (k < 0)
        {
            k = -k;
            start = n - k;
            end = n - 1;
        }

        for (int i = start; i <= end; ++i)
            sum += code[i];

        // sliding window
        for (int i = 0; i < n; ++i)
        {
            res[i] = sum;
            sum -= code[start++ % n];
            sum += code[++end % n];
        }

        return res;
    }
};