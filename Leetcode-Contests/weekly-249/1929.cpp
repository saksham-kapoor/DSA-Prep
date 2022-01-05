class Solution
{
public:
    vector<int> getConcatenation(vector<int> &A)
    {
        // int n = A.size();
        // for(int i = 0; i < n; ++i)
        //     A.push_back(A[i]);
        // return A;

        A.insert(A.end(), A.begin(), A.end());
        return A;
    }
};