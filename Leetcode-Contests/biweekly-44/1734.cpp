/*
Actually since n is odd, we can get the 1 ^ 2 ^ 3 ^ ... ^ n in O(1) time.

Since 2 ^ 3 = 1, 4 ^ 5 = 1, 6 ^ 7 = 1 ...,
so XOR(1) = 1, XOR(3) = 0, XOR(5) = 1, XOR(7) = 0 ... where XOR(n) = 1 ^ 2 ^ ... ^ n.

So XOR(n) = 1 - n / 2 % 2.

MAIN CONCEPT -> WE CAN DECODE THE ENTIRE ARRAY IF WE HAVE THE STARTING ELEMENT, SO CALCULATE STARTING ELEMENT
*/

class Solution
{
public:
    vector<int> decode(vector<int> &en)
    {
        int n = en.size() + 1, _x = 0;

        // calculate XOR of first n numbers
        // for(int i = 1; i <= n; ++i) _x ^= i;
        _x = 1 - ((n / 2) % 2);

        int k = 0, start;
        for (int i = 1; i < en.size(); i += 2)
            k ^= en[i];
        start = _x ^ k;

        vector<int> res(n);
        res[0] = start;

        for (int i = 0; i < en.size(); ++i)
            res[i + 1] = (res[i] ^ en[i]);

        return res;
    }
};