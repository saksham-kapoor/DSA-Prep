#include <unordered_map>
#include <algorithm> //for 'max' function
using namespace std;

int maxLen(int A[], int n)
{
    int maxLength = 0, sum = 0;
    unordered_map<int, int> sumIndex;
    sumIndex[0] = -1;
    for (int i = 0; i < n; i++)
    {
        sum += A[i];
        if (sumIndex.find(sum) != sumIndex.end())
            maxLength = max(maxLength, i - sumIndex[sum]);
        else
            sumIndex[sum] = i;
    }
    return maxLength;
}