class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        int fz[102] = {};
        int max_val = INT_MIN;

        for (auto &i : nums)
        {
            max_val = max(max_val, i); //calculate max value in array
            fz[i > 100 ? 100 : i]++;
        }

        // ans can range between 0 and input.size()
        // there max ans = 100

        int curr = 0;

        if (max_val > 100)
            max_val = 100;

        for (int i = max_val; i >= 0; --i)
        {
            curr += fz[i];
            if (curr == i)
                return curr;
        }

        /*
            Complete snapshot of variable cur
            i  | cur
            --------
            0 |   5
            1 |   3
            2 |   3    
            3 |   3 -- found answer!! return 3
            4 |   2
            5 |   0
            
            bottom to up!
		*/
        return -1;
    }
};