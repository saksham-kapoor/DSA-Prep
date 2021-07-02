// make string alternating
// f[0][0] -> number of zeros in even indices
// f[1][0] -> number of zeros in odd indices
// f[0][1] -> number of ones in even indices
// f[1][1] -> number of ones in odd indices

// to make it alternating
// (all even indices == 0 && all odd indices == 1) || (all odd indices == 0 && all even indices == 1)
// (zeros on odd indices + ones on even indices) OR (ones on odd indices + zeros on even indices)
// take minimum!

class Solution
{
public:
    int minOperations(string s)
    {
        array<array<int, 2>, 2> fz = {};

        for (int i = 0; i < s.size(); ++i)
            fz[i % 2][s[i] - '0']++;

        return min(fz[0][1] + fz[1][0], fz[1][1] + fz[0][0]);
    }
};