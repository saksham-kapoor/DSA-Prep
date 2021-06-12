// SIMPLE STRAIGHT-FORWARD SOLUTION
class Solution
{
public:
    int countStudents(vector<int> &students, vector<int> &sandwiches)
    {
        int num[2] = {};

        for (auto &i : students)
            ++num[i];

        for (auto &i : sandwiches)
        {
            if (num[i] == 0)
                break;
            --num[i];
        }

        return num[0] + num[1];
    }
};

// MULTISET SOLUTION
// OVERKILL
class Solution
{
public:
    int countStudents(vector<int> &stu, vector<int> &sand)
    {
        int n = stu.size();
        multiset<int> st(stu.begin(), stu.end());

        for (int i = 0; i < sand.size(); ++i)
        {
            auto it = st.find(sand[i]);
            if (it == st.end())
                return n - i;
            else
                st.erase(it);
        }

        return 0;
    }
};