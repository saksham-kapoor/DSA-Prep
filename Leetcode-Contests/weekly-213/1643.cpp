// Beautiful lexicographic ordering
// find kth lexicographic order in less time

class Solution
{
    string res;

    int nCr(int n, int r)
    {
        int ans = 1;
        r = min(r, n - r);

        for (int i = 1; i <= r; ++i)
        {
            ans *= n - i + 1;
            ans /= i;
        }

        return ans;
    }

public:
    string kthSmallestPath(vector<int> &destination, int k)
    {
        string res = "";
        int cnt_H = destination[1];
        int cnt_V = destination[0];

        while (cnt_H && cnt_V)
        {
            int h_first = nCr(cnt_H + cnt_V - 1, cnt_H - 1);

            if (h_first < k)
            {
                res += "V";
                --cnt_V;
                k -= h_first;
                continue;
            }

            res += "H";
            --cnt_H;
        }

        while (cnt_H--)
            res += "H";

        while (cnt_V--)
            res += "V";

        return res;
    }
};