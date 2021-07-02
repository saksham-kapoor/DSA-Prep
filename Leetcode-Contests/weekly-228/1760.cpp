// Binary search on answer
// whenever we see clear lower and upper limit of the answer
// always think binary search!

class Solution
{
    bool check(int max, vector<int> &A, int m)
    {
        int op = 0;
        for (auto &i : A)
            op += (i - 1) / max;
        return op <= m;
    }

public:
    int minimumSize(vector<int> &A, int m)
    {
        int n = A.size(), res = 0;
        int start = 1, end = *max_element(A.begin(), A.end());

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (check(mid, A, m))
            {
                res = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return res;
    }
};