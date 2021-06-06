// https://leetcode.com/problems/stone-game-vi/discuss/969574/JavaC%2B%2BPython-Sort-by-Value-Sum

// Method 1
// Sort on the basis of A[i] + B[i]
// why?
// [a1, a2] , [b1, b2]
// suppose we take, a1 for alice, the bob takes b2
// difference = a1 - b2
// we take a1 only if a1 - b2 > a2 - b1 as we play optimally
// therefore whem, a1 + b1 > a2 + b2, we take a1

class Solution
{
public:
    int stoneGameVI(vector<int> &av, vector<int> &bv)
    {
        int n = av.size();

        array<int, 2> points[n];
        array<int, 2> score;

        for (int i = 0; i < n; ++i)
            points[i] = {av[i], bv[i]};

        sort(points, points + n, [](auto &a, auto &b)
             { return a[0] + a[1] > b[0] + b[1]; });

        for (int i = 0; i < n; ++i)
            score[i % 2] += points[i][i % 2];

        if (score[0] == score[1])
            return 0;

        return score[0] > score[1] ? 1 : -1;
    }
};

// Method 2
// Suppose bob takes all the stones, difference now = 0 - sum(B)
// now sort the array in increasing A[i] + B[i]
// Alice will now choose, A[i] + B[i], so now difference = difference + A[i] + B[i]

class Solution
{
public:
    int stoneGameVI(vector<int> &av, vector<int> &bv)
    {
        int n = av.size(), diff = 0;

        for (int i = 0; i < n; ++i)
        {
            diff -= bv[i];
            av[i] += bv[i];
        }

        sort(av.rbegin(), av.rend());

        for (int i = 0; i < n; i += 2)
        {
            diff += av[i];
        }

        if (diff == 0)
            return 0;

        return diff > 0 ? 1 : -1;
    }
};
