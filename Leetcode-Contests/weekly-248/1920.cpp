/*

    Somehow, store 2 numbers at 1 place
    Anything similar we did in past?
    Absolutely, we stored coordinates of a matrix in the same integer by the formula -> y + n * x
    
    here, A[i] = y and A[A[i]] = x
    A[i] = A[i] + n * A[A[i]]
    
    how to access A[i] now? A[i] % n
    how to access A[A[i]] now? A[i] / n

*/

class Solution
{
public:
    vector<int> buildArray(vector<int> &A)
    {
        int n = A.size();

        for (int i = 0; i < n; ++i)
            A[i] += n * (A[A[i]] % n);

        for (int i = 0; i < n; ++i)
            A[i] /= n;

        return A;
    }
};