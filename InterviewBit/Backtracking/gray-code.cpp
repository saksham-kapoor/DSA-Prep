// Recursive Method
vector<int> solve(int bit)
{
    if (bit == 0)
        return {0, 1};
    vector<int> temp = solve(bit - 1), res;

    for (int i = 0; i < temp.size(); ++i)
        res.push_back(temp[i]);

    for (int i = temp.size() - 1; i >= 0; --i)
        res.push_back(temp[i] | (1 << bit));

    return res;
}

// Iterative Method
vector<int> itsolve(int n)
{
    vector<int> res = {0, 1};

    for (int i = 1; i <= n; ++i)
        for (int k = res.size() - 1; k >= 0; --k)
            res.push_back(res[k] | (1 << i));

    return res;
}

vector<int> Solution::grayCode(int A)
{
    return solve(A - 1);
    // or
    return itsolve(A - 1);
}