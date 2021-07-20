class Solution
{
public:
    int canBeTypedWords(string text, string brokenLetters)
    {
        int broken = 0, curr = 0, res = 0;

        for (auto &i : brokenLetters)
            broken |= (1 << (i - 'a'));

        for (int i = 0; i <= text.size(); ++i)
        {
            if (i == text.size() || text[i] == ' ')
            {
                if ((broken & curr) == 0)
                    ++res;

                curr = 0;
            }
            else
                curr |= (1 << (text[i] - 'a'));
        }

        return res;
    }
};