// MAGNETIC FORCE
// TYPICAL BINARY SEARCH WORD PROBLEM!

class Solution
{
    bool isValid(int force, vector<int> &position, int num_balls)
    {
        int count = 1, prev = 0;
        for (int i = 1; i < position.size(); ++i)
        {
            if (position[i] - position[prev] >= force)
            {
                count++;
                prev = i;
            }
        }

        if (count < num_balls)
            return false;
        return true;
    }

public:
    int maxDistance(vector<int> &position, int num_balls)
    {
        sort(position.begin(), position.end());
        int l = 0, r = position.back() - position.front();

        int res = -1;

        while (l <= r)
        {
            int force = l + (r - l) / 2;

            if (isValid(force, position, num_balls))
            {
                res = force;
                l = force + 1;
            }
            else
            {
                r = force - 1;
            }
        }

        return res;
    }
};