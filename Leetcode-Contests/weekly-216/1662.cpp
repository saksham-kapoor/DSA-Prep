// Method 1
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string w1 = "", w2 = "";
        for (auto &s : word1)
            w1 += s;
        for (auto &s : word2)
            w2 += s;
        return w1 == w2;
    }
};

// Method 2 - STL Version of method 1
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2)
    {
        string s = "";
        return accumulate(word1.begin(), word1.end(), s) == accumulate(word2.begin(), word2.end(), s);
    }
};

// Method 3 - INTERVIEW WORTHY METHOD
class Solution
{
public:
    bool arrayStringsAreEqual(vector<string> &w1, vector<string> &w2)
    {
        int i = 0, j = 0, arr_i = 0, arr_j = 0;
        int n = w1.size(), m = w2.size();

        while (arr_i < n && arr_j < m)
        {
            if (w1[arr_i][i] != w2[arr_j][j])
                return false;

            ++i;
            ++j;

            if (i == w1[arr_i].size())
            {
                ++arr_i;
                i = 0;
            }

            if (j == w2[arr_j].size())
            {
                ++arr_j;
                j = 0;
            }
        }

        if (arr_i != n || arr_j != m)
            return false;

        return true;
    }
};
