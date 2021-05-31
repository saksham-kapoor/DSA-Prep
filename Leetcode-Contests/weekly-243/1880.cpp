class Solution
{
public:
    bool isSumEqual(string fw, string sw, string tw)
    {
        for (auto &c : fw)
            c = c - 'a' + '0';
        for (auto &c : sw)
            c = c - 'a' + '0';
        for (auto &c : tw)
            c = c - 'a' + '0';

        return (stoi(fw) + stoi(sw)) == stoi(tw);
    }
};

// SHORTER VERSION
class Solution
{
public:
    bool isSumEqual(string fw, string sw, string tw)
    {
        auto calc = [](auto &s)
        {
            for (auto &c : s)
                c = c - 'a' + '0';
            return s;
        };

        return (stoi(calc(fw)) + stoi(calc(sw))) == stoi(calc(tw));
    }
};