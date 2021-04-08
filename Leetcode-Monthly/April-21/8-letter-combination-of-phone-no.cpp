class Solution
{
    vector<string> ops;
    void combinations(string ip, string op, int n)
    {
        if (ip.size() == 0)
            return;

        char d = ip[0];
        ip.erase(ip.begin());

        int d_num = (int)(d)-48;
        int skip_factor = 97 + ((d == '8') ? 19 : (d == '9') ? 22
                                                             : 3 * (d_num - 2));
        int letter_count = ((d == '7' || d == '9') ? 4 : 3);

        for (int i = 0; i < letter_count; i++)
        {
            string newOp = op;
            char op_d = skip_factor + i;
            newOp.push_back(op_d);
            if (newOp.size() == n)
                ops.push_back(newOp);
            combinations(ip, newOp, n);
        }
    }

public:
    vector<string> letterCombinations(string digits)
    {
        string op = "";
        combinations(digits, op, digits.size());
        return ops;
    }
};