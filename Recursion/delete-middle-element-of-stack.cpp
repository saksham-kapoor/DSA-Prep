class Solution
{
    void solve(stack<int> &s, int k)
    {
        if (k == 1)
        {
            s.pop();
            return;
        }
        int temp = s.top();
        s.pop();
        solve(s, --k);
        s.push(temp);
    }

public:
    void deleteMid(stack<int> &s, int sizeOfStack)
    {
        if (s.empty())
            return;
        int k = sizeOfStack / 2 + 1;
        solve(s, k);
    }
};
