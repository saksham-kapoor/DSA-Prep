// THERE IS ALWAYS AN ELEGANT WAY TO WRITE CODE

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