// https://www.youtube.com/watch?v=LPFhl65R7ww

class Solution
{
public:
    double findMedianSortedArrays(vector<int> &A, vector<int> &B)
    {
        int m = A.size(), n = B.size();
        if (m > n)
            return findMedianSortedArrays(B, A);

        // m is smaller, so we binary search on m
        int leftsz = (m + n + 1) / 2, sz, x1, x2, y1, y2;
        int start = 0, end = m, mid;

        while (start <= end)
        {
            mid = start + (end - start) / 2;
            sz = leftsz - mid;

            x1 = mid == 0 ? INT_MIN : A[mid - 1];
            x2 = mid == A.size() ? INT_MAX : A[mid];
            y1 = sz == 0 ? INT_MIN : B[sz - 1];
            y2 = sz == B.size() ? INT_MAX : B[sz];

            if (x1 <= y2 && y1 <= x2)
                break;
            else if (x1 > y1)
                end = mid - 1;
            else
                start = mid + 1;
        }

        if ((m + n) % 2 == 0)
            return (double)(max(x1, y1) + min(x2, y2)) / 2;

        return max(x1, y1);
    }
};