vector<int> Solution::slidingMaximum(const vector<int> &A, int k)
{
    int n = A.size();
    vector<int> res;
    deque<int> q;

    for (int i = 0; i < n; ++i)
    {
        if (i >= k && A[i - k] == q.front())
            q.pop_front();

        // add element to q if required
        while (q.size() && q.back() < A[i])
            q.pop_back();
        q.push_back(A[i]);

        if (i >= k - 1)
            res.push_back(q.front());
    }

    return res;
}
