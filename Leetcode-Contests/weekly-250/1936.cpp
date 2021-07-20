class Solution
{
public:
    int addRungs(vector<int> &A, int dist)
    {
        int res = (A[0] - 1) / dist;

        for (int i = 1; i < A.size(); ++i)
            if (A[i] - A[i - 1] > dist)
                res += (A[i] - A[i - 1] - 1) / dist;

        return res;
    }
};