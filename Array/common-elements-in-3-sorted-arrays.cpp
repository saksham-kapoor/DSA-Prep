#include <vector>
using namespace std;

// My Solution - O(n) time, O(n) space
// Problem - TOO MANY IF STATEMENTS
class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int> ans;
        int i, j, k;
        i = j = k = 0;

        while (i < n1 && j < n2 && k < n3)
        {
            if (A[i] > B[j] && A[i] > C[k])
            {
                j++;
                k++;
            }
            else if (B[j] > A[i] && B[j] > C[k])
            {
                i++;
                k++;
            }
            else if (C[k] > B[j] && C[k] > A[i])
            {
                j++;
                i++;
            }
            else if (A[i] == B[j] && A[i] > C[k])
            {
                k++;
            }
            else if (C[k] == B[j] && C[k] > A[i])
            {
                i++;
            }
            else if (A[i] == C[k] && A[i] > B[j])
            {
                j++;
            }
            else if (A[i] == B[j] && B[j] == C[k])
            {
                if (ans.empty() || ans.back() != A[i])
                {
                    ans.push_back(A[i]);
                }
                i++;
                j++;
                k++;
            }
        }
        return ans;
    }
};

// Better solution as less if statements, same complexities
class Solution
{
public:
    vector<int> commonElements(int A[], int B[], int C[], int n1, int n2, int n3)
    {
        vector<int> ans;
        int i, j, k;
        i = j = k = 0;

        while (i < n1 && j < n2 && k < n3)
            if (A[i] == B[j] && B[j] == C[k])
            {
                if (ans.empty() || ans.back() != A[i])
                    ans.push_back(A[i]);
                i++;
                j++;
                k++;
            }
            else if (A[i] < B[j])
                i++;
            else if (C[k] > B[j])
                j++;
            else
                k++;

        return ans;
    }
};