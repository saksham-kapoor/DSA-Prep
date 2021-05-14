class Solution
{
public:
    vector<string> alertNames(vector<string> &kn, vector<string> &kt)
    {
        int n = kn.size();
        vector<string> ans;

        unordered_map<string, vector<int>> user;

        for (int i = 0; i < n; ++i)
        {
            int hr = (kt[i][0] - '0') * 10 + (kt[i][1] - '0');
            int min = (kt[i][3] - '0') * 10 + (kt[i][4] - '0');
            int time = hr * 60 + min;
            user[kn[i]].push_back(time);
        }

        for (auto &[name, times] : user)
        {
            int i = 0, j = 2;
            sort(times.begin(), times.end());

            while (j < times.size())
            {
                if (times[j] - times[i] <= 60)
                {
                    ans.push_back(name);
                    break;
                }
                ++i;
                ++j;
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};