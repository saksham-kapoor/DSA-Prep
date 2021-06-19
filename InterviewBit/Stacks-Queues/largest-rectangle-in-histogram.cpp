int Solution::largestRectangleArea(vector<int> &A)
{
    int n = A.size();
    int left[n], right[n];

    vector<int> stack;
    for (int i = 0; i < n; ++i)
    {
        while (stack.size() && A[stack.back()] >= A[i])
            stack.pop_back();

        if (stack.size() == 0)
            left[i] = -1;
        else
            left[i] = stack.back();
        stack.push_back(i);
    }

    stack.clear();

    for (int i = n - 1; i >= 0; --i)
    {
        while (stack.size() && A[stack.back()] >= A[i])
            stack.pop_back();

        if (stack.size() == 0)
            right[i] = n;
        else
            right[i] = stack.back();
        stack.push_back(i);
    }

    int res = 0;
    for (int i = 0; i < n; ++i)
    {
        res = max(res, A[i] * (right[i] - left[i] - 1));
    }
    return res;
}
