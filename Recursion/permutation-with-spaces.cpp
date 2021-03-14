class Solution
{
    vector<string> ans;

public:
    void put_spaces(string op, string ip)
    {
        if (ip.size() == 0)
        {
            ans.push_back(op);
            return;
        }

        string op1, op2;
        op1 = op2 = op;
        op1.push_back(' ');
        op1.push_back(ip[0]);
        op2.push_back(ip[0]);
        ip.erase(ip.begin());

        put_spaces(op1, ip);
        put_spaces(op2, ip);
    }

    vector<string> permutation(string S)
    {
        if (S.size() == 0)
            return ans;
        string op;
        op.push_back(S[0]);
        S.erase(S.begin());
        put_spaces(op, S);
        return ans;
    }
};