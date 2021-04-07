class Solution
{
    bool isVowel(char c)
    {
        c = tolower(c);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }

public:
    bool halvesAreAlike(string s)
    {
        int n = s.size();
        if (n & 1)
            return false;
        int i = 0, j = n - 1, l = 0;
        while (i < j)
        {
            if (isVowel(s[i]))
                l++;
            if (isVowel(s[j]))
                l--;
            i++;
            j--;
        }
        if (l == 0)
            return true;
        return false;
    }
};