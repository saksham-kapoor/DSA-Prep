int Solution::sqrt(int A)
{
    int start = 1, end = A, res = 0;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        if ((long)mid * mid <= A)
        {
            res = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return res;
}
