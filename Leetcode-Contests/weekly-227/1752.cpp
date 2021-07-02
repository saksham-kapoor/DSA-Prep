// Simple, Draw Array Mountain Diagrams to easily visualize conditions!

class Solution
{
public:
    bool check(vector<int> &A)
    {
        int cnt = 0;

        for (int i = 0; i < A.size(); ++i)
            if (A[(i + 1) % A.size()] < A[i])
                ++cnt;

        return cnt <= 1;
    }
};