class Solution
{

    void helper(string &s, int k, bool flag)
    {
        if (s.size() <= 2 || flag == false)
            return;

        flag = false;
        // make flag true if we delete anything

        int i = 0, j = 0, count = 0;
        char curr_el = 'A';
        while (j < s.size())
        {

            // calculation
            if (s[j] == curr_el)
                ++count;
            else
            {
                curr_el = s[j];
                count = 1;
            }

            if (j - i == k - 1)
            {
                if (count == k)
                {
                    // delete
                    flag = true;
                    s.erase(s.begin() + i, s.begin() + j + 1);
                    curr_el = 'A';
                    i = j + 1;
                    j = i;
                }
                else
                {
                    ++i;
                    ++j;
                }
            }
            else
            {
                ++j;
            }
        }

        helper(s, k, flag);
    }

public:
    string removeDuplicates(string s, int k)
    {
        helper(s, k, true);
        return s;
    }
};