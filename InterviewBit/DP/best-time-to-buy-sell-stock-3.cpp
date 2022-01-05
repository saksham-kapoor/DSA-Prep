// AT MOST 2 TRANSACTIONS ALLOWED
// https://www.youtube.com/watch?v=wuzTpONbd-0
// BEST SOLUTION: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/discuss/39611/Is-it-Best-Solution-with-O(n)-O(1).

int Solution::maxProfit(const vector<int> &A)
{
    if (A.size() == 0)
        return 0;

    // prefix --> max profit if i sell till today [including today]
    int prefix[A.size()], min_till_now = A[0];
    prefix[0] = 0;

    for (int i = 1; i < A.size(); ++i)
    {
        min_till_now = min(min_till_now, A[i]);
        prefix[i] = max(prefix[i - 1], A[i] - min_till_now);
    }

    // suffix --> max profit if i buy after today [including today]
    int suffix[A.size()], max_till_now = A[A.size() - 1];
    suffix[A.size() - 1] = 0;

    for (int i = A.size() - 2; i >= 0; --i)
    {
        max_till_now = max(max_till_now, A[i]);
        suffix[i] = max(suffix[i + 1], max_till_now - A[i]);
    }

    // answer
    int res = 0;
    for (int i = 0; i < A.size(); ++i)
        res = max(res, prefix[i] + suffix[i]);

    return res;
}
