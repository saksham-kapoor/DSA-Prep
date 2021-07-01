// Fastest Method
class Solution
{
public:
    int kthLargestValue(vector<vector<int>> &mat, int k)
    {
        int m = mat.size(), n = mat[0].size(), idx = 0;
        vector<int> temp(m * n, 0);

        temp[idx++] = mat[0][0];

        for (int i = 1; i < n; ++i)
            mat[0][i] ^= mat[0][i - 1], temp[idx++] = mat[0][i];

        for (int i = 1; i < m; ++i)
        {
            mat[i][0] ^= mat[i - 1][0];
            temp[idx++] = mat[i][0];

            for (int j = 1; j < n; ++j)
            {
                mat[i][j] ^= mat[i - 1][j] ^ mat[i][j - 1] ^ mat[i - 1][j - 1];
                temp[idx++] = mat[i][j];
            }
        }

        nth_element(temp.begin(), temp.begin() + k - 1, temp.end(), greater<int>());
        return temp[k - 1];
    }
};

// Priority_queue method -> O(mnlog(mn))
// high complexity
// since, we just need the kth largest element, we can put all values in a vector and can get answer using nth element stl function
// so then complexity would be O(mn + mn) = O(mn) [HUGE IMPROVEMENT]
class Solution
{
public:
    int kthLargestValue(vector<vector<int>> &mat, int k)
    {
        int m = mat.size(), n = mat[0].size();
        priority_queue<int> pq;
        pq.push(mat[0][0]);

        for (int i = 1; i < n; ++i)
            mat[0][i] ^= mat[0][i - 1], pq.push(mat[0][i]);

        for (int i = 1; i < m; ++i)
        {
            mat[i][0] ^= mat[i - 1][0];
            pq.push(mat[i][0]);

            for (int j = 1; j < n; ++j)
            {
                mat[i][j] ^= mat[i - 1][j] ^ mat[i][j - 1] ^ mat[i - 1][j - 1];
                pq.push(mat[i][j]);
            }
        }

        while (--k > 0)
            pq.pop();
        return pq.top();
    }
};