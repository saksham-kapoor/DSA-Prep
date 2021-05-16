class Solution
{
public:
    string sortSentence(string s)
    {
        vector<string> words(9);
        string ans;
        string wd;

        for (int i = 0; i < (int)s.size(); ++i)
        {
            if ((int)s[i] - '0' >= 1 && (int)s[i] - '0' <= 9)
            {
                words[s[i] - '0' - 1] = wd;
                wd.clear();
                ++i;
            }
            else
            {
                wd.push_back(s[i]);
            }
        }

        for (int i = 0; i < 9; ++i)
        {
            if (words[i].size() == 0)
                break;
            ans += words[i];
            ans += " ";
        }

        ans.pop_back();
        return ans;
    }
};