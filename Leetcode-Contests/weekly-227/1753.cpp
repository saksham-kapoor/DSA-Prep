// Try to find all cases + extra care to edge cases

class Solution
{
public:
    int maximumScore(int a, int b, int c)
    {
        int stones[] = {a, b, c};
        sort(stones, stones + 3, greater<int>());

        if (stones[1] + stones[2] >= stones[0])
            return (stones[0] + stones[1] + stones[2]) / 2;
        return stones[1] + stones[2];
    }
};