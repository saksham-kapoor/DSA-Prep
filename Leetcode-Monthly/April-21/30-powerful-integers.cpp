class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        set<int> vals;

        for (int i = 1; i < bound; i *= x)
        {
            for (int j = 1; i + j <= bound; j *= y)
            {
                vals.insert(i + j);
                if (y == 1)
                    break;
            }
            if (x == 1)
                break;
        }

        return vector<int>(vals.begin(), vals.end());
    }
};