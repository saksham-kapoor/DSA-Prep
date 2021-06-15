#define INCREASING 1
#define DECREASING 0

int find_peak(vector<int> &A)
{
    int start = 1, end = A.size() - 2;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1])
            return mid;
        else if (A[mid] < A[mid + 1])
            start = mid + 1;
        else
            end = mid - 1;
    }

    return 0; // no peak
}

int find(vector<int> &A, int B, int start, int end, int type)
{
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] == B)
            return mid;
        else if (A[mid] < B)
            if (type == INCREASING)
                start = mid + 1;
            else
                end = mid - 1;
        else if (type == INCREASING)
            end = mid - 1;
        else
            start = mid + 1;
    }
    return -1;
}

int Solution::solve(vector<int> &A, int B)
{
    int peak = find_peak(A), left_ans = -1, right_ans = -1;

    if (B >= A[0] && B <= A[peak])
        left_ans = find(A, B, 0, peak, INCREASING);

    if (left_ans != -1)
        return left_ans;

    if (B <= A[peak + 1] && B >= A.back())
        right_ans = find(A, B, peak + 1, A.size() - 1, DECREASING);

    return right_ans;
}
