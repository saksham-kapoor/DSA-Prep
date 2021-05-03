class Solution
{
public:
    vector<int> closestRoom(vector<vector<int>> &rooms, vector<vector<int>> &queries)
    {
        vector<int> ans(queries.size());

        // sorting rooms according to decreasing size
        sort(rooms.begin(), rooms.end(), [](auto &a, auto &b) {
            return a[1] > b[1];
        });

        // storing index in queries
        // so we can sort the queries and still keep original indices
        for (int i = 0; i < (int)queries.size(); ++i)
            queries[i].push_back(i);

        // sorting queries according to decreasing min size
        sort(queries.begin(), queries.end(), [](auto &a, auto &b) {
            return a[1] > b[1];
        });

        // set to store all room ids
        set<int> s;

        // variable to iterate the rooms array
        int i = 0;

        // solving each query
        for (auto q : queries)
        {
            int pref = q[0], minSize = q[1], idx = q[2];

            // inserting all acceptable room ids into set
            while (i < rooms.size() && rooms[i][1] >= minSize)
                s.insert(rooms[i++][0]);

            // if all room sizes < minSize
            if (!s.size())
            {
                ans[idx] = -1;
                continue;
            }

            // get room id just greater than prefered id
            auto it = s.upper_bound(pref); // logarithmic time!!

            int abs_diff, resRoomId; // variables do as name suggests
            if (it != s.end())
            {
                abs_diff = *it - pref;
                resRoomId = *it;
            }
            else
                resRoomId = abs_diff = INT_MAX;

            // check if previous value is more suitable
            if (it != s.begin())
            {
                --it;
                if (abs(*it - pref) <= abs_diff)
                    resRoomId = *it;
            }

            ans[idx] = resRoomId;
        }

        return ans;
    }
};