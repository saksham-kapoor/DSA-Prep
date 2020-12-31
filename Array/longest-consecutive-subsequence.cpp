#include <vector>
using namespace std;

// Easy - O(N) time | O(N) space
int findLongestConseqSubseq(int arr[], int N)
{
    vector<int> A(100001, 0);
    for (int i = 0; i < N; i++)
        A[arr[i]]++;

    int maxCount = 0;
    int count = 0;

    for (int i = 0; i < A.size(); i++)
        if (A[i] == 0)
            count = 0;
        else
        {
            count += 1;
            if (count > maxCount)
                maxCount = count;
        }
    return maxCount;
}