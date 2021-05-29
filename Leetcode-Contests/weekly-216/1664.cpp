class Solution
{
public:
    int waysToMakeFair(vector<int> &A)
    {
        int n = A.size();
        int right[2] = {};

        // right[0] = A[0] + A[2] + A[4] .....
        // right[1] = A[1] + A[3] + A[5] .....

        for (int i = 0; i < n; ++i)
            right[i % 2] += A[i];

        int left[2] = {};

        // left[0] = A[0] + A[2] ....
        // left[1] = A[1] + A[3] ....

        int res = 0;
        for (int i = 0; i < n; ++i)
        {

            // split at each 'i'
            right[i % 2] -= A[i];

            // if we remove 'i'th element, all the elements after it will change their order
            if (left[0] + right[1] == left[1] + right[0])
                ++res;

            left[i % 2] += A[i]; // moving elements from right to left
        }

        return res;
    }
};