struct comp
{
    bool operator()(pair<int, int> const &a, pair<int, int> const &b)
    {
        return a.first > b.first;
    }
};

class Solution
{
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
    {
        int n = arrival.size();
        vector<int> ans;

        if (n <= k)
        {
            ans.resize(n);
            iota(ans.begin(), ans.end(), 0);
            return ans;
        }

        // set to store available servers ids
        set<int> avail;
        // heap to store unavailable servers with endtime [sorted in dec endtime order]
        priority_queue<pair<int, int>, vector<pair<int, int>>, comp> unavail;

        // at first all k are unavail as n > k
        for (int i = 0; i < k; ++i)
        {
            unavail.push({arrival[i] + load[i], i});
        }

        // now we check for remaining n-k processes

        int cnt[k]; // store number of processes accepted
        memset(cnt, 0, sizeof(cnt));
        int max_fz = 0;

        for (int i = k; i < n; ++i)
        {
            int start = arrival[i], end = start + load[i];

            while (unavail.size() && unavail.top().first <= start)
            {
                avail.insert(unavail.top().second);
                unavail.pop();
            }

            if (avail.empty())
                continue;

            auto it = upper_bound(avail.begin(), avail.end(), (i % k) - 1);
            if (it == avail.end())
                it = avail.begin();

            int id = *it;

            unavail.push({end, id});
            avail.erase(id);
            cnt[id]++;
            max_fz = max(max_fz, cnt[id]);
        }

        // FOR FINAL ANS
        for (int i = 0; i < k; ++i)
        {
            if (cnt[i] == max_fz)
                ans.push_back(i);
        }
        return ans;
    }
};
