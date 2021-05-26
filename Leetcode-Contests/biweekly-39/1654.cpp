// BFS SOLUTION!
class Solution
{
public:
    int minimumJumps(vector<int> &forbidden, int a, int b, int x)
    {
        int steps = 0, furthest = 2000 + a + b;
        queue<pair<int, int>> q;
        set<int> st;

        for (auto &f : forbidden)
        {
            st.insert(f);
        }

        q.emplace(1, 0); // direction, position [1 = forward, 0 = backward]
        st.insert(0);

        while (q.size())
        {
            int sz = q.size();
            while (sz--)
            {
                int dir = q.front().first, pos = q.front().second;
                q.pop();

                if (pos == x)
                    return steps;

                // jump forward
                if (pos + a <= furthest && st.find(pos + a) == st.end())
                {
                    st.insert(pos + a);
                    // insert position in set only when you visit that pos with a forward jump
                    // cuz only then you can explore that position fully
                    q.emplace(1, pos + a);
                }

                // jump backward
                if (dir && pos - b > 0 && st.find(pos - b) == st.end())
                {
                    q.emplace(0, pos - b);
                }
            }
            steps++;
        }

        return -1;
    }
};