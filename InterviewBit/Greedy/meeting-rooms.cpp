int Solution::solve(vector<vector<int>> &A)
{
    int n = A.size();
    int incoming[n], outgoing[n];

    for (int i = 0; i < n; ++i)
        incoming[i] = A[i][0], outgoing[i] = A[i][1];

    sort(incoming, incoming + n);
    sort(outgoing, outgoing + n);

    int i = 0, j = 0, rooms = 0, res = 0;
    while (i < n)
    {
        if (incoming[i] < outgoing[j])
            ++i, ++rooms;
        else
            ++j, --rooms;

        res = max(res, rooms);
    }

    return res;
}
