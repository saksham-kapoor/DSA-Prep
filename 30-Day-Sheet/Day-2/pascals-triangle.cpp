/*
    Self Explanatory
    Just do a dry run for numRows = 5 and you will get the concept
*/

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;

        for (int i = 0; i < numRows; ++i)
        {
            vector<int> t(i + 1, 1);
            for (int j = 1; j < i; ++j)
                t[j] = ans.back()[j - 1] + ans.back()[j];
            ans.push_back(t);
        }

        return ans;
    }
};