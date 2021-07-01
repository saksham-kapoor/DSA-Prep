// Amazing Question!
// String questions, calculate prefix of fz
// elegant solution!

class Solution
{
public:
    int minCharacters(string a, string b)
    {
        int m = a.size(), n = b.size(), res = INT_MAX;

        // calculate fz
        array<int, 26> A = {}, B = {};
        for (auto &c : a)
            ++A[c - 'a'];
        for (auto &c : b)
            ++B[c - 'a'];

        for (int i = 0; i < 26; ++i)
        {
            // both a, b consist of 1 distinct letter i.e i
            res = min(res, m + n - A[i] - B[i]);

            // prefix calculation
            if (i > 0)
                A[i] += A[i - 1], B[i] += B[i - 1];

            if (i < 25)
            {
                res = min(res, m - A[i] + B[i]); // a strictly less than b
                res = min(res, n - B[i] + A[i]); // b strictly less than a
            }
        }

        return res;
    }
};