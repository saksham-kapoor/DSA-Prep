class Solution
{
public:
    vector<int> frequencySort(vector<int> &A)
    {
        int n = A.size();
        unordered_map<int, int> fz;

        for (auto &i : A)
        {
            fz[i]++;
        }

        // "[&]" this '&' or capture-default is required
        // A default capture (also called a capture-default) captures all variables that are mentioned in the lambda.
        // Variables not mentioned in the lambda are not captured if a default capture is used.
        // To capture all used variables by value, use a capture value of =
        // To capture all used variables by reference, use a capture value of &

        sort(A.begin(), A.end(), [&](int &a, int &b) {
            if (fz[a] == fz[b])
                return a > b;
            return fz[a] < fz[b];
        });

        return A;
    }
};