class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        int n = arr.size();

        nth_element(arr.begin(), arr.begin() + n / 20, arr.end());
        nth_element(arr.begin() + n / 20, arr.begin() + n - n / 20, arr.end());

        double sum = accumulate(arr.begin() + n / 20, arr.end() - n / 20, 0);

        return sum / (n - n / 10);
    }
};

class Solution
{
public:
    double trimMean(vector<int> &arr)
    {
        int n = arr.size();

        sort(arr.begin(), arr.end());

        double sum = accumulate(arr.begin() + n / 20, arr.end() - n / 20, 0);

        return sum / (n - n / 10);
    }
};