class Solution
{
public:
    int eatenApples(vector<int> &apples, vector<int> &days)
    {
        int res = 0, n = apples.size(), d = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // rotting day number, num apples

        for (d = 0;; ++d)
        {
            if (d < n && apples[d] != 0)
            {
                pq.push({d + days[d] - 1, apples[d]});
            }
            while (pq.size() && pq.top().first < d)
                pq.pop();
            if (pq.size())
            {
                ++res;
                auto temp = pq.top();
                pq.pop();
                if (temp.second != 1)
                    pq.push({temp.first, temp.second - 1});
            }
            else if (d >= n)
                break;
        }

        return res;
    }
};