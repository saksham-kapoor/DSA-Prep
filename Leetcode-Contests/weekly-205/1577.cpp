/*
IF YOU HAVE TO PERFORM SIMILAR OPERATIONS AGAIN AND AGAIN, SIMPLY MAKE A FUNCTION!
*/

// Method 1
// Store all squares in a map
// then in n^2 calculate product of all duplets in other array and check if present in map
// O(n^2)
class Solution
{
    int count(vector<int> &A, vector<int> &B)
    {
        int count = 0;

        unordered_map<long, int> m;
        for (int i = 0; i < A.size(); ++i)
            m[(long)A[i] * A[i]]++;

        for (int i = 0; i < B.size() - 1; ++i)
        {
            for (int j = i + 1; j < B.size(); ++j)
            {
                auto it = m.find((long)B[i] * B[j]);
                if (it != m.end())
                    count += it->second;
            }
        }

        return count;
    }

public:
    int numTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        return count(nums1, nums2) + count(nums2, nums1);
    }
};

// Method 2 => BETTER METHOD
// O(MN)
class Solution
{
    int count(vector<int> &A, vector<int> &B)
    {
        int count = 0;

        unordered_map<int, int> m;
        for (int i = 0; i < B.size(); ++i)
            m[B[i]]++;

        for (int i = 0; i < A.size(); ++i)
        {
            long target = (long)A[i] * A[i];

            for (auto &[b, cnt] : m)
            {
                if (target % b != 0 || m.find(target / b) == m.end())
                    continue;
                if (target / b == b)
                    count += cnt * (cnt - 1);
                else
                    count += cnt * m[target / b];
            }
        }

        return count / 2; // we count each pair twice, therefore we divide the final count by 2
    }

public:
    int numTriplets(vector<int> &nums1, vector<int> &nums2)
    {
        return count(nums1, nums2) + count(nums2, nums1);
    }
};