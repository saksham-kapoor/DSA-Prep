// Beautiful
// Look at the question from a different angle
// Generalize your solution for 1 condition, i.e sum2 > sum1, if not then swap vectors to make sum2 > sum1

class Solution
{
public:
    int minOperations(vector<int> &A, vector<int> &B)
    {
        int cnt[6] = {}, m = A.size(), n = B.size();
        if (n > 6 * m || m > 6 * n)
            return -1;

        int diff = accumulate(A.begin(), A.end(), 0) - accumulate(B.begin(), B.end(), 0);

        // we want B > A
        if (diff > 0)
            swap(A, B);

        diff = abs(diff);

        // how many operations of each type can we have
        for (auto &i : A)
            ++cnt[6 - i];
        for (auto &i : B)
            ++cnt[i - 1];

        int cnt_pointer = 5, op = 0;

        while (diff > 0)
        {
            op += min(cnt[cnt_pointer], (int)ceil((double)diff / cnt_pointer));
            diff -= cnt[cnt_pointer] * cnt_pointer;
            if (diff <= 0)
                return op;
            --cnt_pointer;
        }

        return 0; // unreachable
    }
};