class Solution
{
public:
    int kthGrammar(int N, int K)
    {
        // Base Conditions
        if (N == 1 && K == 1)
            return 0;

        // Hypothesis
        int ans = (K % 2 == 0) ? kthGrammar(N - 1, K / 2) : kthGrammar(N - 1, (K + 1) / 2);

        // Induction
        if (K % 2 != 0)
            return ans;
        return ans ? 0 : 1;
    }
};