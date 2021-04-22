// we have to pass through minimum bricks
// so we pass through the line where max numbers of bricks end
class Solution
{
public:
    int leastBricks(vector<vector<int>> &wall)
    {
        unordered_map<int, int> prefix;
        int max_common = 0;

        for (int i = 0; i < wall.size(); ++i)
        {
            int row_sum = 0;
            for (int j = 0; j < wall[i].size() - 1; ++j)
            {
                row_sum += wall[i][j];
                ++prefix[row_sum];
                max_common = max(max_common, prefix[row_sum]);
            }
        }

        return wall.size() - max_common;
    }
};