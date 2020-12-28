// MY Solution / Actual Solution - O(N) time, O(1) Space

#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    void reverse(vector<int> &a, int x)
    {
        int n = a.size();
        int i = x, j = n - 1;
        while (i < j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }

    void nextPermutation(vector<int> &a)
    {
        int n = a.size();
        if (n <= 1)
            return;

        for (int i = n - 2; i >= 0; i--)
        {
            if (a[i] < a[i + 1])
            {
                int min = INT_MAX, min_i;
                for (int j = i + 1; j < n; j++)
                {
                    if (a[j] <= min && a[j] > a[i])
                    {
                        min = a[j];
                        min_i = j;
                    }
                }
                swap(a[i], a[min_i]);
                reverse(a, i + 1);
                return;
            }
        }

        reverse(a, 0);
    }
};