// COUNT SORTED VOWEL STRINGS
// https://www.careerbless.com/aptitude/qa/permutations_combinations_imp7.php
// grouping n identical objects into k boxes
// seperating n identical stars using k - 1 bars
// formula -> (n + k - 1) C (k - 1)
class Solution
{
    int nCr(int n, int r)
    {
        int ans = 1;
        r = min(r, n - r);

        for (int i = 1; i <= r; ++i)
        {
            ans *= n - i + 1;
            ans /= i;
        }

        return ans;
    }

public:
    int countVowelStrings(int n)
    {
        return nCr(n + 4, 4);
    }
};

// Good Concept Building Solution
// append a to front of all the strings that starts or after a which are aaa, aae, aai, aao, aau,aee, aei, aeo, aeu,aii, aio, aiu,aoo, aou,auu, after this, a 15 (5 + 4 + 3 + 2 + 1)
// append e to front of all the strings that starts or after e which are eee, eei, eeo, eeu,eii, eio, eiu,eoo, eou,euu, after this, e is 10 (4 + 3 + 2 + 1)
// append i to front of all the strings that starts or after i which are iii, iio, iiu,ioo, iou,iuu, after this, i is 6 (3 + 2 + 1)
// append o to front of all the strings that starts or after o which are ooo, oou,ouu after this, o is 3 (2 + 1)
// append u to front of all the strings that starts or after u which are uuu after this, u is 1 (1)
class Solution
{
public:
    int countVowelStrings(int n)
    {
        int a = 1, e = 1, i = 1, o = 1, u = 1;
        while (--n)
        {
            a = a + e + i + o + u;
            e = e + i + o + u;
            i = i + o + u;
            o = o + u;
            u = u;
        }
        return a + e + i + o + u;
    }
};
