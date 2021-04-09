unordered_map<char, int> fz;

bool comp(char a, char b)
{
    return fz[a] < fz[b];
}

class Solution
{
public:
    bool isAlienSorted(vector<string> &words, string order)
    {
        for (int i = 0; i < order.size(); i++)
            fz[order[i]] = i;

        for (int i = 0; i < words.size() - 1; i++)
        {
            string s1 = words[i], s2 = words[i + 1];
            if (s1 == s2)
                continue;
            if (!lexicographical_compare(s1.begin(), s1.begin() + s1.size(), s2.begin(), s2.begin() + s2.size(), comp))
                return false;
        }

        return true;
    }
};