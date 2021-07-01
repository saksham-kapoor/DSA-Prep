// elegance
// consider cases carefully

class Solution
{
public:
    string maximumTime(string time)
    {
        // XX:59
        time[3] = time[3] == '?' ? '5' : time[3];
        time[4] = time[4] == '?' ? '9' : time[4];

        // 23:59 || 19:59
        time[0] = time[0] == '?' ? (time[1] == '?' || time[1] <= '3' ? '2' : '1') : time[0];
        time[1] = time[1] == '?' ? (time[0] == '2' ? '3' : '9') : time[1];

        return time;
    }
};