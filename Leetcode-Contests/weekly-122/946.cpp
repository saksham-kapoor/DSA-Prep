// push one by one, pop as and when you can

class Solution
{
public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped)
    {
        deque<int> stack_simulator;
        int popped_tracker = 0;

        for (int i = 0; i < pushed.size(); ++i)
        {
            stack_simulator.push_back(pushed[i]);

            while (stack_simulator.size() && stack_simulator.back() == popped[popped_tracker])
                stack_simulator.pop_back(), ++popped_tracker;
        }

        return stack_simulator.size() == 0;
    }
};