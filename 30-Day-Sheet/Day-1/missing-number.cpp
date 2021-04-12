/*

Question can be rephrased as -> in [1,n], 1 number has been raplaced by 0, find that number.
One Pass Solution -> O(N) time, O(1) space

# Method 1 -> taking sum variable
  sum = n(n+1)/2;
  then subtracting all present numbers will give required ans.

  Problem with Method 1 -> if n is huge, sum might overflow

# Method 2 -> using the XOR binary operator
  Properties of XOR ->
  1. a ^ a = 0
  2. a ^ 0 = a
  
  Simply taking xor of [1,n]
  Xor = 1^2^3^.....n
  
  then looping and taking xor of all given values in the same variable
  let missing number be x
  Xor = 0^1^1^2^2^3^3...^x^.....n^n
      = 0^x
      = x 

  ans = Xor
  (better method as bit operations are faster and no overflow problem)
*/

class Solution
{
public:
    int missingNumber(vector<int> &nums)
    {
        int XoR = 0, n = nums.size();

        for (int i = 0; i < n; i++)
            XoR ^= (i + 1) ^ nums[i];

        return XoR;
    }
};