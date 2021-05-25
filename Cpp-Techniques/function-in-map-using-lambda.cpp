class Solution
{
public:
    int evalRPN(vector<string> &t)
    {
        unordered_map<string, function<int(int &, int &)>> mp = {
            {"+", [](int &a, int &b) { return a + b; }},
            {"-", [](int &a, int &b) { return a - b; }},
            {"*", [](int &a, int &b) { return a * b; }},
            {"/", [](int &a, int &b) { return a / b; }}};

        stack<int> st;

        for (auto &s : t)
        {
            const auto &op = mp.find(s);

            if (op == mp.end())
                st.push(stoi(s));
            else
            {
                int a = st.top();
                st.pop();
                int b = st.top();
                st.pop();
                st.push((*op).second(b, a));
            }
        }

        return st.top();
    }
};