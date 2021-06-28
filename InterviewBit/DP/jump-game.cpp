// BFS SOLUTION

int Solution::canJump(vector<int> &A)
{
    int max_explored = 0;
    queue<int> q;
    q.push(0);

    while (q.size())
    {
        int idx = q.front();
        q.pop();

        if (idx == A.size() - 1) // reached the end
            return 1;

        int can_jump = A[idx];
        for (int i = max(max_explored, idx + 1); i <= min((int)A.size() - 1, idx + can_jump); ++i)
            q.push(i);

        max_explored = max(max_explored, idx + can_jump);
    }

    return 0;
}
