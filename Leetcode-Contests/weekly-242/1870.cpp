class Solution
{
    bool check(vector<int> &dist, double hour, int speed)
    {
        double time = 0;

        // caculate total time taken with given speed
        for (int i = 0; i < dist.size() - 1; ++i)
        {
            time += ceil((double)dist[i] / speed);
        }

        time += (double)dist.back() / speed;
        if (time <= hour)
            return true;
        return false;
    }

public:
    int minSpeedOnTime(vector<int> &dist, double hour)
    {
        int start = 1, end = 1e7, ans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (check(dist, hour, mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }

        return ans;
    }
};