// Very Intuitive method, fast too!
class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int d = 0;

        for (int i = 0; i < nums1.size(); ++i)
        {
            for (int j = i + d; j < nums2.size(); ++j)
            {
                if (nums2[j] >= nums1[i])
                    d = max(d, j - i);
                else
                    break;
            }
        }

        return d;
    }
};

// 2 pointer method!
class Solution
{
public:
    int maxDistance(vector<int> &nums1, vector<int> &nums2)
    {
        int d = 0, i = 0, j = 0;

        while (i < nums1.size() && j < nums2.size())
        {
            if (nums1[i] > nums2[j])
                ++i;
            else
            {
                d = max(d, j - i);
                ++j;
            }
        }

        return d;
    }
};