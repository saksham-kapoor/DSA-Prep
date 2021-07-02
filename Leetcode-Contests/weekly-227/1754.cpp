// Manual String Compare
// Extremely Fast
class Solution
{
public:
    string largestMerge(string A, string B)
    {
        string res;
        int i = 0, j = 0, m = A.size(), n = B.size();

        while (i < m && j < n)
        {
            if (A[i] > B[j])
                res += A[i++];
            else if (A[i] < B[j])
                res += B[j++];
            else
            {
                int ii = i, jj = j;
                while (ii < m && jj < n && A[ii] == B[jj])
                    ++ii, ++jj;

                if (ii == m)
                    res += B[j++];
                else if (jj == n)
                    res += A[i++];
                else if (A[ii] > B[jj])
                    res += A[i++];
                else
                    res += B[j++];
            }
        }

        res += A.substr(i);
        res += B.substr(j);
        return res;
    }
};

// Priority Queue Method
// Keep concatenating lexigraphically largest string
// O(L.Log(L).L)

class Solution
{
public:
    string largestMerge(string A, string B)
    {
        priority_queue<string> pq;
        pq.push(A);
        pq.push(B);

        string res((int)A.size() + (int)B.size(), ' ');
        int k = 0;

        while (pq.size())
        {
            string s = pq.top();
            pq.pop();
            res[k++] = s[0];
            if (s.size() > 1)
                pq.push(s.substr(1));
        }

        return res;
    }
};