#include <vector>
using namespace std;

class Solution
{
public:
    int twoPointer(vector<int> &a)
    {
        int l, r, lmax, rmax, res;
        l = lmax = rmax = res = 0;
        r = a.size() - 1;
        while (l <= r)
        {
            if (a[l] <= a[r])
            {
                if (a[l] >= lmax)
                    lmax = a[l];
                else
                    res += lmax - a[l];
                l++;
            }
            else
            {
                if (a[r] >= rmax)
                    rmax = a[r];
                else
                    res += rmax - a[r];
                r--;
            }
        }
        return res;
    }

    int trap(vector<int> &height)
    {
        int Area = 0, n = height.size();
        if (n == 0)
            return 0;

        vector<int> maxL(n), maxR(n);

        // For maxL
        int mxl = height[0];
        maxL[0] = mxl;
        for (int i = 1; i < n; i++)
        {
            if (height[i] > mxl)
                mxl = height[i];
            maxL[i] = mxl;
        }

        // For maxR
        int mxr = height[n - 1];
        maxR[n - 1] = mxr;
        for (int i = n - 2; i >= 0; i--)
        {
            if (height[i] > mxr)
                mxr = height[i];
            maxR[i] = mxr;
        }

        // For maxArea
        for (int i = 0; i < n; i++)
            Area += min(maxL[i], maxR[i]) - height[i];

        return Area;
    }
};