/*

Concept -> A B C D E F G H
           |     |
           sum = a

           |           |
              sum = a

                 |     |
                 sum = 0 
*/

int maxLen(int A[], int n)
{
    int maxLength = 0, sum = 0;
    unordered_map<int, int> index_of_sum;
    index_of_sum[0] = -1;

    for (int i = 0; i < n; ++i)
    {
        sum += A[i];
        if (index_of_sum.find(sum) != index_of_sum.end())
        {
            maxLength = max(maxLength, i - index_of_sum[sum]);
        }
        else
        {
            index_of_sum[sum] = i;
        }
    }

    return maxLength;
}