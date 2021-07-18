// 2 pointer method

class Solution
{
public:
    int numRescueBoats(vector<int> &people, int limit)
    {
        int i = 0, j = people.size() - 1, res = 0;
        sort(people.begin(), people.end());

        while (i <= j)
        {
            int curr = people[j--];

            if (curr + people[i] <= limit)
                ++i;

            ++res;
        }

        return res;
    }
};