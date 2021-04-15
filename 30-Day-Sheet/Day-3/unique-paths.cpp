/*

Method 1 -> Simple Math Combination Solution
            first we calculate available left and right moves
            
            a_left_moves = P
            a_right_moves = Q
            
            total_moves = P+Q
            Each unique path will have a unique combination of left and right moves
            Ans = (P+Q)C(P) or (P+Q)C(Q)
            
            Time: O(m) or O(n) solution [whichever is minimum]
            Space: O(1)

Method 2 -> DP Solution

            t[i][j] stores the number of unique paths it takes to reach i, j
            so we have to find, t[m-1][n-1]
            
            general formula being
            t[i][j] = t[i-1][j] + t[i][j-1]
            as we can arrive at a point i,j by top or left

            return t[m-1][n-1]

*/

// O(n^2) space and time -> Dp solution
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> t(m, vector<int>(n, 1));

        // dp solution
        for (int i = 1; i < m; ++i)
        {
            for (int j = 1; j < n; ++j)
            {
                t[i][j] = t[i - 1][j] + t[i][j - 1];
            }
        }

        return t[m - 1][n - 1];
    }
};

// O(1) space Math Solution
class Solution
{
    int _combination(int a, int b)
    {
        long long num = 1;
        for (int i = 0; i < b; ++i)
        {
            num *= a;
            num /= (i + 1);
            --a;
        }

        return num;
    }

public:
    int uniquePaths(int m, int n)
    {
        int avail_down_moves = m - 1, avail_right_moves = n - 1;
        int total_avail_moves = avail_down_moves + avail_right_moves;

        return _combination(total_avail_moves, min(avail_down_moves, avail_right_moves));
    }
};