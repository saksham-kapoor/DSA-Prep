class Solution
{

    int find_swaps(string dst, string src)
    {
        int swaps = 0;

        for (int i = 0; i < dst.size(); ++i)
        {
            char c = dst[i];

            int j;
            for (j = i; j < src.size(); ++j)
            {
                if (src[j] == c)
                    break;
            }

            while (i != j)
            {
                swap(src[j - 1], src[j]);
                ++swaps;
                --j;
            }
        }

        return swaps;
    }

public:
    int getMinSwaps(string num, int k)
    {
        string target = num;

        for (int i = 0; i < k; ++i)
            next_permutation(target.begin(), target.end());

        return find_swaps(num, target);
    }
};