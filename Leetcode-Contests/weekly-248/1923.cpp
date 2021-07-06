// Rolling Hash solution
// Hash of a sliding window

class Solution
{
    int base = 1e5 + 7;
    long long power[(int)1e5 + 7], mod = 1e11L + 7;

    bool check(vector<vector<int>> &paths, int n)
    {
        unordered_set<long long> all_hashes;
        long long hash = 0;

        // check for common hashes in friends
        for (int f = 0; f < paths.size(); ++f)
        {
            unordered_set<long long> common_hashes;
            hash = 0;

            for (int i = 0; i < paths[f].size(); ++i)
            {
                if (i >= n)
                    hash = (hash + mod - power[n - 1] * paths[f][i - n] % mod) % mod;

                hash = hash * base % mod;
                hash = (hash + power[0] * paths[f][i] % mod) % mod;

                if (f == 0 && i >= n - 1)
                    all_hashes.insert(hash);

                if (f != 0 && i >= n - 1 && all_hashes.find(hash) != all_hashes.end())
                    common_hashes.insert(hash);
            }

            if (f != 0)
            {
                all_hashes = common_hashes;
                if (all_hashes.size() == 0)
                    return false;
            }
        }

        return true;
    }

public:
    int longestCommonSubpath(int n, vector<vector<int>> &paths)
    {
        int min_path = INT_MAX;

        for (auto &p : paths)
            min_path = min(min_path, (int)p.size());

        // create power array
        power[0] = 1;
        for (int i = 1; i < min_path; ++i)
            power[i] = power[i - 1] * base % mod;

        int start = 1, end = min_path, res = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            if (check(paths, mid))
            {
                res = mid;
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }

        return res;
    }
};