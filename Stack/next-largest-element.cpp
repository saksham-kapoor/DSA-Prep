#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<long long> nextLargerElement(vector<long long> arr, int n)
    {
        vector<long long> ans(n, 0);
        stack<long long> s;

        for (int i = n - 1; i >= 0; i--)
        {
            if (s.empty())
            {
                ans[i] = -1;
            }
            else if (s.top() > arr[i])
            {
                ans[i] = s.top();
            }
            else
            {
                while (!s.empty() && s.top() <= arr[i])
                    s.pop();

                if (s.empty())
                    ans[i] = -1;
                else
                    ans[i] = s.top();
            }
            s.push(arr[i]);
        }

        return ans;
    }
};
