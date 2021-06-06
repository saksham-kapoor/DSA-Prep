class Solution
{
public:
    string interpret(string command)
    {
        string res;
        int i = 0, n = command.size();

        while (i < n)
        {
            if (command[i] == '(')
            {
                if (command[i + 1] == ')')
                {
                    res.push_back('o');
                    i += 2;
                }
                else
                {
                    res += "al";
                    i += 4;
                }
            }
            else
            {
                res.push_back(command[i++]);
            }
        }

        return res;
    }
};