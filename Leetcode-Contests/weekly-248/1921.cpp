// O(n) Approach
// count sort inspired solution
class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        const int size = 1e5 + 5, n = dist.size();
        int fz[size] = {}, t = 1;

        for (int i = 0; i < n; ++i)
            ++fz[(int)ceil((double)dist[i] / speed[i])];

        for (; t < size; ++t)
        {
            fz[t] += fz[t - 1];
            if (t < fz[t])
                return t; // monsters exceed time!
            if (fz[t] == n)
                return n; // all monsters dead
        }

        return n;
    }
};

// Learning -> We don't need epsilon when dealing with int / int
// O(nlogN) Approach
class Solution
{
public:
    int eliminateMaximum(vector<int> &dist, vector<int> &speed)
    {
        priority_queue<double, vector<double>, greater<double>> pq; // min pq

        for (int i = 0; i < dist.size(); ++i)
        {
            double time = ceil((double)dist[i] / speed[i]);
            pq.push(time);
        }

        int t = 0;
        while (pq.size() && pq.top() > t++)
            pq.pop();
        return dist.size() - pq.size();
    }
};