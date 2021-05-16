// Perfect Solution
// extremely fast

class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size();    // rows
        int n = box[0].size(); // cols

        // now num(rows) becomes num(cols) for new matrix
        // and vice versa

        vector<vector<char>> res(n, vector<char>(m, '.'));

        for (int i = 0; i < m; ++i)
        {

            int w = n - 1; // write pointer

            for (int j = n - 1; j >= 0; --j)
            {

                if (box[i][j] == '.')
                    continue;

                if (box[i][j] == '#')
                {
                    res[w][m - i - 1] = '#';
                    w--; // shoft write pointer to previous location
                }
                else
                {
                    res[j][m - i - 1] = '*'; // place it as it is
                    w = j - 1;               // decrease write pointer to go before obstacle
                }
            }
        }

        return res;
    }
};

// Okayish Solution!
// Uses a lot of unnecesarry space
// but works :)
class Solution
{
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box)
    {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> res(n, vector<char>(m, '.'));

        vector<array<int, 502>> cnt(m, array<int, 502>{});

        for (int i = 0; i < m; ++i)
        {
            int k = 0;
            for (int j = 0; j < n; ++j)
            {
                if (box[i][j] == '#')
                {
                    cnt[i][k]++;
                    continue;
                }
                if (box[i][j] == '*')
                {
                    k++;
                    cnt[i][501]++;
                }

                res[j][i] = box[i][j];
            }
        }

        for (int i = 0; i < n; ++i)
        {
            reverse(res[i].begin(), res[i].end());
        }

        reverse(cnt.begin(), cnt.end());

        for (int j = 0; j < m; ++j)
        {
            int num = cnt[j][501];
            for (int i = n - 1; i >= 0; --i)
            {
                if (res[i][j] == '*')
                    num--;
                else if (res[i][j] == '.')
                {
                    if (cnt[j][num] != 0)
                    {
                        res[i][j] = '#';
                        --cnt[j][num];
                    }
                }
            }
        }

        return res;
    }
};
