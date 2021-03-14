class Solution
{
    vector<string> ans;
    void generate(string curr, int ones, int zeros, int n)
    {
        if (ones + zeros == n)
        {
            ans.push_back(curr);
            return;
        }
        if (zeros <= ones - 1)
        {
            string op1, op2;
            op1 = op2 = curr;
            op1.push_back('1');
            op2.push_back('0');
            generate(op1, ones + 1, zeros, n);
            generate(op2, ones, zeros + 1, n);
        }
        else
        {
            string op;
            op = curr;
            op.push_back('1');
            generate(op, ones + 1, zeros, n);
        }
    }

public:
    vector<string> NBitBinary(int N)
    {
        if (N == 0)
            return ans;
        string curr = "1";
        generate(curr, 1, 0, N);
        return ans;
    }
};
