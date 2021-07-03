// Find Substring using str.find(part)
// if found, take remaining part
class Solution
{
public:
    string removeOccurrences(string s, string part)
    {
        auto it = s.find(part);
        while (it != string::npos)
        {
            s = s.substr(0, it) + s.substr(it + part.size());
            it = s.find(part);
        }
        return s;
    }
};