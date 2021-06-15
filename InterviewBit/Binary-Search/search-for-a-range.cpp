#define LOWER_BOUND 0
#define UPPER_BOUND 1

int find(const vector<int> &A, int B, int type)
{
    int start = 0, end = A.size() - 1, res = -1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (A[mid] == B)
        {
            res = mid;
            if (type == LOWER_BOUND)
                end = mid - 1;
            else
                start = mid + 1;
        }
        else if (A[mid] < B)
            start = mid + 1;
        else
            end = mid - 1;
    }

    return res;
}

vector<int> Solution::searchRange(const vector<int> &A, int B)
{
    int starting_idx = find(A, B, LOWER_BOUND);

    if (starting_idx == -1)
        return {-1, -1};

    int ending_idx = find(A, B, UPPER_BOUND);
    return {starting_idx, ending_idx};
}
