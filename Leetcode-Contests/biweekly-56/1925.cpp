// can increase space to decrease time complexity

class Solution
{
public:
    int countTriples(int n)
    {
        int res = 0;
        bool squares[62501] = {};

        // mark all squares
        for (int i = 1; i <= n; ++i)
            squares[i * i] = 1;

        for (int i = 1; i <= n; ++i)
            for (int j = i + 1; i * i + j * j <= n * n; ++j)
                res += squares[i * i + j * j] * 2;

        return res;
    }
};