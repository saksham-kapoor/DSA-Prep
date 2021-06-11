// THERE IS ALWAYS AN ELEGANT WAY TO WRITE CODE

// BEAUTIFUL WAY
class Solution
{
public:
    string reformatNumber(string s)
    {
        string res;

        for (int i = 0; i < s.size(); ++i)
        {
            if (!isdigit(s[i]))
                continue;

            res.push_back(s[i]);
            if (res.size() % 4 == 3)
                res.push_back('-');
        }

        // invalid cases
        // 123-1 ----> case 1
        // 123-123- ----> case 2

        // case 2
        if (res.back() == '-')
            res.pop_back();

        // case 1
        if (res.size() > 1 && res[res.size() - 2] == '-')
            swap(res[res.size() - 3], res[res.size() - 2]);

        return res;
    }
};

// OKAYISH WAY
class Solution
{
public:
    string reformatNumber(string s)
    {
        queue<char> q;
        for (auto &i : s)
            if (isdigit(i))
                q.push(i);

        string res;

        while (q.size() > 4)
        {
            res.push_back(q.front());
            q.pop();
            res.push_back(q.front());
            q.pop();
            res.push_back(q.front());
            q.pop();
            res.push_back('-');
        }

        if (q.size() == 4)
        {
            res.push_back(q.front());
            q.pop();
            res.push_back(q.front());
            q.pop();
            res.push_back('-');
        }

        while (q.size())
            res.push_back(q.front()), q.pop();

        return res;
    }
};