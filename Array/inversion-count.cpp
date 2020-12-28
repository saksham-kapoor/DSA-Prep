// Inversion Count : For an array, inversion count indicates how far(or close) the array
// is from being sorted.If array is already sorted then the inversion count is 0.
// If an array is sorted in the reverse order then the inversion count is the maximum.Formally,
// two elements a[i] and a[j] form an inversion if a[i] > a[j] and i < j.

// Merge Sort - Optimal approach | O(nlogn time) | Not very clear. Revise.
long long int merge(long long arr[], long long int l, long long int mid, long long int h)
{
    long long int i = l, j = mid + 1, k = l;
    long long int B[h + 1];
    long long int count = 0;

    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
            B[k++] = arr[i++];
        else
        {
            B[k++] = arr[j++];
            count += mid - i + 1;
        }
    }

    while (i <= mid)
        B[k++] = arr[i++];

    while (j <= h)
        B[k++] = arr[j++];

    for (i = l; i <= h; i++)
    {
        arr[i] = B[i];
    }
    return count;
}

long long int mergeSort(long long arr[], long long int l, long long int h)
{
    long long int inv_c = 0;
    if (l < h)
    {
        long long int mid = (l + h) / 2;
        inv_c += mergeSort(arr, l, mid);
        inv_c += mergeSort(arr, mid + 1, h);
        inv_c += merge(arr, l, mid, h);
    }
    return inv_c;
}

long long int inversionCount(long long arr[], long long N)
{
    return mergeSort(arr, 0, N - 1);
}

// Brute Force Approach - TLE | O(N^2) Time, O(1) Space
long long int inversionCount(long long arr[], long long N)
{
    long long int inv_count = 0;
    for (long long i = 0; i < N; i++)
    {
        for (long long j = i + 1; j < N; j++)
        {
            if (arr[j] < arr[i])
                inv_count++;
        }
    }
    return inv_count;
}