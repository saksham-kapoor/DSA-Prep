// unlimited transactions

int Solution::maxProfit(const vector<int> &A)
{
    if (A.size() == 0)
        return 0;
    int res = 0, prev = A[0];

    for (int i = 1; i < A.size(); ++i)
        if (A[i - 1] > A[i])
            res += A[i - 1] - prev, prev = A[i];

    res += A.back() - prev;
    return res;
}
