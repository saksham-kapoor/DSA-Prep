class Solution
{
public:
    bool containsPattern(vector<int> &arr, int m, int k)
    {
        if (m * k > arr.size())
            return false;

        int p = 0;
        for (int i = 0; i + m < arr.size(); i++)
        {
            if (arr[i] == arr[i + m])
                p++;
            else
                p = 0;

            if (p + m == m * k)
                return true;
        }

        return false;
    }
};
