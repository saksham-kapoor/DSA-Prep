/*

STANDARD GREEDY PROBLEM

How to arrive at locally optimum choice?
We need to select an object with max value and min weight and put it in knapsack
Therefore, sort in dec order of val/wt ratio

keep putting in knapsack till W != 0

*/

bool comp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}

class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comp);

        double total_value = 0;

        for (int i = 0; i < n && W > 0; ++i)
        {
            if (W - arr[i].weight >= 0)
            {
                W -= arr[i].weight;
                total_value += arr[i].value;
            }
            else
            {
                total_value += arr[i].value * ((double)W / arr[i].weight);
                W = 0;
            }
        }

        return total_value;
    }
};