/*

Method 1 -> Sort the array and then solve, Time O(NLogN)

Method 2 -> Create Frequency Array [1, n]
            fz == 0 (missing) and fz == 2 (repeating)

            Time: O(N), Space: O(N)

Method 3 -> Sum and Summation of squares method
            Sum_Expected = S1 = n(n+1)/2
            Sum_Actual = S2 = sum of elements

            S1 - S2 = X - Y
            where X = missing element, Y = repeating element

            Sq_Sum_Expected = S3 = 1^2 + 2^2 + .... + n^2
            Sq_Sum_Actual = S4 = sum of squares of elements

            S3 - S4 = X^2 - Y^2

            solve the two equations to get X and Y

            Time: O(N), Space: O(1)
            Might overflow

Method 4 -> XOR Method (Imp.)
            Explained in Code

            Time: O(N), Space: O(1)

            BONUS CONCEPT : To get right-most different bit of two numbers A, B
                            X = A^B
                            bit = X & ~(X-1)
            
*/

class Solution
{
public:
    int *findTwoElement(int *arr, int n)
    {
        int *ans = new int[2];

        int XoR = 0;
        for (int i = 0; i < n; i++)
            XoR ^= (i + 1) ^ arr[i];
        // XoR = X^Y [X = Missing element, Y = repeating element]

        int rightmost_set_bit = XoR & ~(XoR - 1);

        // this will give us the rightmost bit which is different for X,Y
        // now we divide the elements into 2 buckets

        int XoR1, XoR2;
        XoR1 = XoR2 = XoR;

        // dividing arr elements into buckets XoR1 and XoR2
        for (int i = 0; i < n; i++)
            if (arr[i] & rightmost_set_bit)
                XoR1 ^= arr[i];
            else
                XoR2 ^= arr[i];

        // dividing expected elements into buckets XoR1 and XoR2
        for (int i = 1; i <= n; i++)
            if (i & rightmost_set_bit)
                XoR1 ^= i;
            else
                XoR2 ^= i;

        // Now XoR1 and XoR2 store the required elements :) as all other elements get cancelled out
        // however, this method does not tell us which number repeated and which is missing
        // so we check that manually

        for (int i = 0; i < n; i++)
            if (arr[i] == XoR1)
            {
                ans[0] = XoR1;
                ans[1] = XoR2;
                break;
            }
            else if (arr[i] == XoR2)
            {
                ans[0] = XoR2;
                ans[1] = XoR1;
                break;
            }

        return ans;
    }
};