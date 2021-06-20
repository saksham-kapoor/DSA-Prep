class Solution
{
public:
    int numberOfRounds(string st, string ft)
    {
        int time1 = 60 * stoi(st.substr(0, 2)) + stoi(st.substr(3));
        int time2 = 60 * stoi(ft.substr(0, 2)) + stoi(ft.substr(3));

        time1 = 15 * ceil((double)time1 / 15);
        int diff = time2 - time1 + (time2 < time1 ? 24 * 60 : 0);
        return diff / 15;
    }
};