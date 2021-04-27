/*

We need to complete the job before deadline and maximise profit.

Since we need to maximise profit, sort jobs in dec order of profit

Select a job, choose a slot < deadline, add profit [the slot should be as close to the deadline as possible]
              if no valid slot available, ignore job

*/

bool comp(Job a, Job b)
{
    return a.profit > b.profit;
}

class Solution
{
public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)
    {
        vector<bool> slot(n, false);

        // sort in decreasing order of profit
        sort(arr, arr + n, comp);

        int total_profit = 0, num_jobs = 0;

        for (int i = 0; i < n; ++i)
        {
            int profit = arr[i].profit, deadline = arr[i].dead;

            // find slot
            for (int j = min(deadline, n) - 1; j >= 0; --j)
            {

                // if slot is empty
                if (slot[j] == false)
                {
                    slot[j] = true;
                    total_profit += profit;
                    ++num_jobs;
                    break;
                }
            }
        }

        return {num_jobs, total_profit};
    }
};