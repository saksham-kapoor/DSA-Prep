/*
    Explanation:
    c = a ^ b
    a = b ^ c
    b = a ^ c

*/

class Solution
{
public:
    vector<int> decode(vector<int> &encoded, int first)
    {
        int n = encoded.size();
        vector<int> res(n + 1);
        res[0] = first;

        for (int i = 0; i < n; ++i)
            res[i + 1] = res[i] ^ encoded[i];

        return res;
    }
};