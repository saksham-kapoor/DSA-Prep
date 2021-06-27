// concept -> store in unordered_set
class Solution
{
public:
    int minimumTeachings(int n, vector<vector<int>> &lang, vector<vector<int>> &fr)
    {
        bitset<501> users[501];

        for (int i = 0; i < lang.size(); ++i)
        {
            for (int j = 0; j < lang[i].size(); ++j)
                users[i + 1][lang[i][j]] = 1;
        }

        int res = INT_MAX;
        for (int i = 1; i <= n; ++i)
        {
            // here 'i' is the language we want to teach!
            unordered_set<int> teach;

            for (auto &f : fr)
            {
                if ((users[f[0]] & users[f[1]]) == 0)
                {
                    // if 2 friends don't speak any common language
                    // simply teach them 'i' if they don't already know it
                    if (users[f[0]][i] == 0)
                        teach.insert(f[0]);
                    if (users[f[1]][i] == 0)
                        teach.insert(f[1]);
                }
            }

            // teach.size() simple denotes the number of people who have to learn language i
            // so that all friends can communicate
            res = min(res, (int)teach.size());
        }

        return res;
    }
};