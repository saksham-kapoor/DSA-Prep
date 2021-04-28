/*

GREEDY APPROACH!
Keep placing the flowers as soon as you find a valid spot.

*/

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return true;
        int size = flowerbed.size();

        int i = 0;
        while (i < size)
        {
            if (flowerbed[i] == 1)
            {
                i += 2;
            }
            else
            {
                if ((i == 0 || flowerbed[i - 1] == 0) && (i == size - 1 || flowerbed[i + 1] == 0))
                {
                    i += 2;
                    n -= 1;
                    if (n == 0)
                        return true;
                }
                else
                    ++i;
            }
        }

        return false;
    }
};

/*

GREEDY APPROACH!
COUNT ALL CONSECUTIVE ZEROS
and calculate number of flowers that can be placed there

*/

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        if (n == 0)
            return true;
        int size = flowerbed.size();
        int result = 0, count = 1;

        for (int i = 0; i < size; ++i)
        {
            if (flowerbed[i] == 0)
                count++;
            else
            {
                result += (count - 1) / 2;
                count = 0;
            }
        }

        if (count != 0)
            result += count / 2;

        return result >= n;
    }
};