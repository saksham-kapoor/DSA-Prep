class Solution
{
public:
    int minSwaps(string s)
    {
        int tot_ones = 0, tot_zeros = 0, _ones = 0, _zeros = 0;

        // _zeros store number of 0s on even indices
        // _ones store number of 1s on even indices

        for (int i = 0; i < (int)s.size(); ++i)
        {
            if (s[i] == '0')
            {
                ++tot_zeros;
                if (i % 2 == 0)
                    ++_zeros;
            }
            else
            {
                ++tot_ones;
                if (i % 2 == 0)
                    ++_ones;
            }
        }

        // check invalid case
        // it will be impossible if difference greater than two
        if (tot_zeros != tot_ones && tot_zeros != tot_ones + 1 && tot_ones != tot_zeros + 1)
            return -1;

        // if array size is even, number of swaps required will be min number of 1's or 0's placed on even indices
        // we can say that these number of elements are wrongfully placed
        if ((int)s.size() % 2 == 0)
            return min(_zeros, _ones);

        // if array size is odd
        // if total number of zeros > ones, we can say all the one's placed on even indices need to be swaped
        if (tot_zeros > tot_ones)
            return _ones;

        // vice versa of above statement
        return _zeros;
    }
};