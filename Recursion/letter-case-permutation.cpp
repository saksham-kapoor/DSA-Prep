class Solution
{
    vector<string> ans;
    void perm(string ip, string op)
    {
        if (ip.size() == 0)
        {
            ans.push_back(op);
            return;
        }

        if (ip[0] >= 48 && ip[0] <= 57)
        {
            op.push_back(ip[0]);
            ip.erase(ip.begin());
            perm(ip, op);
        }
        else
        {
            string op1, op2;
            op1 = op2 = op;
            op1.push_back(ip[0]);
            op2.push_back(ip[0] - 32);
            ip.erase(ip.begin());

            perm(ip, op1);
            perm(ip, op2);
        }
    }

public:
    vector<string> letterCasePermutation(string S)
    {
        string op = "";
        transform(S.begin(), S.end(), S.begin(), ::tolower);
        perm(S, op);
        return ans;
    }
};