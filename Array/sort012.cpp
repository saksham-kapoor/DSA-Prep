void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort012(int A[], int n)
{
    int l = 0, m = 0, h = n - 1;
    while (m < n && m >= l && m <= h)
    {
        if (A[m] == 0)
        {
            if (m == l)
                m++;
            else
            {
                if (A[l] != 0)
                    swap(&A[l], &A[m]);
                l++;
            }
        }
        else if (A[m] == 2)
        {
            if (m == h)
                m++;
            else
            {
                if (A[h] != 2)
                    swap(&A[h], &A[m]);
                h--;
            }
        }
        else
            m++;
    }
}