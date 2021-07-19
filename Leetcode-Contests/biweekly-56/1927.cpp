// Visualize the question
// Nothing is too difficult
// Its just about looking at the question with the right mindset

class Solution
{
public:
    bool sumGame(string s)
    {
        int n = s.size(), operations = 0, difference = 0;

        for (int i = 0; i < n / 2; ++i)
            if (s[i] != '?')
                difference += s[i] - '0';
            else
                ++operations;

        for (int i = n / 2; i < n; ++i)
            if (s[i] != '?')
                difference -= s[i] - '0';
            else
                --operations;

        // diff = left_sum - right_sum
        // operations = left_op - right_op

        if (operations >= 0 && difference > 0 || operations <= 0 && difference < 0 || abs(operations) % 2)
            return true; // alice wins

        operations = abs(operations);
        difference = abs(difference);

        if (difference == 9 * operations / 2)
            return false; // bob wins

        return true;
    }
};