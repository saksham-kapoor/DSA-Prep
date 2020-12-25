// Kadane's Algorithm - Used to find max sum contiguous sub array

int maxSubarraySum(int A[], int n)
{
    int curr_best, overall_best;
    curr_best = overall_best = A[0];

    for (int i = 1; i < n; i++)
    {
        (A[i] > curr_best + A[i]) ? curr_best = A[i] : curr_best = curr_best + A[i];
        (curr_best > overall_best) ? overall_best = curr_best : overall_best = overall_best;
    }
    return overall_best;
}