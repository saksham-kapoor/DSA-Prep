// Crazy logical question!

class Solution
{
public:
    vector<bool> canEat(vector<int> &candies, vector<vector<int>> &queries)
    {
        // declare variables
        long type, fav_day, atmost, have_to_eat_min_this, can_eat_atmost_this, min_available, max_available;

        // calculate prefix
        vector<long> sum(candies.size());
        sum[0] = candies[0];
        for (int i = 1; i < candies.size(); ++i)
            sum[i] = sum[i - 1] + candies[i];

        // store ans
        vector<bool> res(queries.size());
        int k = 0;

        // process queries
        for (auto &q : queries)
        {
            // query variables
            type = q[0], fav_day = q[1], atmost = q[2];

            have_to_eat_min_this = fav_day;
            can_eat_atmost_this = (fav_day + 1) * atmost - 1;

            min_available = type == 0 ? 0 : sum[type - 1];
            max_available = sum[type] - 1;

            res[k++] = (have_to_eat_min_this <= max_available && can_eat_atmost_this >= min_available);
        }

        return res;
    }
};