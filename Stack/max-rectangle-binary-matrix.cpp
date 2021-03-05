#include <vector>
#include <stack>
using namespace std;

int largestRectangleArea(vector<int> &arr)
{
    int n = arr.size();
    int maxArea = INT_MIN;
    int NSL[n], NSR[n];
    stack<int> s1, s2;

    // FOR NSL
    for (int i = 0; i < n; i++)
    {
        if (s1.empty())
            NSL[i] = -1;
        else if (arr[s1.top()] < arr[i])
            NSL[i] = s1.top();
        else
        {
            while (!s1.empty() && arr[s1.top()] >= arr[i])
                s1.pop();
            if (s1.empty())
                NSL[i] = -1;
            else
                NSL[i] = s1.top();
        }
        s1.push(i);
    }

    // FOR NSR
    for (int i = n - 1; i >= 0; i--)
    {
        if (s2.empty())
            NSR[i] = n;
        else if (arr[s2.top()] < arr[i])
            NSR[i] = s2.top();
        else
        {
            while (!s2.empty() && arr[s2.top()] >= arr[i])
                s2.pop();
            if (s2.empty())
                NSR[i] = n;
            else
                NSR[i] = s2.top();
        }
        s2.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        int area = arr[i] * (NSR[i] - NSL[i] - 1);
        if (area > maxArea)
            maxArea = area;
    }
    return maxArea;
}

int Solution::maximalRectangle(vector<vector<int>> &A)
{
    int n = A.size(), m = A[0].size();
    vector<int> v;

    for (int i = 0; i < m; i++)
        v.push_back(A[0][i]);

    int maxA = largestRectangleArea(v);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (A[i][j] == 0)
                v[j] = 0;
            else
                v[j] += A[i][j];
        }
        maxA = max(maxA, largestRectangleArea(v));
    }

    return maxA;
}
