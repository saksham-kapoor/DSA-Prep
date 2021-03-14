void generate(string op, int n, int open, int tot_open, vector<string> &ans)
{
    if (op.size() == 2 * n)
    {
        ans.push_back(op);
        return;
    }

    if (tot_open == n)
    {
        op.push_back(')');
        generate(op, n, open - 1, tot_open, ans);
    }
    else
    {
        if (open == 0)
        {
            // open para
            op.push_back('(');
            generate(op, n, open + 1, tot_open + 1, ans);
        }
        else
        {
            // choice
            string op1, op2;
            op1 = op2 = op;
            op1.push_back('(');
            op2.push_back(')');

            generate(op1, n, open + 1, tot_open + 1, ans);
            generate(op2, n, open - 1, tot_open, ans);
        }
    }
}

vector<string> Solution::generateParenthesis(int A)
{
    vector<string> ans;
    string op = "", ip = "";
    generate(op, A, 0, 0, ans);
    return ans;
}
