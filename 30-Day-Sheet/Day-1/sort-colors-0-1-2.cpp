/*
One Pass Solution -> O(N) time, O(1) space

Explanation -
we want to divide the array into 3 regions 0 0 ...| 1 1 ... | 2 2 ....

we take low = mid = 0, high = n-1
2 0 2 1 1 0
L         H 
M

[M, H] is the unknown or unprocessed region
Therefore, while(M <= H)

All array values before index m will contain 0 or 1
while after(including) m can contain 0 or 1 or 2

Therefore, we won't do m++ when swapping with high as that value may be used to swap with low.

Finally,
[0, L) - 0 Region
[L, H] - 1 Region
(H, N-1] - 2 Region
*/

class Solution
{
public:
    void sortColors(vector<int> &a)
    {
        int l = 0, h = a.size() - 1, m = 0;
        while (m <= h)
        {
            if (a[m] == 2)
            {
                a[m] = a[h];
                a[h] = 2;
                h--;
            }
            else if (a[m] == 0)
            {
                a[m] = a[l];
                a[l] = 0;
                l++;
                m++;
            }
            else
                m++;
        }
    }
};