#include <vector>
#include <stack>
using namespace std;

class Solution
{
public:
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> ans(n);
        stack<int> s;
        for (int i = 0; i < n; i++)
        {
            if (s.empty())
                ans[i] = i + 1;
            else if (price[s.top()] > price[i])
                ans[i] = i - s.top();
            else
            {
                while (!s.empty() && price[s.top()] <= price[i])
                    s.pop();
                if (s.empty())
                    ans[i] = i + 1;
                else
                    ans[i] = i - s.top();
            }

            s.push(i);
        }

        return ans;
    }
};