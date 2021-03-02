#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<long long> v, long long n, long long x)
    {
        long long s = 0, e = n - 1, m, res = -1;
        while (s <= e)
        {
            m = s + (e - s) / 2;
            if (x == v[m])
                return m;
            else if (x < v[m])
                e = m - 1;
            else
            {
                res = m;
                s = m + 1;
            }
        }
        return res;
    }
};
