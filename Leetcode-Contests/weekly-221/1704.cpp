class Solution
{
    bool vowel(char &i)
    {
        i |= ' '; // uppercase letters to lowercase
        return i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u';
    }

    int count(string &s, int i, int j)
    {
        int c = 0;
        while (i <= j)
            if (vowel(s[i++]) == true)
                ++c;
        return c;
    }

public:
    bool halvesAreAlike(string s)
    {
        return count(s, 0, s.size() / 2 - 1) == count(s, s.size() / 2, s.size() - 1);
    }
};