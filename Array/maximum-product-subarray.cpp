#include <vector>
using namespace std;

// O(n) time | O(1) space
class Solution
{
public:
    int max(int A, int B, int C)
    {
        return (A > B) ? (A > C) ? A : C : (B > C) ? B : C;
    }

    int min(int A, int B, int C)
    {
        return (A < B) ? (A < C) ? A : C : (B < C) ? B : C;
    }

    int max(int A, int B)
    {
        return (A > B) ? A : B;
    }

    int maxProduct(vector<int> &arr)
    {
        int overall_max = arr[0], current_max = arr[0], current_min = arr[0];
        int n = arr.size();

        for (int i = 1; i < n; i++)
        {
            if (arr[i] == 0)
            {
                if (overall_max < 0)
                    overall_max = 0;
                current_max = current_min = 1;
                continue;
            }

            int temp = current_max;
            current_max = max(arr[i], current_max * arr[i], current_min * arr[i]);
            current_min = min(arr[i], temp * arr[i], current_min * arr[i]);
            overall_max = max(overall_max, current_max);
        }
        return overall_max;
    }
};