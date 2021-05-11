class Solution
{
public:
    int minOperations(vector<string> &logs)
    {
        int level = 0;
        for (auto &s : logs)
        {
            if (s == "../")
            {
                if (level != 0)
                    --level;
            }
            else if (s != "./")
            {
                level++;
            }
        }

        return level;
    }
};