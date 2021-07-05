#include <iostream>
#include <string>
using namespace std;

void compute_lps(string pattern, int lps[])
{
    int i = 0;
    lps[0] = 0;

    for (int j = 1; j < pattern.size(); ++j)
    {
        while (i > 0 && pattern[i] != pattern[j])
            i = lps[i - 1];

        if (pattern[i] = pattern[j])
            ++i;

        lps[j] = i;
    }
}

int kmp(string text, string pattern)
{
    int lps[10]; // pattern length, can be anything
    compute_lps(pattern, lps);

    int j = 0; // pattern pointer

    // main algorithm
    for (int i = 0; i < text.size(); ++i)
    {
        while (j > 0 && text[i] != pattern[j])
            j = lps[j - 1];

        if (text[i] == pattern[j])
            ++j;

        if (j == pattern.size())
            return i - j + 1;
    }

    return -1;
}

int main()
{
    string text = "bababaabababca";
    string pattern = "abababca";

    cout << kmp(text, pattern);
    return 0;
}