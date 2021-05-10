class Solution
{
public:
    string reorderSpaces(string t)
    {
        int n_spaces = 0;
        vector<string> words;
        string word;

        for (int i = 0; i < t.size(); ++i)
        {
            if (t[i] != ' ')
            {
                word.push_back(t[i]);
            }
            else if (t[i] == ' ')
            {
                if (word.size())
                    words.push_back(word);
                word.clear();
                n_spaces++;
            }
        }

        if (word.size())
            words.push_back(word);

        int n_words = words.size();

        if (n_words == 1)
        {
            return words[0] + string(n_spaces, ' ');
        }

        int between, extra;

        between = n_spaces / (n_words - 1);
        extra = n_spaces % (n_words - 1);

        string ans;

        for (int i = 0; i < words.size(); i++)
        {
            ans += words[i];

            if (i == words.size() - 1)
            {
                ans += string(extra, ' ');
                break;
            }

            ans += string(between, ' ');
        }

        return ans;
    }
};