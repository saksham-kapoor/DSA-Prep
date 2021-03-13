class Solution
{
public:
    void solve(int from, int to, int helper, int N, long long &count)
    {
        count++;
        if (N == 1)
        {
            cout << "move disk " << N << " from rod " << from << " to rod " << to << "\n";
            return;
        }
        solve(from, helper, to, N - 1, count);
        cout << "move disk " << N << " from rod " << from << " to rod " << to << "\n";
        solve(helper, to, from, N - 1, count);
    }

    long long toh(int N, int from, int to, int helper)
    {
        long long count = 0;
        solve(from, to, helper, N, count);
        return count;
    }
};