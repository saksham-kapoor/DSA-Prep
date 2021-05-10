/*
    Explanation!
    
    2  3  -2  4
    ____   _
    
    Similar to Kadane's algorithm!
    Either we include '-2' or we start from '-2'
    
    2  3  -2  4
       ^
      here we have imin ending at 3 starting from somewhere
      and imax ending at 3 starting from somewhere
      
    2  3  -2  4
           ^
           Now when we come here
           we either include -2 in prev imin/imax or start from -2

*/

class Solution
{
public:
    int maxProduct(vector<int> &A)
    {
        int imin = A[0], imax = A[0], overall_max = A[0];

        for (int i = 1; i < A.size(); ++i)
        {
            int tmp = imax;

            imax = max({A[i], imax * A[i], imin * A[i]});
            imin = min({A[i], tmp * A[i], imin * A[i]});

            overall_max = max(overall_max, imax);
        }

        return overall_max;
    }
};