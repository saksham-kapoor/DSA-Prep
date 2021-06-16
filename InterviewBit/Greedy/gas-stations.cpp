int Solution::canCompleteCircuit(const vector<int> &A, const vector<int> &B)
{
    int total_gas = 0, tank = 0, start = 0;

    for (int i = 0; i < A.size(); ++i)
    {
        total_gas += A[i] - B[i];

        tank += A[i] - B[i];
        if (tank < 0)
        {
            start = i + 1;
            tank = 0;
        }
    }

    if (total_gas < 0)
        return -1;

    return start;
}
