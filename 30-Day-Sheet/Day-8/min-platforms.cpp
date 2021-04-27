/*

We are given arrival and departure times of trains.
At any given moment, total number of trains present = number of arrivals - number of departures

sort arrivals and departures in asc order
and calculate ans

*/

class Solution
{
public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        sort(arr, arr + n);
        sort(dep, dep + n);

        int trains_present = 0, ans = 0;

        int i, j;
        i = j = 0;

        while (i < n)
        {
            if (arr[i] <= dep[j])
            {
                ++i;
                ++trains_present;
                ans = max(ans, trains_present);
            }
            else
            {
                ++j;
                --trains_present;
            }
        }

        return ans;
    }
};