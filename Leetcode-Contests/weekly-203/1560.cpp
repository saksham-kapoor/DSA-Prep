class Solution
{
public:
    vector<int> mostVisited(int n, vector<int> &rounds)
    {
        vector<int> ans;
        int start = rounds[0], end = rounds.back();

        while (end != start)
        {
            ans.push_back(start);
            start = (start % n) + 1;
        }

        ans.push_back(end);
        sort(ans.begin(), ans.end());
        return ans;
    }
};